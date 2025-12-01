/**
 * @file flow_implement.hpp
 * @brief Declaração da classe Flow_implement (Abstrata).
 */

#ifndef FLOW_IMPLEMENT_HPP
#define FLOW_IMPLEMENT_HPP

#include "flow.hpp"
#include "system.hpp"

/**
 * @class Flow_implement
 * @brief Implementação base para fluxos.
 * * Esta classe gerencia os ponteiros de origem (Source) e destino (Target),
 * mas mantém o método equation() como abstrato.
 */
class Flow_implement : public Flow {
protected:
    /** @brief Ponteiro para o sistema de origem (quem perde valor). */
    System *m_source;
    /** @brief Ponteiro para o sistema de destino (quem ganha valor). */
    System *m_target;

public:
    /** @brief Construtor padrão. Inicializa ponteiros como NULL. */
    Flow_implement();

    /** * @brief Construtor parametrizado.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    Flow_implement(System *source, System *target);

    /** @brief Construtor de cópia. 
    * @param other Objeto a ser copiado.
    */
    Flow_implement(const Flow_implement &other);

    /** @brief Operador de atribuição. 
    * @param other Fluxo a ser copiado.
    * @return Referência para o próprio objeto.
    */
    Flow_implement& operator=(const Flow_implement &other);

    /** @brief Destrutor virtual. */
    virtual ~Flow_implement();

    /** @brief Define a origem do fluxo. */
    void setSource(System *source);

    /** @brief Define o destino do fluxo. */
    void setTarget(System *target);

    /** @brief Retorna o ponteiro da origem. 
    * @return Ponteiro para o sistema de origem.
    */
    System *getSource() const;

    /** @brief Retorna o ponteiro do destino. 
    * @return Ponteiro para o sistema de destino.
    */
    System *getTarget() const;

    /**
     * @brief Método virtual puro para a equação do fluxo.
     * @return O valor calculado da taxa de transferência no passo atual.
     */
    virtual double equation() = 0; // must be implemented by concrete flows
};

#endif // FLOW_IMPLEMENT_HPP