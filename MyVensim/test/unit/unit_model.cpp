#include "unit_model.hpp"
#include "../../src/model_implement.hpp"
#include "../../src/system_implement.hpp"
#include "../../src/flow_implement.hpp"
#include "flow_mock.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

void unit_Model_constructor() {
    Model_implement m;
    // Verifica se inicia vazio
    assert(m.beginSystems() == m.endSystems());
    assert(m.beginFlows() == m.endFlows());
}

void unit_Model_add() {
    Model *m = new Model_implement();
    System_implement *s = new System_implement(100.0);
    // Cria fluxo que retorna 0 (padrão) ou 1, tanto faz aqui
    FlowMock *f = new FlowMock(); 

    m->add(s);
    m->add(f);
}

void unit_Model_run() {
    Model *m = new Model_implement();
    System_implement *s1 = new System_implement(100.0);
    System_implement *s2 = new System_implement(0.0);
    
    // AQUI É A MÁGICA: Passamos 1.0 no construtor!
    // Assim a equation() vai retornar 1.0
    FlowMock *f = new FlowMock(s1, s2, 1.0); 

    m->add(s1);
    m->add(s2);
    m->add(f);

    m->run(0, 1, 1);
}

void unit_Model_copy_constructor() {
    Model_implement m1;
    System_implement *s = new System_implement(100.0);
    m1.add(s);

    // 2. Cria m2 como cópia de m1
    Model_implement m2(m1);

    // 3. Verifica se m2 também tem o sistema
    // (Se o iterador inicio for diferente do fim, significa que tem elementos)
    assert(m2.beginSystems() != m2.endSystems());
}

void unit_Model_assignmentOperator() {
    // 1. Cria o modelo original m1 com conteúdo
    Model_implement m1;
    System_implement *s = new System_implement(100.0);
    m1.add(s);

    // 2. Cria m2 vazio
    Model_implement m2;
    
    // 3. Atribui m1 a m2
    m2 = m1;

    // 4. Verifica se m2 recebeu o sistema
    assert(m2.beginSystems() != m2.endSystems());
}

void run_unit_tests_Model() {
    unit_Model_constructor();
    unit_Model_add();
    unit_Model_run();
    unit_Model_copy_constructor();
    unit_Model_assignmentOperator();
}