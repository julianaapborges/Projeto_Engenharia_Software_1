/** @file flow_handle.hpp
 *  @brief Declaração da classe FlowHandle que implementa o padrão Handle-Body para Flow.
 */
#ifndef FLOW_HANDLE_HPP
#define FLOW_HANDLE_HPP

#include "flow.hpp"
#include "flow_body.hpp"

/** @brief Contadores globais para criação e destruição de handles */
extern int numHandleCreated;
extern int numHandleDeleted;

/** @brief Classe que representa o handle para FlowBody */
class FlowHandle : public Flow, public Handle<FlowBody> {
public:
    /** @brief Construtor que inicializa o FlowHandle */
    FlowHandle() {
        numHandleCreated++;
    }
    
    /** @brief Construtor de cópia que incrementa o contador de handles */
    FlowHandle(const FlowHandle& hd) : Handle<FlowBody>(hd) {
        numHandleCreated++;
    }

    /** @brief Destrutor que atualiza o contador global */
    virtual ~FlowHandle() {
        numHandleDeleted++;
    }

    /** @brief Define o System de origem */
    void setSource(System* s) override { pImpl_->setSource(s); }
    /** @brief Define o System de destino */
    void setTarget(System* t) override { pImpl_->setTarget(t); }
    /** @brief Obtém o System de origem */
    System* getSource() const override { return pImpl_->getSource(); }
    /** @brief Obtém o System de destino */
    System* getTarget() const override { return pImpl_->getTarget(); }
    
    /** @brief Método que representa a equação do fluxo, pode ser sobrescrito */
    virtual double equation() = 0; 
};

#endif