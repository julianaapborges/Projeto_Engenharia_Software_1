#ifndef SYSTEM_H
#define SYSTEM_H

class System {
protected:
    double m_value;

public:
  System();
  System(double value);
  System(const System &other);
  System &operator=(const System &other);
  virtual ~System();
  
  void print();
  void setValue(double value);
  double getValue();
};

#endif // SYSTEM_H