/** @file system_handle.hpp
 *  @brief Declaração da classe SystemHandle que implementa o padrão Handle-Body para System.
 */

#ifndef SYSTEM_HANDLE_HPP
#define SYSTEM_HANDLE_HPP

#include "system.hpp"
#include "system_body.hpp"

/** @brief Contadores globais para criação e destruição de handles */
extern int numHandleCreated;
extern int numHandleDeleted;

/** @brief Classe que representa o handle para SystemBody */
class SystemHandle : public System, public Handle<SystemBody> {
public:
    /** @brief Construtor que inicializa o valor do SystemHandle */
    SystemHandle(double value = 0.0) {
        pImpl_->setValue(value);
        numHandleCreated++;
    }
    
    /** @brief Construtor de cópia que incrementa o contador de handles */
    SystemHandle(const SystemHandle& hd) : Handle<SystemBody>(hd) {
        numHandleCreated++;
    }

    /** @brief Destrutor que atualiza o contador global */
    virtual ~SystemHandle() {
        numHandleDeleted++;
    }

    /** @brief Define o valor armazenado no SystemHandle */
    void setValue(double value) override { pImpl_->setValue(value); }
    /** @brief Obtém o valor armazenado no SystemHandle */
    double getValue() const override { return pImpl_->getValue(); }

    /** @brief Declaração de amizade para permitir acesso aos membros privados em testes unitários */
    friend class unit_System;
};

#endif