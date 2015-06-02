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
    incioParaFinal(minhaLista);
    imprimir(minhaLista);
    removeDoInicio(minhaLista, NULL);
    imprimir(minhaLista);
    removeDoFim(minhaLista, NULL);
    imprimir(minhaLista);
    return EXIT_SUCCESS;
}
