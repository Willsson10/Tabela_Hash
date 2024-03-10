/*
    Módulo onde são implementadas funções para manipular uma tabela hash.

    Possui funções de inserção, remoção e procura. Além de uma função auxiliar
    para definir o método de inserção.
*/

#ifndef _HASH_H
#define _HASH_H

#include "lista.h"

/*
    Função a qual insere um valor int "valor", o qual possui no máximo
    "tamanhoValor" dígitos, em uma tabela hash "vetor". Utiliza o método de dobra
    para inserção.
*/
void InsereTabela (Lista* vetor[], int valor, int tamanhoValor);

/*
    Função a qual remove um valor int "valor", o qual possui no máximo
    "tamanhoValor" dígitos, de uma tabela hash "vetor".
*/
void RemoveTabela (Lista* vetor[], int valor, int tamanhoValor);

/*
    Função a qual retorna um valor int "valor", em uma tabela hash
    "vetor". Caso encontre, retorna o valor. Caso contrário, retorna
    -1.
*/
int ProcuraValor (Lista* vetor[], int valor, int tamanhoValor);

/*
    Retorna o endereco de um vetor, no qual, será inserido
    o valor "valor".
*/
int DefinePosicao (int valor, int tamanho);

/*
    Função a qual da free em uma tabela hash.
*/
void KillHash (Lista* vetor[], int tamanho);

/*
    Função a qual escreve em um arquivo .txt, os elementos de uma tabela hash "vetor".
*/
void EscreveTabelaTxt (FILE* txt, Lista* vetor[], int tamanho);

#endif