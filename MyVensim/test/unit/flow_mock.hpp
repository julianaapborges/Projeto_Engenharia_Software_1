/**
 * @file flow_mock.hpp
 * @brief Declaração da classe FlowMock utilizada para testes unitários.
 * 
 * Esta classe implementa um fluxo mockado, permitindo definir manualmente
 * o valor retornado pela equação. É útil para testes, evitando depender
 * de lógica real de Modelos.
 */

#ifndef FLOW_MOCK_HPP
#define FLOW_MOCK_HPP

#include "../../src/lib/flow_impl.hpp"
#include "../../src/lib/system.hpp"

/**
 * @class FlowMock
 * @brief Implementação mock de um fluxo para testes.
 * 
 * A classe permite definir manualmente o valor retornado pela função
 * `equation()`, facilitando a validação do comportamento dos sistemas
 * sem depender de cálculos reais.
 */
class FlowMock : public Flow_impl {
private:
    /** Valor pré-definido que a equação irá retornar. */
    double m_result; // Valor que a equação vai retornar

public:
    /**
     * @brief Construtor padrão.
     * Inicializa o fluxo com valor de equação igual a 0.
     */
    FlowMock() : Flow_impl(), m_result(0.0) {}

    /**
     * @brief Construtor que define o valor que será retornado pela equação.
     * @param result Valor desejado para o retorno de `equation()`.
     */
    FlowMock(double result) : Flow_impl(), m_result(result) {}

    /**
     * @brief Construtor completo que permite definir source, target e valor da equação.
     * @param s Ponteiro para o sistema de origem (Source).
     * @param t Ponteiro para o sistema de destino (Target).
     * @param result Valor que a equação irá retornar. (Padrão: 0.0)
     */
    FlowMock(System *s, System *t, double result = 0.0) : Flow_impl(s, t), m_result(result) {}

    /**
     * @brief Retorna o valor mockado da equação.
     * Esta implementação ignora completamente informações dos sistemas,
     * retornando sempre o valor definido em `m_result`.
     * @return Valor da equação mockada.
     */
    double equation() { 
        return m_result; 
    }
};

#endif // FLOW_MOCK_HPP