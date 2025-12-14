/**
 * @file model.hpp
 * @brief Interface para a classe Model.
 * @author Juliana Aparecida Borges
 * @date 2025-12-01
 */
#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <string>
#include "flow.hpp"

class System;

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

    // --- 1. FÁBRICA ESTÁTICA (Ponto de Entrada) ---
    static Model* createModel();

    // --- 2. FÁBRICA DE SISTEMAS ---
    // O usuário pede um sistema, o Model cria e guarda.
    virtual System* createSystem(double value) = 0;

    // --- 3. FÁBRICA DE FLUXOS (Template) ---
    // O usuário passa a CLASSE do fluxo (Ex: Exponential) e os sistemas.
    // O Model cria, conecta e guarda.
    template <typename T_FLOW>
    Flow* createFlow(System* source, System* target) {
        // Criamos o fluxo do tipo T_FLOW (que o usuário definiu)
        Flow* f = new T_FLOW();
        f->setSource(source);
        f->setTarget(target);
        
        // Adicionamos ao modelo (chamando o método protegido)
        add(f);
        
        return f;
    }

    // Métodos virtuais puros
    /**
     * @brief Executa a simulação.
     * @param start Tempo inicial.
     * @param final Tempo final.
     * @param increment Passo de incremento do tempo.
     */
    virtual void run(double start, double final, int increment) = 0;

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

    protected:
        // O add vira protegido/interno. O usuário não chama mais.
        virtual void add(System* system) = 0;
        virtual void add(Flow* flow) = 0;
};

#endif // MODEL_HPP