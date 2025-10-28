#include "bib.hpp"

long long calcularFatorial(int n) {
    if (n < 0) {
        return -1; 
    }
    if (n == 0 || n == 1) {
        return 1;
    }

    long long resultado = 1;
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

bool ehPrimo(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}