#ifndef MODEL_H
#define MODEL_H

#include "flow.hpp"
#include "system.hpp"
#include <vector>

class Model {
protected:
    double m_time;
    std::vector<System *> m_systems;
    std::vector<Flow *> m_flows;

public:
  Model();
  virtual ~Model();
  Model(const Model &model);
  Model &operator=(const Model &model);
  
  void add(System *system);
  void add(Flow *flow);
  void run(double start, double final, int increment);
};

#endif // MODEL_H
