#ifndef FLOW_H
#define FLOW_H

#include "system.hpp"

class Flow {
protected:
    System *m_source;
    System *m_target;
public:
    Flow();
    Flow(System *source, System *target);
    virtual ~Flow();

    void setSource(System *source);
    void setTarget(System *target);
    System *getSource();
    System *getTarget();

    virtual double equation() = 0; // must be implemented by concrete flows
    Flow(const Flow &flow); // copy constructor
    Flow& operator=(const Flow &flow); // assignment operator
};

#endif // FLOW_H