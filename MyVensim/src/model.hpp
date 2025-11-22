#ifndef MODEL_H
#define MODEL_H

#include "flow.hpp"
#include "system.hpp"
#include <vector>

class Model {
protected:
    double m_time;
    typedef std::vector<System*> SystemContainer; // coloquei em protected pois nao sei se vai ter iteradores, se precisar passo para public
    typedef std::vector<Flow*> FlowContainer; // coloquei em protected pois nao sei se vai ter iteradores, se precisar passo para public
    SystemContainer m_systems;
    FlowContainer m_flows;

public:
  Model();
  virtual ~Model();
  Model(const Model &other);
  Model &operator=(const Model &other);
  
  void add(System *system);
  void add(Flow *flow);
  void run(double start, double final, int increment);
};

#endif // MODEL_H
