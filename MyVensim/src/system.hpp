/**
 * @file system.hpp
 * @brief Declaração da classe System.
 * @author Juliana Aparecida Borges
 * @date 2025
 */

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

/**
 * @class System
 * @brief Representa um Estoque (Variável de Nível) na simulação.
 * * A classe System armazena o valor de energia/matéria acumulado.
 * Ela é alterada pelos fluxos ao longo do tempo.
 */

class System {
protected:
    /** @brief Valor atual armazenado no sistema. */
    double m_value;

public:
  /** * @brief Construtor padrão. 
  * Inicializa o valor com 0.0.
  */
  System();
  /**
     * @brief Construtor com valor inicial.
     * @param value Valor numérico inicial do sistema.
     */
  System(double value);
  /**
     * @brief Construtor de cópia.
     * @param system Objeto a ser copiado.
     */
  System(const System &other);
  /**
     * @brief Operador de atribuição.
     * @param system Sistema a ser copiado.
     * @return Referência para o próprio objeto.
     */
  System &operator=(const System &other);
  /** * @brief Destrutor virtual. 
     */
  virtual ~System();
  
  /**
     * @brief Define o valor armazenado no sistema.
     * @param value Novo valor a ser atribuído.
     */
  void setValue(double value);
  /**
     * @brief Retorna o valor atual do sistema.
     * @return O valor armazenado (double).
     */
  double getValue();
};

#endif // SYSTEM_HPP