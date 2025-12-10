#include "model_impl.hpp"
#include "system.hpp"
#include "flow.hpp"

// Implementação da classe Model_impl.
// O Model_impl mantém coleções de `System` e `Flow` e executa a simulação
// ao longo do tempo. A integração é feita de forma explícita por passos:
// 1) calcula todas as taxas (chamando `equation()` em cada Flow) e armazena
//    os resultados em um vetor auxiliar;
// 2) aplica essas taxas simultaneamente aos Systems, subtraindo da fonte
//    e adicionando ao destino. Esse procedimento evita atualizações parciais
//    dentro do mesmo passo de tempo.

Model_impl::Model_impl() : m_time(0) {}

Model_impl::~Model_impl() {
    // Limpa as coleções de Systems e Flows
    // Percorre o vetor de fluxos e deleta um por um
    for (auto flow : m_flows) {
        delete flow;
    }
    m_flows.clear();

    // Percorre o vetor de sistemas e deleta um por um
    for (auto system : m_systems) {
        delete system;
    }
    m_systems.clear();
}

// Construtor de cópia: copia estado e coleções (shallow copy dos ponteiros)
Model_impl::Model_impl(const Model_impl &other) {
  this->m_time = other.m_time;
  this->m_systems = other.m_systems;
  this->m_flows = other.m_flows;
}

// Operador de atribuição: copia estado e coleções (shallow copy)
Model_impl &Model_impl::operator=(const Model_impl &other) {
  if (this != &other) {
    this->m_time = other.m_time;
    this->m_systems = other.m_systems;
    this->m_flows = other.m_flows;
  }
  return *this;
}

// Adiciona um System ao Modelo (não faz cópia, apenas armazena o ponteiro)
void Model_impl::add(System *system) { m_systems.push_back(system); }

// Adiciona um Flow ao Modelo (ponteiro armazenado)
void Model_impl::add(Flow *flow) { m_flows.push_back(flow); }

// Executa a simulação do tempo `start` até `final` com passo `increment`.
// Observações importantes:
// - O passo de tempo é aplicado como incremento de `m_time` (tipo inteiro em prática)
// - A estratégia usada calcula primeiro todas as taxas de fluxo para o passo
//   e só então atualiza os Systems, garantindo consistência entre fluxos
//   que dependem uns dos outros dentro do mesmo passo.
// - O método utiliza `double` para valores e soma/subtrai diretamente os
//   valores calculados (comportamento equivalente a um integrador explícito simples).
void Model_impl::run(double start, double final, int increment) {
    // Vetor auxiliar que guarda o valor calculado por cada fluxo no passo atual
    std::vector<double> auxiliar(m_flows.size());

    // Loop principal de tempo
    for (m_time = start; m_time < final; m_time += increment) {
        // 1) calcula a taxa (equation) de cada fluxo e armazena em auxiliar
        for(unsigned int i=0; i < m_flows.size(); i++){
            auxiliar[i] = m_flows[i]->equation();
        }

        // 2) aplica todas as taxas: remove da fonte e adiciona ao destino
        for (unsigned int i = 0; i < m_flows.size(); i++) {
            System *source = m_flows[i]->getSource();
            if (source != nullptr) {
                source->setValue(source->getValue() - auxiliar[i]);
            }

            System *target = m_flows[i]->getTarget();
            if (target != nullptr) {
                target->setValue(target->getValue() + auxiliar[i]);
            }
        }
    }
}

/** @brief Implementação dos Iteradores de System */
Model_impl::systemIterator Model_impl::beginSystems() {
    return m_systems.begin();
}

Model_impl::systemIterator Model_impl::endSystems() {
    return m_systems.end();
}

/** @brief Implementação dos Iteradores de Flow */
Model_impl::flowIterator Model_impl::beginFlows() {
    return m_flows.begin();
}

Model_impl::flowIterator Model_impl::endFlows() {
    return m_flows.end();
}