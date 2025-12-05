#ifndef MAIN_UNIT_CPP
#define MAIN_UNIT_CPP

#include "unit_flow.hpp"
#include "unit_model.hpp"
#include "unit_system.hpp" 

#include <iostream>

int main() {
    // Chama os testes do Flow
    std::cout << "Rodando testes unitários de Flow..." << std::endl;
    unit_Flow uf;
    uf.run_unit_tests_Flow();
    std::cout << "OK!" << std::endl;

    // Chama os testes do Model
    std::cout << "Rodando testes unitários de Model..." << std::endl;
    unit_Model um;
    um.run_unit_tests_Model();
    std::cout << "OK!" << std::endl;

    // Chama os testes do System
    std::cout << "Rodando testes unitários de System..." << std::endl;
    unit_System us;
    us.run_unit_tests_System();
    std::cout << "OK!" << std::endl;

    return 0;
}

#endif // MAIN_UNIT_CPP