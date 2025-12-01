#include "unit_flow.hpp"
#include "../../src/flow_implement.hpp"
#include "../../src/system_implement.hpp"
#include "flow_mock.hpp"
#include <iostream>
#include <cassert>

void unit_Flow_constructor() {
    System_implement s1(100.0);
    System_implement s2(50.0);
    // Usamos FlowMock em vez de Flow
    FlowMock f(&s1, &s2); 
    
    assert(f.getSource() == &s1);
    assert(f.getTarget() == &s2);
}

void unit_Flow_setSource() {
    System_implement s1(100.0);
    FlowMock f;
    f.setSource(&s1);
    assert(f.getSource() == &s1);
}

void unit_Flow_setTarget() {
    System_implement s2(50.0);
    FlowMock f;
    f.setTarget(&s2);
    assert(f.getTarget() == &s2);
}

void unit_Flow_getSource() {
    System_implement s1(100.0);
    System_implement s2(50.0);
    FlowMock f(&s1, &s2);
    assert(f.getSource() == &s1);
}

void unit_Flow_getTarget() {
    System_implement s1(100.0);
    System_implement s2(50.0);
    FlowMock f(&s1, &s2);
    assert(f.getTarget() == &s2);
}

void unit_Flow_copy_constructor() {
    System_implement s1(100.0);
    System_implement s2(50.0);
    FlowMock f1(&s1, &s2);
    FlowMock f2(f1); // Copia f1
    assert(f2.getSource() == &s1); // Verifica se aponta para o mesmo lugar
    assert(f2.getTarget() == &s2);
}

void unit_Flow_assignmentOperator() {
    System_implement s1(100.0);
    System_implement s2(50.0);
    FlowMock f1(&s1, &s2);
    FlowMock f2;
    f2 = f1; // Atribuição
    assert(f2.getSource() == &s1);
    assert(f2.getTarget() == &s2);
}

void run_unit_tests_Flow() {
    unit_Flow_constructor();
    unit_Flow_setSource();
    unit_Flow_setTarget();
    unit_Flow_getSource();
    unit_Flow_getTarget();
    unit_Flow_copy_constructor();
    unit_Flow_assignmentOperator();
}