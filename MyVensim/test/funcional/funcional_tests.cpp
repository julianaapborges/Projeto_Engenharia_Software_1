#include "funcional_tests.hpp"
#include "../../src/flow.hpp"
#include "../../src/model.hpp"
#include "../../src/system.hpp"
#include <cassert>
#include <cmath>
#include <cstdint>

void exponentialFunctionalTest() {
  class exponential : public Flow {
  public:
    double equation() { return 0.01 * getSource()->getValue(); }
  };

  System *pop1 = new System(100);
  System *pop2 = new System(0);

  exponential *exp = new exponential();

  exp->setSource(pop1);
  exp->setTarget(pop2);

  Model *model = new Model();

  model->add(pop1);
  model->add(pop2);
  model->add(exp);
  model->run(0, 100, 1);

  // Validação: compara os valores finais com os esperados para crescimento/exaustão exponencial.
  assert((pop1->getValue() - 36.6032) < 0.0001);
  assert((pop2->getValue() - 63.3968) < 0.0001);

  delete model;
}

void logisticalFunctionalTest() {
  class logistical : public Flow {
  public:
    double equation() {
      return 0.01 * getTarget()->getValue() *
             (1 - getTarget()->getValue() / 70);
    }
  };

  System *p1 = new System(100);
  System *p2 = new System(10);

  logistical *log = new logistical();

  log->setSource(p1);
  log->setTarget(p2);

  Model *model = new Model();

  model->add(p1);
  model->add(p2);
  model->add(log);
  model->run(0, 100, 1);

  // Validação logística: compara os valores finais com os esperados para crescimento logístico.
  assert((p1->getValue() - 88.2167) < 0.0001);
  assert((p2->getValue() - 21.7833) < 0.0001);

  delete model;
}

void complexFunctionalTest() {
  class complex : public Flow {
  public:
    double equation() { return 0.01 * getSource()->getValue(); }
  };

  Model *model = new Model();

  complex *f = new complex();
  complex *g = new complex();
  complex *r = new complex();
  complex *t = new complex();
  complex *u = new complex();
  complex *v = new complex();

  System *q1 = new System(100);
  System *q2 = new System(0);
  System *q3 = new System(100);
  System *q4 = new System(0);
  System *q5 = new System(0);

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

  // Validação do cenário complexo: compara os valores finais com os esperados.
  assert((q1->getValue() - 31.8513) < 0.0001);
  assert((q2->getValue() - 18.4003) < 0.0001);
  assert((q3->getValue() - 77.1143) < 0.0001);
  assert((q4->getValue() - 56.1728) < 0.0001);
  assert((q5->getValue() - 16.4612) < 0.0001);

  delete model;
}
