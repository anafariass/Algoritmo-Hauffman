#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char caractere;       
    int freq;             
    struct No *esq, *dir;
} No;

typedef struct MinHeap {
    int tamanho;   
    int capacidade;
    No** array;  
} MinHeap;


No* novoNo(char caractere, int freq, No* esq, No* dir);

MinHeap* criarMinHeap(int capacidade);

void trocarNo(No** a, No** b);

void heapify(MinHeap* heap, int i);

int tamanhoUm(MinHeap* heap);

No* extrairMin(MinHeap* heap);

void inserirMinHeap(MinHeap* heap, No* no);

void construirMinHeap(MinHeap* heap);

No* construirHuffman(char data[], int freq[], int tamanho);

void gerarCodigos(No* raiz, int arr[], int topo);

#endif
