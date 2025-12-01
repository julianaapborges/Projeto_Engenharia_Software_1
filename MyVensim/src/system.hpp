/**
 * @file system.hpp
 * @brief Interface para a classe System.
* @author Juliana Aparecida Borges 
* @date 2025-12-01
 */

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>
#include <string> 

/**
 * @class System
 * @brief Interface que representa um Sistema (Estoque) na teoria de sistemas.
 * * Um sistema armazena um valor (energia, matéria, população) que varia com o tempo
 * através da ação de fluxos. Esta é uma classe abstrata pura.
 */
class System {
public:
    /** @brief Destrutor virtual. */
    virtual ~System() {}
    
    // Métodos puramente virtuais (= 0)
    /**
     * @brief Define o valor numérico do sistema.
     * @param value O valor a ser atribuído.
     */
    virtual void setValue(double value) = 0;

    /**
     * @brief Obtém o valor atual do sistema.
     * @return O valor numérico atual (double).
     */
    virtual double getValue() const = 0; // const é boa prática em getters
};

#endif // SYSTEM_HPP