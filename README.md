# 📦 Huffman Coding em C

Implementação do **Algoritmo de Huffman** em linguagem C.  
O programa permite construir a árvore de Huffman a partir de uma string de entrada, gerar os códigos binários de cada caractere e comprimir o texto.

Este repositório foi organizado de forma modular, separando as funções em arquivos `.h` e `.c` para facilitar a manutenção e compreensão do código.

---

## 🚀 Funcionalidades
- Criação da árvore de Huffman a partir das frequências dos caracteres.
- Geração dos códigos binários para cada caractere.
- Compressão da string original em uma versão codificada.
- Estrutura modular dividida em:
  - `huffman.h` → cabeçalho (structs e protótipos).
  - `huffman.c` → implementação das funções.
  - `main.c` → programa principal.

---

## 🛠️ Estrutura de Arquivos
```
  huffman.h → declarações (Node, MinHeap, protótipos)
  huffman.c → implementação do algoritmo
  main.c → programa principal (entrada e saída)
```
