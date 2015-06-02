#include<stdio.h>
#include<stdlib.h>
#include "ListaDEnc.h"

ListaDEnc* criarLista() {
    ListaDEnc* lista = malloc(sizeof(*lista));
    if (lista == NULL)
        return NULL;
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

No* criarNo(int item, No* ant, No* prox) {
	No *no = malloc(sizeof(*no));
	no->item = item;
	no->proximo = prox;
	no->anterior = ant;
	return no;
}

int insereNoInicio(ListaDEnc *lista, int item) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    No *novoNo = criarNo(item, NULL, lista->inicio);
    if (!estahVazia(lista))
        lista->inicio->anterior = novoNo;
    else
        lista->fim = novoNo;
    lista->inicio = novoNo;
    return OK;
}

int insereNoFim(ListaDEnc *lista, int item) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    No *novoNo = criarNo(item, lista->fim, NULL);
    if (!estahVazia(lista))
        lista->fim->proximo = novoNo;
    else
        lista->inicio = novoNo;
    lista->fim = novoNo;
    return OK;
}

int estahVazia(ListaDEnc* lista) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (lista->inicio == NULL) return TRUE;
    else return FALSE;
}

int removeDoInicio(ListaDEnc* lista, int *item) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return ESTRUTURA_VAZIA;
    No* noAux = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    if (lista->inicio == NULL)
        lista->fim = NULL;
    else
        lista->inicio->anterior = NULL;
    if (item != NULL)
        *item = noAux->item;
    free(noAux);
    noAux = NULL;
    return OK;
}

int removeDoFim(ListaDEnc* lista, int *item) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return ESTRUTURA_VAZIA;
    No* noAux = lista->fim;
    lista->fim = lista->fim->anterior;
    if (lista->fim == NULL)
        lista->inicio = NULL;
    else
        lista->fim->proximo = NULL;
    if (item != NULL)
        *item = noAux->item;
    free(noAux);
    noAux = NULL;
    return OK;
}

int liberarLista(ListaDEnc* lista) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;

    // remove todos os elementos da lista
    while(!estahVazia(lista))
        removeDoInicio(lista, NULL);

    free(lista);
    lista = NULL;
    return OK;
}

void imprimir(ListaDEnc* lista) {
    if (lista != NULL) {
        No *aux = lista->inicio;
        while(aux != NULL) {
            printf("%d ", aux->item);
            aux = aux->proximo;
        }
        printf("\n");
    }
}

int incioParaFinal(ListaDEnc* lista){
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return ESTRUTURA_VAZIA;
    int item;
    removeDoInicio(lista,&item);
    insereNoFim(lista,item);
    return OK;
}
