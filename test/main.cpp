#include <iostream>
#include <cassert> 
#include "../src/bib.hpp" 

void testFatorial() {
    std::cout << "Iniciando testes de Fatorial..." << std::endl;

    // Cenário 1: Fatorial de 0 deve ser 1
    assert(calcularFatorial(0) == 1);
    std::cout << "Teste 1 (Fatorial 0) OK" << std::endl;

    // Cenário 2: Fatorial de 1 deve ser 1
    assert(calcularFatorial(1) == 1);
    std::cout << "Teste 2 (Fatorial 1) OK" << std::endl;

    // Cenário 3: Fatorial de 5 deve ser 120
    assert(calcularFatorial(5) == 120);
    std::cout << "Teste 3 (Fatorial 5) OK" << std::endl;

    std::cout << "Todos os testes de Fatorial passaram!" << std::endl;
}

void testEhPrimo(){
    std::cout << "Iniciando testes de EhPrimo..." << std::endl;
    assert(ehPrimo(2) == true);
    assert(ehPrimo(3) == true);
    assert(ehPrimo(4) == false);
    assert(ehPrimo(17) == true);
    assert(ehPrimo(1) == false);
    assert(ehPrimo(0) == false);
    std::cout << "Todos os testes de EhPrimo passaram!" << std::endl;
}

int main() {
    testFatorial();
    testEhPrimo();
    return 0;
}