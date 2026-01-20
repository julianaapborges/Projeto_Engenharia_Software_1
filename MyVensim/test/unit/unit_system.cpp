#include "unit_system.hpp"
#include "../../src/lib/system_handle.hpp" 
#include "../../src/lib/system_body.hpp"
#include <iostream>
#include <cassert>
#include <cmath> 

// Variável auxiliar local
int unit_system_destructor_count = 0;

// Classe espiã local
/** Classe espiã para testar o destrutor de SystemHandle */
class SystemDestructorSpy : public SystemHandle {
public:
    SystemDestructorSpy(double v) : SystemHandle(v) {}
    ~SystemDestructorSpy() {
        unit_system_destructor_count++;
    }
};

/** @brief Teste para o construtor da classe System */
void unit_System::unit_system_constructor() {
    SystemHandle s1;
    assert(s1.pImpl_->m_value == 0.0);
    SystemHandle s2(10.0);
    assert(s2.pImpl_->m_value == 10.0);
}

/** @brief Teste para o método setValue da classe System */
void unit_System::unit_system_setValue() {
    SystemHandle s;
    s.setValue(100.0);
    assert(s.pImpl_->m_value == 100.0);
}

/** @brief Teste para o método getValue da classe System */
void unit_System::unit_system_getValue() {
    SystemHandle s(10.0);
    assert(s.pImpl_->m_value == 10.0);
}

/** @brief Teste para o construtor de cópia da classe System */
void unit_System::unit_system_copy_constructor() {
    SystemHandle s1(10.0);
    SystemHandle s2(s1);
    assert(s2.pImpl_->m_value == s1.pImpl_->m_value);
}

/** @brief Teste para o operador de atribuição da classe System */
void unit_System::unit_system_assignmentOperator() {
    SystemHandle s1(10.0);
    SystemHandle s2;
    s2 = s1;
    assert(s2.pImpl_->m_value == 10.0);
}

/** @brief Teste para o destrutor da classe System */
void unit_System::unit_system_destructor() {
    // Zera
    unit_system_destructor_count = 0;
    
    // Cria
    SystemHandle *s = new SystemDestructorSpy(10.0);
    
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