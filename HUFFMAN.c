#include <huffman.h>

 MinHeap* criarMinHeap(int capacidade) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    heap->array = (No**)malloc(heap->capacidade * sizeof(No*));
    return heap;
}

No* novoNo(char caractere, int freq, No* esq, No* dir) {
    No* node = (No*)malloc(sizeof(No));
    node->caractere = caractere;
    node->freq = freq;
    node->esq = esq;
    node->dir = dir;
    return node;
}

void heapify(MinHeap* heap, int i) {
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < heap->tamanho && heap->array[esq]->freq < heap->array[menor]->freq)
        menor = esq;

    if (dir < heap->tamanho && heap->array[dir]->freq < heap->array[menor]->freq)
        menor = dir;

    if (menor != i) {
        trocarNode(&heap->array[i], &heap->array[menor]);
        heapify(heap, menor);
    }
}
