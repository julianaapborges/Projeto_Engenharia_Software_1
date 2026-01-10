/** @file model_body.hpp
 *  @brief Declaração da classe ModelBody que implementa o padrão Handle-Body para Body.
 */
#ifndef MODEL_BODY_HPP
#define MODEL_BODY_HPP

#include "handleBody.hpp"
#include "system.hpp"
#include "flow.hpp"
#include "system_handle.hpp" // Necessário para createSystem
#include <vector>

/** @brief Contadores globais para criação e destruição de bodies */
extern int numBodyCreated;
extern int numBodyDeleted;

/** @brief Classe concreta que representa o corpo de um Model */
class ModelBody : public Body {
protected:
    /** @brief Vetor de ponteiros para Systems */
    std::vector<System*> m_systems;
    /** @brief Vetor de ponteiros para Flows */
    std::vector<Flow*> m_flows;
    /** @brief Tempo do modelo */
    double m_time;
public:
    /** @brief Construtor que inicializa o ModelBody */
    ModelBody() : m_time(0.0) {
        numBodyCreated++;
    }
    /** @brief Destrutor que atualiza o contador global */
    virtual ~ModelBody() {
        numBodyDeleted++;
        // Limpa a memória dos objetos gerenciados
        for(auto s : m_systems) delete s;
        for(auto f : m_flows) delete f;
    }

    /** @brief Adiciona um System ao modelo */
    void add(System* s) { m_systems.push_back(s); }
    /** @brief Adiciona um Flow ao modelo */
    void add(Flow* f) { m_flows.push_back(f); }

    /** @brief Cria um novo System com um valor inicial */
    System* createSystem(double value) {
        System* s = new SystemHandle(value);
        add(s);
        return s;
    }

    /** @brief Executa o modelo no intervalo de tempo especificado */
    void run(double start, double final, int increment);

    /** @brief Iteradores para Systems e Flows */
    typedef std::vector<System*>::iterator systemIterator;
    typedef std::vector<Flow*>::iterator flowIterator;

    /** @brief Obtém o iterador para o início dos Systems */
    systemIterator beginSystems() { return m_systems.begin(); }
    /** @brief Obtém o iterador para o fim dos Systems */
    systemIterator endSystems()   { return m_systems.end(); }
    /** @brief Obtém o iterador para o início dos Flows */
    flowIterator beginFlows()     { return m_flows.begin(); }
    /** @brief Obtém o iterador para o fim dos Flows */ 
    flowIterator endFlows()       { return m_flows.end(); }
};

#endif