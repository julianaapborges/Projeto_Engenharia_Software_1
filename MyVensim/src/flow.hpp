/**
 * @file flow.hpp
 * @brief Interface pura para a classe Flow.
 * @author Juliana Aparecida Borges 
 * @date 2025-12-01
 */
#ifndef FLOW_HPP
#define FLOW_HPP

class System;

/**
 * @class Flow
 * @brief Interface que representa um Fluxo na teoria de sistemas.
 * * Um fluxo conecta dois sistemas (Origem e Destino) e transporta
 * valores entre eles baseado em uma equação matemática.
 */
class Flow {
public:
    /** @brief Destrutor virtual. */
    virtual ~Flow() {}

    // Métodos virtuais puros (Interface)
    /** @brief Define o sistema de origem (Source). */
    virtual void setSource(System *source) = 0;
    /** @brief Define o sistema de destino (Target). */
    virtual void setTarget(System *target) = 0;
    
    /** @brief Obtém o sistema de origem (Source). */
    virtual System *getSource() const = 0;
    /** @brief Obtém o sistema de destino (Target). */
    virtual System *getTarget() const = 0;

    /**
    * @brief Calcula a taxa de transferência do fluxo.
    * @return O valor a ser transferido neste passo de tempo.
    * @warning Este método é abstrato puro e DEVE ser implementado pelo usuário.
    */
    virtual double equation() = 0;
};

#endif // FLOW_HPP