/*
   Módulo onde são implementadas funções para manipulação de uma lista linkada
   duplamente encadeada.

   Possui funções de inicialização, inserção, remocão, procura e escrita.
   Além de possuir a estrutura da lista.
*/

#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct node {
   int valor;
   struct node* prox;
   struct node* ant;
} Node;

typedef struct lista {
   int tamanho;
   int quantidade;
   Node* pri;
   Node* ult;
} Lista;

/*
   Função a qual inicializa e retorna uma lista.
*/
Lista* CreateLst (int tamanho);

/*
   Função a qual insere um valor int "valor" em uma
   lista "lista".
*/
void InsertLst (Lista* lista, int valor);

/*
   Função a qual remove um valor int "valor" de uma
   lista "lista".
*/
void RemoveLst (Lista* lista, int valor);

/*
   Função a qual retorna um valor existente na lista "lista".
   Caso o valor não esteja na lista, retorna -1.
*/
int GetValor (Lista* lista, int valor);

/*
   Função a qual da free em uma lista.
*/
void KillLst (Lista* lista);

/*
   Função a qual escreve no terminal, os elemntos de uma lista "lista".
*/
void EscreveLista (Lista* lista);

/*
   Função a qual escreve em um arquivo .txt, os elementos de uma lista "lista".
*/
void EscreveListaTxt (FILE* txt, Lista* lista);

#endif