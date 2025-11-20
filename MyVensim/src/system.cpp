#include "system.hpp"
#include <iostream>

// Implementação da classe System.
// Um System representa uma quantidade (por exemplo, população, estoque)
// que pode ser alterada por Fluxos (Flow). A classe fornece métodos simples
// para acessar e modificar o valor armazenado.

System::System() { m_value = 0; }

// Construtor que inicializa o valor do System
System::System(double value) { m_value = value; }

System::~System() {}

// Construtor de cópia: copia o valor armazenado
System::System(const System &system) { m_value = system.m_value; }

// Operador de atribuição: copia o valor, protegendo contra self-assignment
System &System::operator=(const System &system) {
  if (this != &system) {
    m_value = system.m_value;
  }
  return *this;
}

// Imprime o valor atual no stdout (útil para debug)
void System::print() { std::cout << m_value << std::endl; }

// Define o valor do System (substitui o valor atual)
void System::setValue(double value) { m_value = value; }

// Retorna o valor atual do System
double System::getValue() { return m_value; }

