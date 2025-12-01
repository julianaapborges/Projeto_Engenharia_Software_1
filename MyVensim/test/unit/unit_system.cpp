#include "unit_system.hpp"
#include "../../src/system_implement.hpp" 
#include <iostream>
#include <cassert>
#include <cmath> 

// Teste para o construtor
void unit_System_constructor() {
    System_implement s1;
    assert(s1.getValue() == 0.0);
    System_implement s2(10.0);
    assert(s2.getValue() == 10.0);
}

// Teste para o método setValue
void unit_System_setValue() {
    System_implement s;
    s.setValue(100.0);
    assert(s.getValue() == 100.0);
}

// Teste para o método getValue
void unit_System_getValue() {
    System_implement s(10.0);
    assert(s.getValue() == 10.0);
}

// Teste para o construtor de cópia
void unit_System_copy_constructor() {
    System_implement s1(10.0);
    System_implement s2(s1);
    assert(s2.getValue() == s1.getValue());
}

// Teste para o operador de atribuição
void unit_System_assignmentOperator() {
    System_implement s1(10.0);
    System_implement s2;
    s2 = s1;
    assert(s2.getValue() == 10.0);
}

// Função para executar todos os testes unitários da classe System
void run_unit_tests_System() {
    unit_System_constructor();
    unit_System_setValue();
    unit_System_getValue();
    unit_System_copy_constructor();
    unit_System_assignmentOperator();
}