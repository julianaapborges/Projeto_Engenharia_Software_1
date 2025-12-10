/**
 * @file system_impl.hpp
 * @brief Declaração da classe concreta System_impl.
 */

#ifndef SYSTEM_IMPL_HPP
#define SYSTEM_IMPL_HPP
#include "system.hpp"

/**
 * @class System_impl
 * @brief Implementação concreta da interface System.
 * * Esta classe define a variável de estado e implementa os métodos
 * de acesso e modificação.
 */
class System_impl : public System {
protected:
    /** @brief Valor atual armazenado no sistema. */
    double m_value;

public:
  /** * @brief Construtor padrão. 
  * Inicializa o valor com 0.0.
  */
  System_impl();

  /**
     * @brief Construtor com valor inicial.
     * @param value Valor numérico inicial do sistema.
     */
  System_impl(double value);

  /**
     * @brief Construtor de cópia.
     * @param other Objeto a ser copiado.
     */
  System_impl(const System_impl &other);

  /**
     * @brief Operador de atribuição.
     * @param other Sistema a ser copiado.
     * @return Referência para o próprio objeto.
     */
  System_impl &operator=(const System_impl &other);

  /** * @brief Destrutor virtual. 
     */
  virtual ~System_impl();
  
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

  /** @brief Permite que a classe unit_System acesse membros privados/protegidos. */
  friend class unit_System; // unit_System pode acessar membros privados/protegidos
};

#endif // SYSTEM_IMPL_HPP