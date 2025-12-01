#include "system_implement.hpp" 

System_implement::System_implement() : m_value(0.0) {}

System_implement::System_implement(double value) : m_value(value) {}
System_implement::~System_implement() {}

System_implement::System_implement(const System_implement &other) : m_value(other.m_value) {}

System_implement &System_implement::operator=(const System_implement &other) {
    if (this != &other) {
        m_value = other.m_value;
    }
    return *this;
}

void System_implement::setValue(double value) {
    m_value = value;
}

double System_implement::getValue() const {
    return m_value;
}