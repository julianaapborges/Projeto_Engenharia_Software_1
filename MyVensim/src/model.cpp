#include "model.hpp"

// Implementação da classe Model.
// O Model mantém coleções de `System` e `Flow` e executa a simulação
// ao longo do tempo. A integração é feita de forma explícita por passos:
// 1) calcula todas as taxas (chamando `equation()` em cada Flow) e armazena
//    os resultados em um vetor auxiliar;
// 2) aplica essas taxas simultaneamente aos Systems, subtraindo da fonte
//    e adicionando ao destino. Esse procedimento evita atualizações parciais
//    dentro do mesmo passo de tempo.

Model::Model() : m_time(0) {}

Model::~Model() {
  for(unsigned int i =0; i < m_systems.size(); i++){ 
    delete m_systems[i];
  }
  for(unsigned int i =0; i < m_flows.size(); i++){ 
    delete m_flows[i];
  }
}

// Construtor de cópia: copia estado e coleções (shallow copy dos ponteiros)
Model::Model(const Model &other) {
  this->m_time = other.m_time;
  this->m_systems = other.m_systems;
  this->m_flows = other.m_flows;
}

// Operador de atribuição: copia estado e coleções (shallow copy)
Model &Model::operator=(const Model &other) {
  if (this != &other) {
    this->m_time = other.m_time;
    this->m_systems = other.m_systems;
    this->m_flows = other.m_flows;
  }
  return *this;
}

// Adiciona um System ao modelo (não faz cópia, apenas armazena o ponteiro)
void Model::add(System *system) { m_systems.push_back(system); }

// Adiciona um Flow ao modelo (ponteiro armazenado)
void Model::add(Flow *flow) { m_flows.push_back(flow); }

// Executa a simulação do tempo `start` até `final` com passo `increment`.
// Observações importantes:
// - O passo de tempo é aplicado como incremento de `m_time` (tipo inteiro em prática)
// - A estratégia usada calcula primeiro todas as taxas de fluxo para o passo
//   e só então atualiza os Systems, garantindo consistência entre fluxos
//   que dependem uns dos outros dentro do mesmo passo.
// - O método utiliza `double` para valores e soma/subtrai diretamente os
//   valores calculados (comportamento equivalente a um integrador explícito simples).
void Model::run(double start, double final, int increment) {
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
      // Subtrai o valor do fluxo da System fonte (se existir)
      System *source = m_flows[i]->getSource();
      if (source != nullptr) {
        source->setValue(source->getValue() - auxiliar[i]);
      }

      // Adiciona o valor do fluxo à System alvo (se existir)
      System *target = m_flows[i]->getTarget();
      if (target != nullptr) {
        target->setValue(target->getValue() + auxiliar[i]);
      }
    }
  }
}

/** @brief Implementação dos Iteradores de System */
Model::systemIterator Model::beginSystems() {
    return m_systems.begin();
}

Model::systemIterator Model::endSystems() {
    return m_systems.end();
}

/** @brief Implementação dos Iteradores de Flow */
Model::flowIterator Model::beginFlows() {
    return m_flows.begin();
}

Model::flowIterator Model::endFlows() {
    return m_flows.end();
}