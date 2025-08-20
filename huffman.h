#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
  char caractere;
  int freq;
  struct No *esq, *dir;
} No;

typedef struct MinHeap
{
  int tamanho;
  int capacidade;
  No **array;
} MinHeap;

void contarFrequencia(const char *str, int freq[256]);
void trocarNode(No **a, No **b);
No *extrairMin(MinHeap *heap);
MinHeap *criarMinHeap(int capacidade);
No *novoNo(char caractere, int freq, No *esq, No *dir);
void inserirMinHeap(MinHeap *heap, No *node);
void heapify(MinHeap *heap, int i);
No *construirArvoreHuffman(int freq[256]);
void gerarCodigos(No *raiz, char *codigo, int profundidade, char codigos[256][256]);
void comprimirString(const char *str, char codigos[256][256], char *comprimida);

#endif 
