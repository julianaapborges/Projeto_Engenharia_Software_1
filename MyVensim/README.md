# Framework de Simulação C++ (Dinâmica de Sistemas)

Repositório criado para a disciplina de Engenharia de Software I (BCC322), do Prof. Tiago Garcia de Senna Carneiro.

## 🚀 Sobre o Projeto

O objetivo deste projeto é projetar, especificar (UML) e implementar uma API (framework) em C++ para a construção de simulações baseadas na **Dinâmica de Sistemas**.

A API permitirá ao modelador criar "sistemas" (estoques de energia/matéria) e "fluxos" (que transportam essa energia/matéria), permitindo a simulação de modelos dinâmicos conforme a Teoria Geral de Sistemas. O loop de simulação principal seguirá o algoritmo geral descrito na Figura 5 do trabalho.

### Funcionalidades (Casos de Uso)

O framework será desenvolvido utilizando TDD (Desenvolvimento Orientado por Testes) para implementar os seguintes modelos de validação:

* **Modelo 1:** Crescimento Populacional Exponencial 
* **Modelo 2:** Crescimento Populacional Logístico 
* **Modelo 3:** Crescimento Populacional Complexo

## 📁 Estrutura de Diretórios
```
├── src/ # Código fonte (.cpp, .hpp) 
├── include/ # Arquivos de header (se separados) 
├── bin/ # Binários compilados (ignorados pelo .gitignore) 
├── test/ # Códigos de teste (TDD) 
├── doc/ # Documentação 
├── .gitignore # Arquivos ignorados pelo Git 
├── Makefile # Arquivo de compilação 
└── readme.md # Este arquivo
```

## 🛠️ Como Compilar

**Compilar o programa principal (Exemplo de uso):**
```bash
make

**Compilar os testes de validação (TDD):**
```bash
make test
    ou
make func
    ou
make unit

**Executar os testes (validação dos modelos):**
```bash
./bin/testeRegressivo.exe
    ou
./bin/testeFuncional.exe
    ou
./bin/testeUnitario.exe