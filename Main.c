#include <stdio.h>
#include "huffman.h"

int main() {
    char str[1024]; 
    printf("Digite a string a ser comprimida: ");
    fgets(str, sizeof(str), stdin);

    int len = 0;
    while (str[len] != '\0') len++;
    if (str[len - 1] == '\n') str[len - 1] = '\0';

    int freq[256];
    contarFrequencia(str, freq);

    No *raiz = construirArvoreHuffman(freq);

    char codigos[256][256]; 
    char codigoTemp[256];   
    gerarCodigos(raiz, codigoTemp, 0, codigos);

    printf("\nCódigos de Huffman:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' : %s\n", i, codigos[i]);
        }
    }

    char comprimida[8192]; 
    comprimirString(str, codigos, comprimida);

    printf("\nString original: %s\n", str);
    printf("String comprimida: %s\n", comprimida);

    return 0;
}
