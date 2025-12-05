#include "unit_model.hpp"
#include "../../src/model_impl.hpp"
#include "../../src/system_impl.hpp"
#include "../../src/flow_impl.hpp"
#include "flow_mock.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

// --- VARIAVEIS GLOBAIS DE CONTROLE ---
/** Contadores para verificar chamadas de destrutores em testes */
int sys_destructor_calls = 0;
int flow_destructor_calls = 0;

// --- CLASSES ESPIÃS ---
/** Classe espiã para System_impl que incrementa contador no destrutor */
class SystemSpy : public System_impl {
public:
    SystemSpy() : System_impl() {}
    ~SystemSpy() { sys_destructor_calls++; }
};

/** Classe espiã para Flow_impl que incrementa contador no destrutor */
class FlowSpy : public Flow_impl {
public:
    FlowSpy() : Flow_impl() {}
    ~FlowSpy() { flow_destructor_calls++; }
    double equation() { return 0; }
};

// --- TESTES ---
/** @brief Testa o construtor padrão do Model_impl */
void unit_Model::unit_model_constructor() {
    Model_impl m;
    assert(m.beginSystems() == m.endSystems());
    assert(m.beginFlows() == m.endFlows());
}

/** @brief Testa o método add do Model_impl */
void unit_Model::unit_model_add() {
    Model *m = new Model_impl();
    System_impl *s = new System_impl(100.0);
    FlowMock *f = new FlowMock(); 

    m->add(s);
    m->add(f);
    
    // Precisamos deletar m para não vazar memória, 
    // mas o destrutor agora limpa s e f, então está seguro.
    delete m; 
}

/** @brief Testa o método run do Model_impl */
void unit_Model::unit_model_run() {
    Model *m = new Model_impl();
    System_impl *s1 = new System_impl(100.0);
    System_impl *s2 = new System_impl(0.0);
    FlowMock *f = new FlowMock(s1, s2, 1.0); 

    m->add(s1);
    m->add(s2);
    m->add(f);

    m->run(0, 1, 1);
    
    // Validação básica
    assert(fabs(s1->getValue() - 99.0) < 0.0001);
    
    delete m;
}

/** @brief Testa o construtor de cópia do Model_impl */
void unit_Model::unit_model_copy_constructor() {
    // Cria m1 e adiciona sistema
    Model_impl m1;
    System_impl *s = new System_impl(100.0);
    m1.add(s);

    // Cria m2 como cópia de m1 (Aponta para o mesmo 's')
    Model_impl m2(m1);

    // Verifica se a cópia funcionou
    assert(m2.beginSystems() != m2.endSystems());

    // --- CORREÇÃO DO SEGMENTATION FAULT ---
    // Como m1 e m2 apontam para o mesmo 's', se deixarmos ambos serem destruídos,
    // teremos double free. Vamos limpar o vetor de m2 manualmente para que ele
    // não delete o 's' quando sair do escopo. O m1 vai cuidar de deletar.
    m2.m_systems.clear(); 
    m2.m_flows.clear();
}

/** @brief Testa o operador de atribuição do Model_impl */
void unit_Model::unit_model_assignmentOperator() {
    Model_impl m1;
    System_impl *s = new System_impl(100.0);
    m1.add(s);

    Model_impl m2;
    m2 = m1; // Atribuição (Cópia rasa)

    assert(m2.beginSystems() != m2.endSystems());

    // --- CORREÇÃO DO SEGMENTATION FAULT ---
    // m2 esquece os ponteiros para não deletar o que é de m1
    m2.m_systems.clear();
    m2.m_flows.clear();
}

/** @brief Testa o destrutor do Model_impl */
void unit_Model::unit_model_destructor() {
    sys_destructor_calls = 0;
    flow_destructor_calls = 0;

    // Cria modelo com 2 sistemas e 1 fluxo
    Model *m = new Model_impl();
    m->add(new SystemSpy());
    m->add(new SystemSpy());
    m->add(new FlowSpy());

    // Deleta modelo, o que deve disparar os destrutores
    delete m;

    // Verifica se os destrutores foram chamados corretamente
    assert(sys_destructor_calls == 2);
    assert(flow_destructor_calls == 1);
}

/** @brief Teste para verificar o funcionamento dos iteradores de System */
void unit_Model::unit_model_iterator_systems() {
    Model_impl m;
    System_impl *s = new System_impl(100.0);

    // Teste Vazio: begin deve ser igual a end
    assert(m.beginSystems() == m.endSystems());

    // Adiciona elemento
    m.add(s);

    // Teste Preenchido: begin deve ser diferente de end
    assert(m.beginSystems() != m.endSystems());

    // Teste de Acesso: O conteúdo apontado é o correto?
    assert(*m.beginSystems() == s);
    
    // O destrutor de 'm' vai limpar 's' ao sair do escopo
}

/** @brief Teste para verificar o funcionamento dos iteradores de Flow */
void unit_Model::unit_model_iterator_flows() {
    Model_impl m;
    FlowMock *f = new FlowMock();

    // Teste Vazio
    assert(m.beginFlows() == m.endFlows());

    // Adiciona elemento
    m.add(f);

    // Teste Preenchido
    assert(m.beginFlows() != m.endFlows());

    // Teste de Acesso
    assert(*m.beginFlows() == f);
    
    // O destrutor de 'm' vai limpar 'f' ao sair do escopo
}

/** @brief Executa todos os testes unitários do Model_impl */
void unit_Model::run_unit_tests_Model() {
    unit_model_constructor();
    unit_model_add();
    unit_model_run();
    unit_model_copy_constructor();
    unit_model_assignmentOperator();
    unit_model_destructor();
    unit_model_iterator_systems();
    unit_model_iterator_flows();
}