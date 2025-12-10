/**
 * @file flow_impl.hpp
 * @brief Declaração da classe Flow_impl (Abstrata).
 */

#ifndef FLOW_IMPL_HPP
#define FLOW_IMPL_HPP

#include "flow.hpp"
#include "system.hpp"

/**
 * @class Flow_impl
 * @brief Implementação base para fluxos.
 * * Esta classe gerencia os ponteiros de origem (Source) e destino (Target),
 * mas mantém o método equation() como abstrato.
 */
class Flow_impl : public Flow {
protected:
    /** @brief Ponteiro para o sistema de origem (quem perde valor). */
    System *m_source;
    /** @brief Ponteiro para o sistema de destino (quem ganha valor). */
    System *m_target;

public:
    /** @brief Construtor padrão. Inicializa ponteiros como NULL. */
    Flow_impl();

    /** * @brief Construtor parametrizado.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    Flow_impl(System *source, System *target);

    /** @brief Construtor de cópia. 
    * @param other Objeto a ser copiado.
    */
    Flow_impl(const Flow_impl &other);

    /** @brief Operador de atribuição. 
    * @param other Fluxo a ser copiado.
    * @return Referência para o próprio objeto.
    */
    Flow_impl& operator=(const Flow_impl &other);

    /** @brief Destrutor virtual. */
    virtual ~Flow_impl();

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

    /** @brief Permite que a classe unit_Flow acesse membros privados/protegidos. */
    friend class unit_Flow; // unit_Flow pode acessar membros privados/protegidos
};

#endif // FLOW_IMPL_HPP