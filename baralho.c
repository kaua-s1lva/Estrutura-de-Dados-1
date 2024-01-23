#include "baralho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tno *CriaLista() {
  tno *carta = NULL;
  return carta;
}

int ListaVazia(tno *carta) {
  if (carta == NULL)
    return 1;
  else
    return 0;
}

void LiberaLista(tno **carta) {
  tno *aux;
  while (!ListaVazia(*carta)) {
    aux = (*carta)->prox;
    free(*carta);
    (*carta) = aux;
  }
}

tno *CriaNoLista(tcarta elem) {
  tno *novo = malloc(sizeof(tno));

  strcpy(novo->carta.face, elem.face);
  strcpy(novo->carta.naipe, elem.naipe);
  novo->carta.valor = elem.valor;
  strcpy(novo->carta.nome, elem.nome);

  novo->prox = NULL;
  return novo;
}

void InsereNoPosLista(tno **lista, tno *novoNo, int pos){
  int i=1;
  tno *aux, **aux2;

  aux2 = lista;
  while(i < pos && (*aux2) != NULL){
    aux2 = (tno**) &((*aux2)->prox);
    i++;
  }
  aux = novoNo;
  aux->prox = (*aux2);
  (*aux2) = aux;
}

void InsereElemPosLista(tno **lista, tcarta elem, int pos) {
  InsereNoPosLista(lista, CriaNoLista(elem), pos);
}

tno *RemovePosLista(tno **lista, int pos){
  int i;
  tno *aux, *aux2;
  aux = (*lista);
  if(pos == 1){
    (*lista) = aux->prox;
    aux->prox = NULL;
    return aux;
  } else{
    for(i=1; i<pos-1;i++) aux = aux->prox;
    aux2 = aux->prox;
    aux->prox = aux2->prox;
    aux2->prox = NULL;
    return aux2;
  }
}

int AcessaElemLista(tcarta **lista, int elem){
  return 0;
}

tno *AcessaPosLista(tno *lista, int pos){
  int i;
  tno *aux = lista;
  for(i=0; i<pos-1;i++) aux = aux->prox;
  return aux;
}

void MudaPosLista(tno **lista, int posOrig, int posDest){
  tno *aux = RemovePosLista(lista, posOrig);
  InsereNoPosLista(lista, aux, posDest);
}

void ImprimeLista(tno *lista) {
  tno *aux = lista;
  printf("\n\n");
  while (!ListaVazia(aux)) {
    printf("%s %s %d %s \n", aux->carta.face, aux->carta.naipe, aux->carta.valor, aux->carta.nome);
    aux = aux->prox;
  }
  printf("\n\n\n");
}