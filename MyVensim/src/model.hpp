/**
 * @file model.hpp
 * @brief Declaração da classe Model (Motor da simulação).
 * @author Juliana Aparecida Borges
 * @date 2025
 */

#ifndef MODEL_HPP
#define MODEL_HPP

#include "flow.hpp"
#include "system.hpp"
#include <vector>

/**
 * @class Model
 * @brief Responsável por gerenciar e executar a simulação.
 * * O Model armazena todos os Sistemas e Fluxos, controla o tempo
 * e executa os cálculos passo-a-passo.
 */

class Model {
protected:
    /** @brief Tempo atual da simulação. */
    double m_time;
    /** @brief */
    std::vector<System*> m_systems; 
    /** @brief Contêiner de ponteiros para os Fluxos. */
    std::vector<Flow*> m_flows; 

public:
  /** @brief Construtor padrão. Inicializa tempo em 0. */
  Model();
  /** @brief Destrutor. Limpa a memória dos sistemas e fluxos alocados. */
  virtual ~Model();
  /** @brief Construtor de cópia. */
  Model(const Model &other);
  /** @brief Operador de atribuição. */
  Model &operator=(const Model &other);
  
  /** @brief Adiciona um Sistema ao modelo. */
  void add(System *system);
  /** @brief Adiciona um Fluxo ao modelo. */
  void add(Flow *flow);
  /**
     * @brief Executa a simulação.
     * @param start Tempo inicial.
     * @param final Tempo final.
     * @param increment Passo de tempo (delta t).
     */
  void run(double start, double final, int increment);

  /** @brief Iteradores para sistemas e fluxos */
  typedef std::vector<System*>::iterator systemIterator;
  typedef std::vector<Flow*>::iterator flowIterator;

  /**
     * @return Iterador apontando para o primeiro elemento do vetor de sistemas.
     */
  systemIterator beginSystems(); 

  /**
     * @return Iterador apontando para a posição final (após o último elemento) do vetor.
     */
  systemIterator endSystems();   

  /**
     * @return Iterador apontando para o primeiro elemento do vetor de fluxos.
     */
  flowIterator beginFlows(); 

  /**
     * @return Iterador apontando para a posição final (após o último elemento) do vetor.
     */
  flowIterator endFlows();
};

#endif // MODEL_HPP
