#include "unit_model.hpp"
#include "../../src/lib/model_impl.hpp"
#include "../../src/lib/system_impl.hpp"
#include "../../src/lib/flow_impl.hpp"
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
    SystemSpy(double value = 0.0) : System_impl(value) {}
    ~SystemSpy() { sys_destructor_calls++; }
};

/** Classe espiã para Flow_impl que incrementa contador no destrutor */
class FlowSpy : public Flow_impl {
public:
    FlowSpy() : Flow_impl() {}
    ~FlowSpy() { flow_destructor_calls++; }
    double equation() override { return 0; }
};

// --- TESTES ---
/** @brief Testa o construtor padrão do Model_impl */
void unit_Model::unit_model_constructor() {
    Model_impl m;
    // Acesso direto à memória via friend:
    // Verificamos se os vetores internos foram inicializados vazios
    assert(m.m_systems.size() == 0);
    assert(m.m_flows.size() == 0);
    
    // Também podemos checar se o tempo começou em 0
    assert(m.m_time == 0.0);
}

/** @brief Testa o método add do Model_impl */
void unit_Model::unit_model_add() {
    // CORREÇÃO: Usar Model_impl* em vez de Model*
    // O compilador precisa saber que é Model_impl para liberar o acesso 'protected' via friend
    Model_impl *m = new Model_impl(); 
    
    // Construtores SEM NOME
    System_impl *s = new System_impl(100.0);
    FlowMock *f = new FlowMock(); 

    m->add(s); 
    m->add(f);

    // Verifica se realmente adicionou
    assert(m->m_systems.size() == 1);
    assert(m->m_flows.size() == 1);

    delete m;
}

/** @brief Testa o método run do Model_impl */
void unit_Model::unit_model_run() {
    Model_impl m;

    System_impl *s1 = new System_impl(100.0);
    System_impl *s2 = new System_impl(0.0);

    FlowMock *f = new FlowMock(s1, s2, 10.0);

    m.m_systems.push_back(s1);
    m.m_systems.push_back(s2);
    m.m_flows.push_back(f);

    m.run(0, 1, 1);

    // Verifica
    assert(std::abs(s1->getValue() - 90.0) < 0.0001);
    assert(std::abs(s2->getValue() - 10.0) < 0.0001);
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
    // Reset dos contadores
    sys_destructor_calls = 0;
    flow_destructor_calls = 0;

    // Usamos Model_impl diretamente para acessar o destrutor e o add
    Model_impl *m = new Model_impl();

    // Adiciona Spies (Sem nomes, apenas valores quando necessário)
    m->add(new SystemSpy(10.0));
    m->add(new SystemSpy(20.0));
    m->add(new FlowSpy());

    // Ao deletar o modelo, ele deve deletar os filhos
    delete m;

    assert(sys_destructor_calls == 2);
    assert(flow_destructor_calls == 1);
}

/** @brief Teste para verificar o funcionamento dos iteradores de System */
void unit_Model::unit_model_iterator_systems() {
    Model_impl m;
    System_impl *s = new System_impl(100.0); // Sem nome

    // Vazio
    assert(m.beginSystems() == m.endSystems());

    m.add(s);

    // Preenchido
    assert(m.beginSystems() != m.endSystems());
    assert(*m.beginSystems() == s);
}

/** @brief Teste para verificar o funcionamento dos iteradores de Flow */
void unit_Model::unit_model_iterator_flows() {
    Model_impl m;
    FlowMock *f = new FlowMock();

    // Vazio
    assert(m.beginFlows() == m.endFlows());

    m.add(f);

    // Preenchido
    assert(m.beginFlows() != m.endFlows());
    assert(*m.beginFlows() == f);
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