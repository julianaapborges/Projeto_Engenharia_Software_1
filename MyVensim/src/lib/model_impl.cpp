#include "model_handle.hpp"
#include "model_body.hpp"

// --- Implementação da Fábrica Estática ---
Model* Model::createModel() {
    return new ModelHandle();
}

// --- Implementação Lógica do ModelBody::run ---
void ModelBody::run(double start, double final, int increment) {
    std::vector<double> results;
    
    for (m_time = start; m_time < final; m_time += increment) {
        results.resize(m_flows.size());
        
        // 1. Calcula equações
        int i = 0;
        for(auto f : m_flows) {
            results[i] = f->equation();
            i++;
        }

        // 2. Atualiza sistemas
        i = 0;
        for(auto f : m_flows) {
            System* source = f->getSource();
            System* target = f->getTarget();
            
            if(source) source->setValue(source->getValue() - results[i]);
            if(target) target->setValue(target->getValue() + results[i]);
            
            i++;
        }
    }
}