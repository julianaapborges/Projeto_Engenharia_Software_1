/** @file flow_body.hpp
 *  @brief Declaração da classe FlowBody que implementa o padrão Handle-Body para Flow.
 */
#ifndef FLOW_BODY_HPP
#define FLOW_BODY_HPP

#include "handleBody.hpp"
#include "system.hpp"

/** @brief Contadores globais para criação e destruição de bodies */
extern int numBodyCreated;
extern int numBodyDeleted;

/** @brief Classe concreta que representa o corpo de um Flow */
class FlowBody : public Body {
protected:
    /** @brief Ponteiro para o System de origem */
    System* m_source;
    /** @brief Ponteiro para o System de destino */
    System* m_target;
public:
    /** @brief Construtor que inicializa os ponteiros de origem e destino */
    FlowBody() : m_source(nullptr), m_target(nullptr) {
        numBodyCreated++;
    }
    /** @brief Destrutor que atualiza o contador global */
    virtual ~FlowBody() {
        numBodyDeleted++;
    }
    /** @brief Define o System de origem */
    void setSource(System* s) { m_source = s; }
    /** @brief Define o System de destino */
    void setTarget(System* t) { m_target = t; }
    /** @brief Obtém o System de origem */
    System* getSource() const { return m_source; }
    /** @brief Obtém o System de destino */
    System* getTarget() const { return m_target; }
    
    /** @brief Método que representa a equação do fluxo, pode ser sobrescrito */
    virtual double equation() { return 0.0; } 

    /** @brief Declaração de amizade para permitir acesso aos membros privados em testes unitários */
    friend class unit_Flow;
};

#endif