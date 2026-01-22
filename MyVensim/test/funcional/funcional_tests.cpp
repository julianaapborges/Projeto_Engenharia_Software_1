#include "funcional_tests.hpp"
#include "../../src/lib/flow.hpp"
#include "../../src/lib/model.hpp"
#include "../../src/lib/system.hpp"
#include "../../src/lib/flow_handle.hpp"
#include <cassert>
#include <cmath>

using namespace std;

// Definição das variáveis globais necessárias para o Handle/Body funcionar
int numHandleCreated = 0;
int numHandleDeleted = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;

// Fluxo Exponencial
/** @brief Fluxo exponencial usado em cenário exponencial */
class FlowExponential : public FlowHandle {
public:
    // Construtor repassa para o pai (FlowHandle)
    FlowExponential() : FlowHandle() {}
    
    double equation() override {
        if (getSource() != NULL)
            return 0.01 * getSource()->getValue();
        return 0.0;
    }
};

// Fluxo Logístico
/** @brief Fluxo logístico usado em cenário logístico */
class FlowLogistical : public FlowHandle {
public:
    FlowLogistical() : FlowHandle() {}
    
    double equation() override{
        if (getTarget() != NULL) {
            double p = getTarget()->getValue();
            return 0.01 * p * (1 - p / 70);
        }
        return 0.0;
    }
};

// Fluxo Complexo (Mesma equação do Exponencial, mas usado em outro contexto)
/** @brief Fluxo complexo usado em cenário complexo */
class FlowComplexo : public FlowHandle {
public:
    FlowComplexo() : FlowHandle() {}
    
    double equation() override{
        if (getSource() != NULL)
            return 0.01 * getSource()->getValue();
        return 0.0;
    }
};

/** @brief Teste funcional para o crescimento exponencial */
void exponentialFunctionalTest() {
  // 1. Cria Modelo
    Model *model = Model::createModel();

    // 2. Cria Sistemas (Removido o nome "pop1", apenas valor)
    System *pop1 = model->createSystem(100.0);
    System *pop2 = model->createSystem(0.0);

    // 3. Cria Fluxo (Removido o nome "exponencial")
    model->createFlow<FlowExponential>(pop1, pop2);

    // 4. Executa
    model->run(0, 100, 1);

    // 5. Valida
    assert(fabs(pop1->getValue() - 36.6032) < 0.0001);
    assert(fabs(pop2->getValue() - 63.3968) < 0.0001);

    // 6. Limpa
    delete model;

    cout << "Teste Exponencial -> Handles Criados: " << numHandleCreated << ", Deletados: " << numHandleDeleted << endl;
    cout << "Teste Exponencial -> Bodies Criados: " << numBodyCreated << ", Deletados: " << numBodyDeleted << endl;
}

/** @brief Teste funcional para o crescimento logístico */
void logisticalFunctionalTest() {
  Model *model = Model::createModel();

    // CORREÇÃO AQUI: Removido "p1" e "p2"
    System *p1 = model->createSystem(100.0);
    System *p2 = model->createSystem(10.0);

    // CORREÇÃO AQUI: Removido nome do fluxo
    model->createFlow<FlowLogistical>(p1, p2);

    model->run(0, 100, 1);

    assert(fabs(p1->getValue() - 88.2167) < 0.0001);
    assert(fabs(p2->getValue() - 21.7833) < 0.0001);

    delete model;

    cout << "Teste Logístico -> Handles Criados: " << numHandleCreated << ", Deletados: " << numHandleDeleted << endl;
    cout << "Teste Logístico -> Bodies Criados: " << numBodyCreated << ", Deletados: " << numBodyDeleted << endl;
}

/** @brief Teste funcional para um cenário complexo */
void complexFunctionalTest() {
  Model *model = Model::createModel();

    // CORREÇÃO AQUI: Removidos nomes "Q1"..."Q5"
    System *q1 = model->createSystem(100.0);
    System *q2 = model->createSystem(0.0);
    System *q3 = model->createSystem(100.0);
    System *q4 = model->createSystem(0.0);
    System *q5 = model->createSystem(0.0);

    // CORREÇÃO AQUI: Removidos nomes "f", "g", "r", etc.
    model->createFlow<FlowComplexo>(q1, q2); // f
    model->createFlow<FlowComplexo>(q1, q3); // g
    model->createFlow<FlowComplexo>(q2, q5); // r
    model->createFlow<FlowComplexo>(q2, q3); // t
    model->createFlow<FlowComplexo>(q3, q4); // u
    model->createFlow<FlowComplexo>(q4, q1); // v

    model->run(0, 100, 1);

    // Validação
    assert(fabs(q1->getValue() - 31.8513) < 0.0001);
    assert(fabs(q2->getValue() - 18.4003) < 0.0001);
    assert(fabs(q3->getValue() - 77.1143) < 0.0001);
    assert(fabs(q4->getValue() - 56.1728) < 0.0001);
    assert(fabs(q5->getValue() - 16.4612) < 0.0001);

    delete model;

    cout << "Teste Complexo -> Handles Criados: " << numHandleCreated << ", Deletados: " << numHandleDeleted << endl;
    cout << "Teste Complexo -> Bodies Criados: " << numBodyCreated << ", Deletados: " << numBodyDeleted << endl;
}
