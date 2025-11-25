/**
 * @file flow.hpp
 * @brief Declaração da classe Flow (Abstrata).
 * @author Juliana Aparecida Borges
 * @date 2025
 */

#ifndef FLOW_HPP
#define FLOW_HPP

#include "system.hpp"

/**
 * @class Flow
 * @brief Classe base abstrata para fluxos (transferências entre sistemas).
 * * Um fluxo conecta dois estoques (Source e Target) e transfere valores
 * entre eles baseado em uma equação definida nas subclasses.
 */

class Flow {
protected:
    /** @brief Ponteiro para o sistema de origem (quem perde valor). */
    System *m_source;
    /** @brief Ponteiro para o sistema de destino (quem ganha valor). */
    System *m_target;

public:
    /** @brief Construtor padrão. Inicializa ponteiros como NULL. */
    Flow();
    /** * @brief Construtor parametrizado.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    Flow(System *source, System *target);
    /** @brief Construtor de cópia. */
    Flow(const Flow &flow); // copy constructor
    /** @brief Operador de atribuição. */
    Flow& operator=(const Flow &flow); // assignment operator
    /** @brief Destrutor virtual. */
    virtual ~Flow();

    /** @brief Define a origem do fluxo. */
    void setSource(System *source);
    /** @brief Define o destino do fluxo. */
    void setTarget(System *target);
    /** @brief Retorna o ponteiro da origem. */
    System *getSource();
    /** @brief Retorna o ponteiro do destino. */
    System *getTarget();

    /**
     * @brief Método virtual puro para a equação do fluxo.
     * @return O valor calculado da taxa de transferência no passo atual.
     */
    virtual double equation() = 0; // must be implemented by concrete flows
};

#endif // FLOW_HPP
