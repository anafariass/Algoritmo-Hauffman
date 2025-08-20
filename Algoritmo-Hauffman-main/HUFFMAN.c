#include <huffman.h>
void contarFrequencia(const char *str, int freq[256])
{
    for (int i = 0; i < 256; i++)
        freq[i] = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        freq[(unsigned char)str[i]]++;
    }
}

void trocarNode(No **a, No **b)
{
    No *temp = *a;
    *a = *b;
    *b = temp;
}

No *extrairMin(MinHeap *heap)
{
    No *temp = heap->array[0];
    heap->array[0] = heap->array[heap->tamanho - 1];
    heap->tamanho--;
    heapify(heap, 0);
    return temp;
}

MinHeap *criarMinHeap(int capacidade)
{
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    heap->array = (No **)malloc(heap->capacidade * sizeof(No *));
    return heap;
}

No *novoNo(char caractere, int freq, No *esq, No *dir)
{
    No *node = (No *)malloc(sizeof(No));
    node->caractere = caractere;
    node->freq = freq;
    node->esq = esq;
    node->dir = dir;
    return node;
}

void inserirMinHeap(MinHeap *heap, No *node)
{
    int i = heap->tamanho;
    heap->array[i] = node;
    heap->tamanho++;

    while (i && heap->array[i]->freq < heap->array[(i - 1) / 2]->freq)
    {
        trocarNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify(MinHeap *heap, int i)
{
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < heap->tamanho && heap->array[esq]->freq < heap->array[menor]->freq)
        menor = esq;

    if (dir < heap->tamanho && heap->array[dir]->freq < heap->array[menor]->freq)
        menor = dir;

    if (menor != i)
    {
        trocarNode(&heap->array[i], &heap->array[menor]);
        heapify(heap, menor);
    }
}

No *construirArvoreHuffman(int freq[256])
{
    MinHeap *heap = criarMinHeap(256);
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            inserirMinHeap(heap, novoNo((char)i, freq[i], NULL, NULL));
        }
    }
    while (heap->tamanho > 1)
    {
        No *esq = extrairMin(heap);
        No *dir = extrairMin(heap);
        inserirMinHeap(heap, novoNo('\0', esq->freq + dir->freq, esq, dir));
    }
    No *raiz = extrairMin(heap);
    free(heap->array);
    free(heap);
    return raiz;
}

void gerarCodigos(No *raiz, char *codigo, int profundidade, char codigos[256][256])
{
    if (raiz->esq == NULL && raiz->dir == NULL)
    {
        codigo[profundidade] = '\0';
        strcpy(codigos[(unsigned char)raiz->caractere], codigo);
        return;
    }
    if (raiz->esq)
    {
        codigo[profundidade] = '0';
        gerarCodigos(raiz->esq, codigo, profundidade + 1, codigos);
    }
    if (raiz->dir)
    {
        codigo[profundidade] = '1';
        gerarCodigos(raiz->dir, codigo, profundidade + 1, codigos);
    }
}

void comprimirString(const char *str, char codigos[256][256], char *comprimida)
{
    comprimida[0] = '\0';
    for (int i = 0; str[i] != '\0'; i++)
    {
        strcat(comprimida, codigos[(unsigned char)str[i]]);
    }
}


