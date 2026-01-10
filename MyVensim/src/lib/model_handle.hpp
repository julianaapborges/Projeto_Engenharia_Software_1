/** @file model_handle.hpp
 *  @brief Definição da classe ModelHandle
 */
#ifndef MODEL_HANDLE_HPP
#define MODEL_HANDLE_HPP

#include "model.hpp"
#include "model_body.hpp"

/** @brief Contadores globais para criação e destruição de handles */
extern int numHandleCreated;
extern int numHandleDeleted;

/** @brief Classe que representa o handle para ModelBody */
class ModelHandle : public Model, public Handle<ModelBody> {
public:
    /** @brief Construtor que inicializa o ModelHandle */
    ModelHandle() {
        numHandleCreated++;
    }
    /** @brief Construtor de cópia que incrementa o contador de handles */
    ModelHandle(const ModelHandle& hd) : Handle<ModelBody>(hd) {
        numHandleCreated++;
    }
    /** @brief Destrutor que atualiza o contador global */
    virtual ~ModelHandle() {
        numHandleDeleted++;
    }

    /** @brief Cria um novo System com um valor inicial */
    System* createSystem(double value) override { return pImpl_->createSystem(value); }
    
    /** @brief Executa o modelo no intervalo de tempo especificado */
    void run(double start, double final, int increment) override { 
        pImpl_->run(start, final, increment); 
    }
    
    /** @brief Obtém o iterador para o início dos Systems */
    systemIterator beginSystems() override { return pImpl_->beginSystems(); }
    /** @brief Obtém o iterador para o fim dos Systems */
    systemIterator endSystems() override { return pImpl_->endSystems(); }
    /** @brief Obtém o iterador para o início dos Flows */
    flowIterator beginFlows() override { return pImpl_->beginFlows(); }
    /** @brief Obtém o iterador para o fim dos Flows */
    flowIterator endFlows() override { return pImpl_->endFlows(); }

protected:
    /** @brief Adiciona um System ao modelo */
    void add(System* s) override { pImpl_->add(s); }
    /** @brief Adiciona um Flow ao modelo */
    void add(Flow* f) override { pImpl_->add(f); }
};

#endif