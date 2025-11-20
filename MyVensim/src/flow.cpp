#include "flow.hpp"

// Implementação da classe Flow.
// Um Flow representa uma taxa de transferência entre dois objetos System
// (uma fonte e um destino). A classe fornece acesso para definir/obter
// essas referências e deve ser herdada por implementações concretas que
// definem o método `equation()` (a taxa calculada a cada passo da simulação).

Flow::Flow() {
  // Construtor padrão: inicializa ponteiros como nulos
  m_source = nullptr;
  m_target = nullptr;
}

Flow::Flow(System *source, System *target) {
  // Construtor com inicialização de fonte e destino
  m_source = source;
  m_target = target;
}

// Destrutor virtual (implementação vazia). Subclasses podem sobrepor se necessário.
Flow::~Flow() {}

// Construtor de cópia: copia apenas as referências de source/target
Flow::Flow(const Flow &flow) {
  m_source = flow.m_source;
  m_target = flow.m_target;
}

// Operador de atribuição: copia referências de source/target, protegendo self-assignment
Flow &Flow::operator=(const Flow &flow) {
  if (this != &flow) {
    m_source = flow.m_source;
    m_target = flow.m_target;
  }
  return *this;
}

// Define a System de origem (fonte) deste fluxo
void Flow::setSource(System *source) { m_source = source; }

// Define a System de destino (alvo) deste fluxo
void Flow::setTarget(System *target) { m_target = target; }

// Retorna a System de origem (pode ser nullptr)
System *Flow::getSource() { return m_source; }

// Retorna a System de destino (pode ser nullptr)
System *Flow::getTarget() { return m_target; }
