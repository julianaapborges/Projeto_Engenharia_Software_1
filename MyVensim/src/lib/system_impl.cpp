#include "system_impl.hpp" 

System_impl::System_impl() : m_value(0.0) {}

System_impl::System_impl(double value) : m_value(value) {}

System_impl::~System_impl() {}

System_impl::System_impl(const System_impl &other) : m_value(other.m_value) {}

System_impl &System_impl::operator=(const System_impl &other) {
    if (this != &other) {
        m_value = other.m_value;
    }
    return *this;
}

void System_impl::setValue(double value) {
    m_value = value;
}

double System_impl::getValue() const {
    return m_value;
}

// Implementação da Fábrica
System* System::createSystem(double value) {
    return new System_impl(value);
}