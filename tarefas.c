#include "tarefas.h"
#include <stdlib.h>
#include <stdio.h>

tNoTarefa *criaNoFila (tNoTarefa tarefa) {
  
  tNoTarefa *no = malloc(sizeof(tNoTarefa));
  
  no->turno = tarefa.turno;
  no->prazo = tarefa.prazo;
  no->paus = tarefa.paus;
  no->espadas = tarefa.espadas;
  no->ouros = tarefa.ouros;
  no->copas = tarefa.copas;
  no->premios = tarefa.premios;

  no->prox = NULL;
  
  return no;
}

tfila *criaFila() {
  
  tfila *fila = malloc(sizeof(tfila));

  fila->prim = NULL;
  fila->ult = NULL;

  return fila;
}

int verificaFilaVazia (tfila *fila) {
  
  if (fila->prim == NULL && fila->ult == NULL) {
    return 1;
  } else {
    return 0;
  }
}

void insereNoFila(tfila *fila, tNoTarefa *tarefa) {
  
  if (verificaFilaVazia(fila)) {
    
    fila->prim = tarefa;
    fila->ult = tarefa;
    
  } else {
    fila->ult = tarefa;
    fila->ult->prox = tarefa;
  }
}

tNoTarefa *removeFila(tfila *fila) {
  
  tNoTarefa *aux = malloc(sizeof(tNoTarefa));
  
  if (verificaFilaVazia(fila)) {
    return NULL;
  
  } else {
    return aux = fila->prim;
    
    if (fila->prim == fila->ult) {
      fila->prim = NULL;
      fila->ult = NULL;
      
    
    } else {
      fila->prim = fila->prim->prox;
      
    }
  }
}

void imprimeNoFila (tNoTarefa *tarefa) {
  
  if (tarefa != NULL) {
    printf("Tarefas: %d(P: %d, E: %d, O: %d, C: %d)", tarefa->turno, tarefa->paus, tarefa->espadas, tarefa->ouros, tarefa->copas);
  }
}