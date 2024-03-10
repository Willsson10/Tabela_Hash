/*
    Este programa, consiste na implementaçaõ de uma tabala hash. Na qual, será
    utilizado o método de inserção da dobra. A linguagem utilizada será a linguagem C.

    Nele serão implementadas funções de inserção, remoção e busca na tabela hash.
    Também serão implementadas funções para manipular uma lista linkada duplamente
    encadeada.

    Caso não saiba do que se trata uma tabela hash, vá para:
    https://dcm.ffclrp.usp.br/~augusto/teaching/icii/Hash-Tables-Apresentacao.pdf

    O programa irá gerar valores inteiros aleatórios de até n dígitos. Em seguida irá
    remover alguns destes valores da tabela hash.

    Ao final do programa, serão geradas duas saídas .txt, "antes.txt" e "depois.txt".
    "antes.txt" terá a tabela hash antes das remoções. "depois.txt" terá a tabela hash
    depois das remoções.
*/

#include "headers.h"
#include <time.h>

int main () {

    srand(time(NULL));

    FILE* antes = fopen("antes.txt", "w");
    FILE* depois = fopen("depois.txt", "w");

    Lista* tabela[100]; // Tabela hash;
    for (int i=0; i<100; i++) tabela[i] = CreateLst(-1); // Incializando cada lista da tabela.

    int maximo = pow(10, 8); // Definindo valor maximo para valores aleatorios.
    int valores[100]; // Vetor auxiliar, para ter um registro dos valores inseridos.

    // Inserindo valores na tabela hash.
    for (int i=0; i<100; i++) {
        int valor = (rand() % 10000);
        InsereTabela(tabela, valor, 8);
        valores[i] = valor;

    }
    EscreveTabelaTxt(antes, tabela, 100);

    // Removendo valores na tabela hash.
    for (int i=0; i<50; i++) {
        int valor = rand() % 100;
        RemoveTabela(tabela, valores[i], 8);
    }
    EscreveTabelaTxt(depois, tabela, 100);

    KillHash(tabela, 100); // Dando free na tabela hash.

    return 0;
}