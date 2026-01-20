#include "unit_flow.hpp"
#include "../../src/lib/flow_handle.hpp"
#include "../../src/lib/flow_body.hpp"
#include "../../src/lib/system_handle.hpp"
#include "flow_mock.hpp"
#include <iostream>
#include <cassert>

// Variável auxiliar
int unit_flow_destructor_count = 0;

/** Classe espiã para testar o destrutor de FlowHandle */
// Herda de FlowHandle e incrementa uma variável global ao ser destruída
class FlowDestructorSpy : public FlowHandle {
public:
    // Construtor padrão chama o construtor de FlowHandle
    FlowDestructorSpy() : FlowHandle() {}
    // Destrutor incrementa o contador global para verificar se foi chamado
    ~FlowDestructorSpy() {
        unit_flow_destructor_count++;
    }
    // Implementação do método equation (necessário para classe concreta)
    double equation() { return 0; }
};

/** @brief Teste para o construtor da classe Flow */
void unit_Flow::unit_flow_constructor() {
    SystemHandle s1(100.0);
    SystemHandle s2(50.0);
    // Usamos FlowMock em vez de Flow
    FlowMock f(&s1, &s2); 
    
    assert(f.pImpl_->m_source == &s1);
    assert(f.pImpl_->m_target == &s2);
}

/** @brief Teste para o método setSource da classe Flow  */
void unit_Flow::unit_flow_setSource() {
    SystemHandle s1(100.0);
    FlowMock f;
    f.setSource(&s1);
    assert(f.pImpl_->m_source == &s1);
}

/** @brief Teste para o método setTarget da classe Flow  */
void unit_Flow::unit_flow_setTarget() {
    SystemHandle s2(50.0);
    FlowMock f;
    f.setTarget(&s2);
    assert(f.pImpl_->m_target == &s2);
}

/** @brief Teste para o método getSource da classe Flow  */
void unit_Flow::unit_flow_getSource() {
    SystemHandle s1(100.0);
    SystemHandle s2(50.0);
    FlowMock f(&s1, &s2);
    assert(f.pImpl_->m_source == &s1);
}

/** @brief Teste para o método getTarget da classe Flow  */
void unit_Flow::unit_flow_getTarget() {
    SystemHandle s1(100.0);
    SystemHandle s2(50.0);
    FlowMock f(&s1, &s2);
    assert(f.pImpl_->m_target == &s2);
}

/** @brief Teste para o construtor de cópia da classe Flow */
void unit_Flow::unit_flow_copy_constructor() {
    SystemHandle s1(100.0);
    SystemHandle s2(50.0);
    FlowMock f1(&s1, &s2);
    FlowMock f2(f1); // Copia f1
    assert(f2.pImpl_->m_source == &s1); // Verifica se aponta para o mesmo lugar
    assert(f2.pImpl_->m_target == &s2);
}

/** @brief Teste para o operador de atribuição da classe Flow */
void unit_Flow::unit_flow_assignmentOperator() {
    SystemHandle s1(100.0);
    SystemHandle s2(50.0);
    FlowMock f1(&s1, &s2);
    FlowMock f2;
    f2 = f1; // Atribuição
    assert(f2.pImpl_->m_source == &s1);
    assert(f2.pImpl_->m_target == &s2);
}

/** @brief Teste para o destrutor da classe Flow */
void unit_Flow::unit_flow_destructor() {
    unit_flow_destructor_count = 0;
    
    FlowHandle *f = new FlowDestructorSpy();
    delete f;
    
    assert(unit_flow_destructor_count == 1);
}

/** @brief Função para executar todos os testes unitários da classe Flow */
void unit_Flow::run_unit_tests_Flow() {
    unit_flow_constructor();
    unit_flow_setSource();
    unit_flow_setTarget();
    unit_flow_getSource();
    unit_flow_getTarget();
    unit_flow_copy_constructor();
    unit_flow_assignmentOperator();
    unit_flow_destructor();
}