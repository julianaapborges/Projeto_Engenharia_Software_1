#include "funcional_tests.hpp"
#include "../../src/lib/flow.hpp"
#include "../../src/lib/model.hpp"
#include "../../src/lib/system.hpp"
#include <cassert>
#include <cmath>

/** @brief Teste funcional para o crescimento exponencial */
void exponentialFunctionalTest() {
  class Exponential : public Flow {
    System *source = nullptr;
    System *target = nullptr;
  public:
      // Precisamos implementar os métodos da interface Flow manualmente
      void setSource(System *s) override { source = s; }
      void setTarget(System *t) override { target = t; }
      System* getSource() const override { return source; }
      System* getTarget() const override { return target; }

      // A equação continua a mesma
      double equation() override { 
          if(source != nullptr)
              return 0.01 * source->getValue(); 
          return 0.0;
      }
  };

  // USANDO FÁBRICA (Factory Method)
  // Em vez de: System *pop1 = new System_impl(100);
  System *pop1 = System::createSystem(100);
  System *pop2 = System::createSystem(0);

  Exponential *exp = new Exponential();
  exp->setSource(pop1);
  exp->setTarget(pop2);

  // USANDO FÁBRICA
  // Em vez de: Model *model = new Model_impl();
  Model *model = Model::createModel(0.0, 100.0); // Assumindo que mudamos a factory para receber tempo

  model->add(pop1);
  model->add(pop2);
  model->add(exp);
  
  model->run(0, 100, 1);

  assert(abs(pop1->getValue() - 36.6032) < 0.0001);
  assert(abs(pop2->getValue() - 63.3968) < 0.0001);

  // Lembre-se: O destrutor do Model deleta os Systems e Flows adicionados?
  // Se sim, apenas delete model. Se não, delete tudo.
  // Pela sua implementação anterior, o Model deleta tudo.
  delete model;
}

/** @brief Teste funcional para o crescimento logístico */
void logisticalFunctionalTest() {
  class Logistical : public Flow {
    System *source = nullptr;
    System *target = nullptr;
  public:
      void setSource(System *s) override { source = s; }
      void setTarget(System *t) override { target = t; }
      System* getSource() const override { return source; }
      System* getTarget() const override { return target; }

      double equation() override {
          if(target != nullptr)
              return 0.01 * target->getValue() * (1 - target->getValue() / 70);
          return 0.0;
      }
  };

  System *p1 = System::createSystem(100);
  System *p2 = System::createSystem(10);

  Logistical *log = new Logistical();
  log->setSource(p1);
  log->setTarget(p2);

  Model *model = Model::createModel();

  model->add(p1);
  model->add(p2);
  model->add(log);
  
  model->run(0, 100, 1);

  assert(abs(p1->getValue() - 88.2167) < 0.0001);
  assert(abs(p2->getValue() - 21.7833) < 0.0001);

  delete model;
}

/** @brief Teste funcional para um cenário complexo */
void complexFunctionalTest() {
  class Complex : public Flow {
    System *source = nullptr;
    System *target = nullptr;
  public:
      void setSource(System *s) override { source = s; }
      void setTarget(System *t) override { target = t; }
      System* getSource() const override { return source; }
      System* getTarget() const override { return target; }

      double equation() override {
          if(source != nullptr)
              return 0.01 * source->getValue();
          return 0.0;
      }
  };

  Model *model = Model::createModel(0.0, 100.0);

  Complex *f = new Complex();
  Complex *g = new Complex();
  Complex *r = new Complex();
  Complex *t = new Complex();
  Complex *u = new Complex();
  Complex *v = new Complex();

  System *q1 = System::createSystem(100);
  System *q2 = System::createSystem(0);
  System *q3 = System::createSystem(100);
  System *q4 = System::createSystem(0);
  System *q5 = System::createSystem(0);

  f->setSource(q1);
  f->setTarget(q2);

  g->setSource(q1);
  g->setTarget(q3);

  r->setSource(q2);
  r->setTarget(q5);

  t->setSource(q2);
  t->setTarget(q3);

  u->setSource(q3);
  u->setTarget(q4);

  v->setSource(q4);
  v->setTarget(q1);

  model->add(q1);
  model->add(q2);
  model->add(q3);
  model->add(q4);
  model->add(q5);

  model->add(f);
  model->add(g);
  model->add(r);
  model->add(t);
  model->add(u);
  model->add(v);

  model->run(0, 100, 1);

  // Validação rigorosa com abs
  assert(std::abs(q1->getValue() - 31.8513) < 0.0001);
  assert(std::abs(q2->getValue() - 18.4003) < 0.0001);
  assert(std::abs(q3->getValue() - 77.1143) < 0.0001);
  assert(std::abs(q4->getValue() - 56.1728) < 0.0001);
  assert(std::abs(q5->getValue() - 16.4612) < 0.0001);

  delete model;
}
