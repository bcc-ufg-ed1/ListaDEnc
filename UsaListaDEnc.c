#include<stdio.h>
#include<stdlib.h>
#include "ListaDEnc.h"

int main() {
    ListaDEnc* minhaLista = criarLista();
    insereNoFim(minhaLista, 6);
    insereNoFim(minhaLista, 7);
    insereNoFim(minhaLista, 8);
    insereNoInicio(minhaLista, 9);
    insereNoInicio(minhaLista, 10);
    insereNoInicio(minhaLista, 11);

    /*removeDoInicio(minhaLista, NULL);
    imprimir(minhaLista);
    removeDoFim(minhaLista, NULL);
    imprimir(minhaLista);*/
    int tam;
    remover(minhaLista,&tam,1);
    imprimir(minhaLista);
    //obterTamanho(minhaLista,&tam);
    //printf("Tamanho: %d\n",tam);
    return EXIT_SUCCESS;
}
