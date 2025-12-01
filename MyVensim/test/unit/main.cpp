#ifndef MAIN_UNIT_CPP
#define MAIN_UNIT_CPP

#include "unit_flow.hpp"
#include "unit_model.hpp"
#include "unit_system.hpp" 

#include <iostream>

int main() {
    // Chama os testes do Flow
    std::cout << "Rodando testes de Flow..." << std::endl;
    run_unit_tests_Flow();
    std::cout << "OK!" << std::endl;

    // Chama os testes do Model
    std::cout << "Rodando testes de Model..." << std::endl;
    run_unit_tests_Model();
    std::cout << "OK!" << std::endl;

    // Chama os testes do System
    std::cout << "Rodando testes de System..." << std::endl;
    run_unit_tests_System();
    std::cout << "OK!" << std::endl;

    return 0;
}

#endif // MAIN_UNIT_CPP