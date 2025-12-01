/**
 * @file system_implement.hpp
 * @brief Declaração da classe concreta System_implement.
 */

#ifndef SYSTEM_IMPLEMENT_HPP
#define SYSTEM_IMPLEMENT_HPP
#include "system.hpp"

/**
 * @class System_implement
 * @brief Implementação concreta da interface System.
 * * Esta classe define a variável de estado e implementa os métodos
 * de acesso e modificação.
 */
class System_implement : public System {
protected:
    /** @brief Valor atual armazenado no sistema. */
    double m_value;

public:
  /** * @brief Construtor padrão. 
  * Inicializa o valor com 0.0.
  */
  System_implement();

  /**
     * @brief Construtor com valor inicial.
     * @param value Valor numérico inicial do sistema.
     */
  System_implement(double value);

  /**
     * @brief Construtor de cópia.
     * @param other Objeto a ser copiado.
     */
  System_implement(const System_implement &other);

  /**
     * @brief Operador de atribuição.
     * @param other Sistema a ser copiado.
     * @return Referência para o próprio objeto.
     */
  System_implement &operator=(const System_implement &other);

  /** * @brief Destrutor virtual. 
     */
  virtual ~System_implement();
  
  /**
     * @brief Define o valor armazenado no sistema.
     * @param value Novo valor a ser atribuído.
     */
  void setValue(double value);

  /**
     * @brief Retorna o valor atual do sistema.
     * @return O valor armazenado (double).
     */
  double getValue() const;
};

#endif // SYSTEM_IMPLEMENT_HPP