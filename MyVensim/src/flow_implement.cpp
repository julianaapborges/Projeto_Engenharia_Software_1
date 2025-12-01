#include "flow_implement.hpp"

// Implementação da classe Flow_implement.
// Um Flow_implement representa uma taxa de transferência entre dois objetos System
// (uma fonte e um destino). A classe fornece acesso para definir/obter
// essas referências e deve ser herdada por implementações concretas que
// definem o método `equation()` (a taxa calculada a cada passo da simulação).

Flow_implement::Flow_implement() {
  // Construtor padrão: inicializa ponteiros como nulos
  m_source = nullptr;
  m_target = nullptr;
}

Flow_implement::Flow_implement(System *source, System *target) {
  // Construtor com inicialização de fonte e destino
  this->m_source = source;
  this->m_target = target;
}

// Destrutor virtual (implementação vazia). Subclasses podem sobrepor se necessário.
Flow_implement::~Flow_implement() {}

// Construtor de cópia: copia apenas as referências de source/target
Flow_implement::Flow_implement(const Flow_implement &flow) {
  this->m_source = flow.m_source;
  this->m_target = flow.m_target;
}

// Operador de atribuição: copia referências de source/target, protegendo self-assignment
Flow_implement &Flow_implement::operator=(const Flow_implement &flow) {
  if (this != &flow) {
    this->m_source = flow.m_source;
    this->m_target = flow.m_target;
  }
  return *this;
}

// Define a System de origem (fonte) deste fluxo
void Flow_implement::setSource(System *source) { m_source = source; }

// Define a System de destino (alvo) deste fluxo
void Flow_implement::setTarget(System *target) { m_target = target; }

// Retorna a System de origem (pode ser nullptr)
System *Flow_implement::getSource() const { return m_source; }

// Retorna a System de destino (pode ser nullptr)
System *Flow_implement::getTarget() const { return m_target; }