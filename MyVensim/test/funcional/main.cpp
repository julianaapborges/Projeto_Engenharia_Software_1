#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.hpp"
#include <iostream>

int main() {

  std::cout << "Rodando testes funcionais exponenciais..." << std::endl;
  exponentialFunctionalTest();
  std::cout << "OK!" << std::endl;

  std::cout << "Rodando testes funcionais logísticos..." << std::endl;
  logisticalFunctionalTest();
  std::cout << "OK!" << std::endl;

  std::cout << "Rodando testes funcionais complexos..." << std::endl;
  complexFunctionalTest();
  std::cout << "OK!" << std::endl;

  return 0;
}

#endif // MAIN_FUNCIONAL_TESTS
