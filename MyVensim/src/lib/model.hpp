/**
 * @file model.hpp
 * @brief Interface para a classe Model.
 * @author Juliana Aparecida Borges
 * @date 2025-12-01
 */
#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>

class System;
class Flow;

/**
 * @class Model
 * @brief Interface que representa o Motor de Simulação.
 * * O Model gerencia a execução da simulação, controlando o tempo
 * e a interação entre sistemas e fluxos.
 */
class Model {
public:
    /** @brief Destrutor virtual padrão. */
    virtual ~Model() {}

    // Métodos virtuais puros
    /**
     * @brief Executa a simulação.
     * @param start Tempo inicial.
     * @param final Tempo final.
     * @param increment Passo de incremento do tempo.
     */
    virtual void run(double start, double final, int increment) = 0;

    /** @brief Adiciona um Sistema ao Modelo. */
    virtual void add(System *system) = 0;

    /** @brief Adiciona um Fluxo ao Modelo. */
    virtual void add(Flow *flow) = 0;

    // Definição dos tipos de iteradores (necessário para a interface expor o acesso)
    typedef std::vector<System*>::iterator systemIterator;
    typedef std::vector<Flow*>::iterator flowIterator;

    /** @brief Retorna um iterador para o início dos sistemas. */
    virtual systemIterator beginSystems() = 0;

    /** @brief Retorna um iterador para o fim dos sistemas. */
    virtual systemIterator endSystems() = 0;

    /** @brief Retorna um iterador para o início dos fluxos. */
    virtual flowIterator beginFlows() = 0;
    
    /** @brief Retorna um iterador para o fim dos fluxos. */
    virtual flowIterator endFlows() = 0;
};

#endif // MODEL_HPP