/**
 * @file model_impl.hpp
 * @brief Declaração da classe Model_impl (Motor da simulação).
 */

#ifndef MODEL_IMPL_HPP
#define MODEL_IMPL_HPP

#include "model.hpp"
#include "system.hpp"
#include "flow.hpp"
#include "system_impl.hpp"
#include <vector>

/**
 * @class Model_impl
 * @brief Implementação concreta do Modelo.
 * * Gerencia os containers (vetores) de System e Flow e implementa
 * o algoritmo de execução passo-a-passo.
 */
class Model_impl : public Model {
protected:
    /** @brief Tempo atual da simulação. */
    double m_time;
    /** @brief Contêiner de ponteiros para os Sistemas. */
    std::vector<System*> m_systems; 
    /** @brief Contêiner de ponteiros para os Fluxos. */
    std::vector<Flow*> m_flows; 

    // Métodos internos
    /** @brief Adiciona um Sistema ao Modelo (implementação interna). */
    void add(System* system) override;
    /** @brief Adiciona um Fluxo ao Modelo (implementação interna). */
    void add(Flow* flow) override;

public:
   // --- MUDANÇA AQUI: STATIC ---
   // Este vetor guarda TODOS os modelos criados. 
   // Tem que ser static para o createModel (que também é static) conseguir acessar.
   static std::vector<Model*> m_models;

   /** @brief Construtor padrão. Inicializa tempo em 0. */
   Model_impl();

   /** @brief Destrutor. Limpa a memória dos sistemas e fluxos alocados. */
   virtual ~Model_impl();

   /** @brief Construtor de cópia. */
   Model_impl(const Model_impl &other);

   /** @brief Operador de atribuição. */
   Model_impl &operator=(const Model_impl &other);

   // Implementação da Fábrica de Sistemas
   /** @brief Cria e adiciona um Sistema ao Modelo. */
   System* createSystem(double value) override;
   
   /**
      * @brief Executa a simulação.
      * @param start Tempo inicial.
      * @param final Tempo final.
      * @param increment Passo de tempo (delta t).
      */
   void run(double start, double final, int increment) override;

   /** @brief Iteradores para sistemas e fluxos */
   typedef std::vector<System*>::iterator systemIterator;
   typedef std::vector<Flow*>::iterator flowIterator;
   
   /**
      * @return Iterador apontando para o primeiro elemento do vetor de sistemas.
      */
   systemIterator beginSystems() override; 

   /**
      * @return Iterador apontando para a posição final (após o último elemento) do vetor.
      */
   systemIterator endSystems() override;   

   /**
      * @return Iterador apontando para o primeiro elemento do vetor de fluxos.
      */
   flowIterator beginFlows() override; 

   /**
      * @return Iterador apontando para a posição final (após o último elemento) do vetor.
      */
   flowIterator endFlows() override;

   /** @brief Permite que a classe unit_Model acesse membros privados/protegidos. */
   friend class unit_Model; // unit_Model pode acessar membros privados/protegidos
};

#endif // MODEL_IMPL_HPP