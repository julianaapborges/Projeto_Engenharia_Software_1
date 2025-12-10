#include "unit_system.hpp"
#include "../../src/lib/system_impl.hpp" 
#include <iostream>
#include <cassert>
#include <cmath> 

// Variável auxiliar local
int unit_system_destructor_count = 0;

// Classe espiã local
class SystemDestructorSpy : public System_impl {
public:
    SystemDestructorSpy(double v) : System_impl(v) {}
    ~SystemDestructorSpy() {
        unit_system_destructor_count++;
    }
};

/** @brief Teste para o construtor da classe System */
void unit_System::unit_system_constructor() {
    System_impl s1;
    assert(s1.getValue() == 0.0);
    System_impl s2(10.0);
    assert(s2.getValue() == 10.0);
}

/** @brief Teste para o método setValue da classe System */
void unit_System::unit_system_setValue() {
    System_impl s;
    s.setValue(100.0);
    assert(s.m_value == 100.0);
}

/** @brief Teste para o método getValue da classe System */
void unit_System::unit_system_getValue() {
    System_impl s(10.0);
    assert(s.getValue() == 10.0);
}

/** @brief Teste para o construtor de cópia da classe System */
void unit_System::unit_system_copy_constructor() {
    System_impl s1(10.0);
    System_impl s2(s1);
    assert(s2.getValue() == s1.getValue());
}

/** @brief Teste para o operador de atribuição da classe System */
void unit_System::unit_system_assignmentOperator() {
    System_impl s1(10.0);
    System_impl s2;
    s2 = s1;
    assert(s2.getValue() == 10.0);
}

void unit_System::unit_system_destructor() {
    // Zera
    unit_system_destructor_count = 0;
    
    // Cria
    System *s = new SystemDestructorSpy(10.0);
    
    // Deleta
    delete s;
    
    // Verifica
    assert(unit_system_destructor_count == 1);
}

/** @brief Função para executar todos os testes unitários da classe System */
void unit_System::run_unit_tests_System() {
    unit_system_constructor();
    unit_system_setValue();
    unit_system_getValue();
    unit_system_copy_constructor();
    unit_system_assignmentOperator();
    unit_system_destructor();
}