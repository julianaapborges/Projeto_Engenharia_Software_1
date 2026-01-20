/** @file system_body.hpp
*   @brief Declaração da classe concreta System_body.
*/

#ifndef SYSTEM_BODY_HPP
#define SYSTEM_BODY_HPP

#include "handleBody.hpp"

/** @brief Contadores globais para criação e destruição de bodies */
extern int numBodyCreated;
extern int numBodyDeleted;

/** @class SystemBody
    @brief Classe concreta que representa o corpo de um System 
    Esta classe implementa os métodos para definir e obter o valor armazenado no sistema.    
*/
class SystemBody : public Body {
private:
    /** @brief Valor armazenado no SystemBody */
    double m_value;
public:
    /** @brief Construtor que inicializa o valor do SystemBody */
    SystemBody(double value = 0.0) : m_value(value) {
        numBodyCreated++;
    }
    /** @brief Destrutor que atualiza o contador global */
    virtual ~SystemBody() {
        numBodyDeleted++;
    }
    /** @brief Define o valor armazenado no SystemBody */
    void setValue(double value) { m_value = value; }
    /** @brief Obtém o valor armazenado no SystemBody */
    double getValue() const { return m_value; }

    /** @brief Declaração de amizade para permitir acesso aos membros privados em testes unitários */
    friend class unit_System;
};

#endif