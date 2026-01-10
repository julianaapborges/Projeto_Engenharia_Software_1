#include "flow_handle.hpp"
#include "flow_body.hpp"

// Implementação da classe Flow_impl.
// Um Flow_impl representa uma taxa de transferência entre dois objetos System
// (uma fonte e um destino). A classe fornece acesso para definir/obter
// essas referências e deve ser herdada por implementações concretas que
// definem o método `equation()` (a taxa calculada a cada passo da simulação).

// Flow_impl::Flow_impl() {
//   // Construtor padrão: inicializa ponteiros como nulos
//   m_source = nullptr;
//   m_target = nullptr;
// }

// Flow_impl::Flow_impl(System *source, System *target) {
//   // Construtor com inicialização de fonte e destino
//   this->m_source = source;
//   this->m_target = target;
// }

// // Destrutor virtual (implementação vazia). Subclasses podem sobrepor se necessário.
// Flow_impl::~Flow_impl() {}

// // Construtor de cópia: copia apenas as referências de source/target
// Flow_impl::Flow_impl(const Flow_impl &other) {
//   this->m_source = other.m_source;
//   this->m_target = other.m_target;
// }

// // Operador de atribuição: copia referências de source/target, protegendo self-assignment
// Flow_impl &Flow_impl::operator=(const Flow_impl &other) {
//   if (this != &other) {
//     this->m_source = other.m_source;
//     this->m_target = other.m_target;
//   }
//   return *this;
// }

// // Define a System de origem (fonte) deste fluxo
// void Flow_impl::setSource(System *source) { m_source = source; }

// // Define a System de destino (alvo) deste fluxo
// void Flow_impl::setTarget(System *target) { m_target = target; }

// // Retorna a System de origem (pode ser nullptr)
// System *Flow_impl::getSource() const { return m_source; }

// // Retorna a System de destino (pode ser nullptr)
// System *Flow_impl::getTarget() const { return m_target; }