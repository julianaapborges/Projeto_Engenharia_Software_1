# Framework de Simulação C++ (Dinâmica de Sistemas)

Repositório criado para a disciplina de Engenharia de Software I (BCC322), do Prof. Tiago Garcia de Senna Carneiro.

## 🚀 Sobre o Projeto

O objetivo deste projeto é projetar, especificar (UML) e implementar uma API (framework) em C++ para a construção de simulações baseadas na **Dinâmica de Sistemas**.

A API permitirá ao Modelador criar "sistemas" (estoques de energia/matéria) e "fluxos" (que transportam essa energia/matéria), permitindo a simulação de Modelos dinâmicos conforme a Teoria Geral de Sistemas. O loop de simulação principal seguirá o algoritmo geral descrito na Figura 5 do trabalho.

### Funcionalidades (Casos de Uso)

O framework será desenvolvido utilizando TDD (Desenvolvimento Orientado por Testes) para implementar os seguintes Modelos de validação:

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

**Gerar a biblioteca compartilhada (DLL):**
```bash
make DLL
```
Gera a biblioteca compartilhada `libmyvensim.so` em `bin/`, utilizada pelos executáveis do projeto.

**Limpar arquivos de build (CLEAN):**
```bash
make CLEAN
```
Remove todos os arquivos gerados em `bin/`, limpando o ambiente de compilação.

**Compilar os testes de validação (TDD):**
```bash
make BUILD_APP
    ou
make BUILD_FUNC_TEST
    ou
make BUILD_UNIT_TEST
```

**Executar os testes (validação dos Modelos):**
```bash
make APP
    ou
make RUN_FUNC_TEST
    ou
make RUN_UNIT_TEST
```

## 📌 Status do Projeto e Versões

A versão atual na branch principal (`master`) reflete a entrega da **Sprint 5**, que é a versão **mais estável e funcional** do framework, com todos os testes passando.

> **💡 Nota sobre a Sprint 6 (Padrão Handle/Body):** > Existe uma branch isolada chamada `sprint6` no repositório. Nela, realizei um experimento de refatoração da arquitetura para aplicar o idioma **Handle/Body** (Padrão Bridge), muito comum em C++ para encapsular a implementação e gerenciar memória. 
> 
> Como essa mudança estrutural profunda acabou comprometendo a estabilidade da lógica de simulação construída anteriormente, decidi não mesclá-la com a `master`. A branch foi mantida propositalmente como um registro valioso de aprendizado prático sobre padrões de projeto e evolução de arquitetura.