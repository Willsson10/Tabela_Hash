#include "lista.h"

Lista* CreateLst (int tamanho) {

    Lista* lista = malloc(sizeof(Lista)); // Alocando memória para uma nova lista.

    // Inicializando valores da lista.
    lista->pri = NULL;
    lista->ult = NULL;
    lista->quantidade = 0;
    lista->tamanho = tamanho;
    return lista;
}

void InsertLst (Lista* lista, int valor) {

    Node* novo = malloc(sizeof(Node)); // Alocando memória para um novo node da lista.

    novo->prox = NULL;
    novo->valor = valor;

    if (lista->quantidade == 0) lista->pri = novo;
    else lista->ult->prox = novo;

    novo->ant = lista->ult;
    lista->ult = novo;
    lista->quantidade++; // Incrementado a quantidade de elementos.
}

void RemoveLst (Lista* lista, int valor) {

    if (lista->quantidade == 0) return; // Caso a lista esteja vazia.

    Node* node = lista->pri;

    while (node->valor != valor) {
        node = node->prox;
        if (node == NULL) return;
    }

    if (lista->quantidade == 1) {
        lista->pri = NULL;
        lista->ult = NULL;
    }
    else if (lista->pri->valor == node->valor) {
        lista->pri = node->prox;
        lista->pri->ant = NULL;
        node->prox = NULL;
    }
    else if (lista->ult->valor == node->valor) {
        node->ant->prox = NULL;
        lista->ult = node->ant;
    }
    else {
        node->ant->prox = node->prox;
        node->prox->ant = node->ant;
    }

    lista->quantidade--; // Decrementa a quantidade de elementos.
    free(node); // Dando free no node.
}

int GetValor (Lista* lista, int valor) {

    Node* aux = lista->pri;

    // Procura o valor;
    while (aux->valor != valor) {
        aux = aux->prox;
        if (aux == NULL) return -1;
    }

    return aux->valor;
}

void KillLst (Lista* lista) {

    if (lista->quantidade == 0) return; // Caso a lista esteja vazia.

    Node* aux = lista->pri;
    Node* aux2 = aux->prox;

    // Percorre a lista, removendo os elementos.
    for (int i=0; i<lista->quantidade; i++) {
        RemoveLst(lista, GetValor(lista, aux->valor));
        aux = aux2;
        if (aux == NULL) return;
        aux2 = aux2->prox;
    }
}

void EscreveLista (Lista* lista) {

    if (lista->quantidade == 0) return; // Caso a lista esteja vazia.

    Node* aux = lista->pri;

    while (aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

void EscreveListaTxt (FILE* txt, Lista* lista) {

    if (lista->quantidade == 0) return; // Caso a lista esteja vazia.

    Node* aux = lista->pri;

    while (aux != NULL) {
        fprintf(txt, "%d, ", aux->valor);
        aux = aux->prox;
    }
}