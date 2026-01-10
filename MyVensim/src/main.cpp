#include <iostream>
#include <cassert>
#include "../src/lib/model_handle.hpp"
#include "../src/lib/system_handle.hpp"
#include "../src/lib/flow_handle.hpp"

using namespace std;

// --- ALOCAÇÃO DAS VARIÁVEIS GLOBAIS ---
int numHandleCreated = 0;
int numHandleDeleted = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;

int main() {
    cout << "--- Teste Handle/Body ---" << endl;

    // Reset para garantir
    numHandleCreated = 0; numHandleDeleted = 0;
    numBodyCreated = 0; numBodyDeleted = 0;

    {
        // 1. Cria ModelHandle (Handle++ Body++)
        ModelHandle m; 
        
        // 2. Cria SystemHandle via Factory (Handle++ Body++)
        System* s1 = m.createSystem(100.0);
        
        // 3. Cópia de Handle (Handle++ Body mantido)
        SystemHandle s2 = *(dynamic_cast<SystemHandle*>(s1)); 
        
        // Verifica se estão compartilhando o mesmo Body
        s1->setValue(50.0);
        cout << "Valor s2 (deve ser 50): " << s2.getValue() << endl;
    } 
    // Fim do escopo: Destrutores chamados

    cout << "Handles Criados: " << numHandleCreated << endl;
    cout << "Handles Deletados: " << numHandleDeleted << endl;
    cout << "Bodies Criados: " << numBodyCreated << endl;
    cout << "Bodies Deletados: " << numBodyDeleted << endl;

    if (numHandleCreated == numHandleDeleted && numBodyCreated == numBodyDeleted) {
        cout << ">> SUCESSO: Sem vazamento de memória." << endl;
    } else {
        cout << ">> FALHA: Contagem incorreta." << endl;
    }

    return 0;
}