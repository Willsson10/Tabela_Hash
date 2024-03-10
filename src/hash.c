#include "hash.h"

void InsereTabela (Lista* vetor[], int valor, int tamanhoValor) {

    int posicao = DefinePosicao(valor, tamanhoValor); // Definindo posição no vetor.

    InsertLst(vetor[posicao], valor);
}

void RemoveTabela (Lista* vetor[], int valor, int tamanhoValor) {

    int posicao = DefinePosicao(valor, tamanhoValor); // Definindo posição no vetor.

    RemoveLst(vetor[posicao], valor);
}

int ProcuraValor (Lista* vetor[], int valor, int tamanhoValor) {

    int posicao = DefinePosicao(valor, tamanhoValor); // Definindo posição no vetor.

    return GetValor(vetor[posicao], valor);
}

int DefinePosicao (int valor, int tamanho) {

    if (tamanho == 1) return valor;
    int vetor[tamanho]; // Declaro vetor para armazenar o valor.

    // "Distribuindo" valor pelo vetor.
    int aux = valor;
    for (int i = tamanho - 1; i >= 0; i--) {
        vetor[tamanho - 1 - i] = aux / pow(10, i);
        aux = aux % (int)pow(10, i);
    }

    size_t dobras = tamanho/2 - 1; // Definindo quantas dobras serão realizadas.
    if (dobras > 0) {
        int endereco1 = vetor[0];
        int endereco2 = vetor[1];
        for (int i=0; i<dobras; i++) { // Realizando dobras.
            vetor[3 + (2 * i)] = (endereco1 + vetor[3 + (2 * i)]) % 10;
            vetor[2 + (2 * i)] = (endereco2 + vetor[2 + (2 * i)]) % 10;
            endereco1 = vetor[2 + (2 * i)];
            endereco2 = vetor[3 + (2 * i)];
        }
    }

    return (vetor[tamanho - 2] * 10 + vetor[tamanho - 1]); // Retorna posicao a inserir.
}

void KillHash (Lista* vetor[], int tamanho) {

    for (int i=0; i<tamanho; i++) KillLst(vetor[i]); // Dando free na tabela hash.
}

void EscreveTabelaTxt (FILE* txt, Lista* vetor[], int tamanho) {

    for (int i=0; i<tamanho; i++) {
        fprintf(txt, "%d:\t", i);
        EscreveListaTxt(txt, vetor[i]);
        fprintf(txt, "\n");
    }
}