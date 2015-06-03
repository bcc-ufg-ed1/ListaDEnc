#include<stdio.h>
#include<stdlib.h>
#include "ListaDEnc.h"

ListaDEnc* criarLista() {
    ListaDEnc* lista = malloc(sizeof(*lista));
    if (lista == NULL)
        return NULL;
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho=0;
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
    lista->tamanho++;
    return OK;
}

int insereNoFim(ListaDEnc *lista, int item) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return insereNoInicio(lista, item);

    No *novoNo = criarNo(item, lista->fim, NULL);
    lista->fim->proximo = novoNo;
    lista->fim = novoNo;
     lista->tamanho++;
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
     lista->tamanho--;
    return OK;
}

int removeDoFim(ListaDEnc* lista, int *item) {
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    if (estahVazia(lista))
        return ESTRUTURA_VAZIA;
    if (lista->inicio == lista->fim)
        return removeDoInicio(lista, item);
    No* noAux = lista->fim;
    lista->fim = lista->fim->anterior;
    lista->fim->proximo = NULL;
    if (item != NULL)
        *item = noAux->item;
    free(noAux);
    noAux = NULL;
     lista->tamanho--;
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

int obterTamanho(ListaDEnc* lista,int* item){
 if (lista == NULL)
 return ESTRUTURA_NAO_INICIALIZADA;
 *item = lista->tamanho;
 return OK;
}
int inserir(ListaDEnc* lista, int item, int pos){
    if (lista == NULL)
        return ESTRUTURA_NAO_INICIALIZADA;
    int tamanho;
    obterTamanho(lista,&tamanho);
    if(pos<0||pos>tamanho)
        return INDICE_INVALIDO;
    if(pos==0){
        insereNoInicio(lista,item);
        return OK;
    }

    if(pos==tamanho){
        insereNoFim(lista,item);
        return OK;
    }
    No* aux=lista->inicio;
    for(int i=0;i<pos;i++){
        aux=aux->proximo;
    }
    No* novoNo = criarNo(item,aux->anterior,aux);
    No* aux2 = aux;
    aux = aux->anterior;
    aux->proximo=novoNo;
    aux2->anterior=novoNo;
    return OK;
}
