#include <stdio.h>
#include "baralho.h"
//#include "tarefas.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

void calculaRecurso (tno *descarte, int tamanho, int *paus, int *ouros, int *espadas, int *copas) {
  int i;
  tno *no[6];

  for (i=1; i<=tamanho; i++) {
    no[i] = AcessaPosLista(descarte, i);
  }

  for (i=1; i<=tamanho; i++) {
    if (no[i]->carta.naipe[0] == 'P') {
      *paus = *paus + no[i]->carta.valor;
    } else if (no[i]->carta.naipe[0] == 'C') {
      *copas = *copas + no[i]->carta.valor;
    } else if (no[i]->carta.naipe[0] == 'O') {
      *ouros = *ouros + no[i]->carta.valor;
    } else if (no[i]->carta.naipe[0] == 'E') {
      *espadas = *espadas + no[i]->carta.valor;
    }
  }

}

int calculaPar (tno *par, int tamanho) {

  int valorPar=0;
  tno *no1, *no2;

  no1 = AcessaPosLista(par, 1);
  no2 = AcessaPosLista(par, 2);

  if (tamanho == 2 && (no1->carta.valor == no2->carta.valor)) {
    return valorPar = 2;
  } else {
    return valorPar;
  }
}

int calculaTrinca (tno *trinca, int tamanho) {

  int valorTrinca=0;
  tno *no1, *no2, *no3;

  no1 = AcessaPosLista(trinca, 1);
  no2 = AcessaPosLista(trinca, 2);
  no3 = AcessaPosLista(trinca, 3);

  if (tamanho == 3 && (no1->carta.valor == no2->carta.valor) && (no2->carta.valor == no3->carta.valor)) {
    return valorTrinca = 5;
  } else {
    return valorTrinca;
  }

}

int calculaQuadra (tno *quadra, int tamanho) {

  int valorQuadra=0;
  tno *no1, *no2, *no3, *no4;

  no1 = AcessaPosLista(quadra, 1);
  no2 = AcessaPosLista(quadra, 2);
  no3 = AcessaPosLista(quadra, 3);
  no4 = AcessaPosLista(quadra, 4);

  if (tamanho == 4 && (no1->carta.valor == no2->carta.valor) && (no2->carta.valor == no3->carta.valor) && (no3->carta.valor == no4->carta.valor)) {
    return valorQuadra = 20;

  } else {
    return valorQuadra;
  }
}

int calculaSequencia (tno *sequencia, int tamanho) {

  int i, verificador=0;
  tno *no[5];

  for (i=1; i<=tamanho; i++) {
    no[i] = AcessaPosLista(sequencia, i);
  }

  for (i=1; i<tamanho; i++) {
    if (no[i]->carta.valor == no[i+1]->carta.valor + 1) {
      verificador+=0;
    } else {
      verificador+=1;
    }
  }

  if (verificador == 0) {
    return 2*tamanho;
  } else {
    return 0;
  }
}

int calculaMesmoNaipe (tno *mesmoNaipe, int tamanho) {

  int i, verificador=0;
  tno *no[5];

  for (i=1; i<=tamanho; i++) {
    no[i] = AcessaPosLista(mesmoNaipe, i);
  }

  for (i=1; i<tamanho; i++) {
    if ( strcmp(no[i]->carta.naipe, no[i+1]->carta.naipe) == 0 ) {
      verificador+=0;
    } else {
      verificador+=1;
    }
  }

  if (verificador == 0) {
    return 3*tamanho;
  } else {
    return 0;
  }
}

int calculaBonus (tno *bonus, int numCartasDescarte) {
  
  int valorBonus;
  valorBonus = calculaPar(bonus, numCartasDescarte) + calculaTrinca(bonus, numCartasDescarte) + calculaQuadra(bonus, numCartasDescarte) + calculaSequencia(bonus, numCartasDescarte) + calculaMesmoNaipe(bonus, numCartasDescarte);
  return valorBonus;
  
}

/*
**
    main
**
*/


int main(void) {

  //variáveis
  int i, numeroSorteado, numeroCartas = 52, numEscolhido, origem, destino, numCartasDescarte=0, valorBonus=0;
  int paus=0, ouros=0, espadas=0, copas=0;

  //declaração da lista
  tno *lista, *mao, *noSolto, *bonus;
  tcarta cartas[52];

  //declaração da fila
  //tNoTarefa tarefas[10];
  //tfila *fila;

  //abrindo arquivos
  FILE *arquivo = fopen("/baralho1.dat", "r");
  FILE *arquivoTarefas = fopen("/tarefas.dat", "r");

  //verificação de arquivos
  if (arquivo == NULL || arquivoTarefas == NULL) {
    printf("Erro ao abrir arquivos");
    return 0;
  }

  //função srand para o rand
  srand(time(NULL));

  //lendo arquivo do baralho
  for (i=0; i<52; i++) {
    fscanf(arquivo, "%s %s %d %[^\n]s", cartas[i].face, cartas[i].naipe, &cartas[i].valor, cartas[i].nome);
  }

  //lendo arquivo de tarefas
  //O PROBLEMA ESTÁ AQUI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  /*
  for (i=0; i<10; i++) {
    fscanf(arquivoTarefas, "%d %d %d %d %d %d %d", &tarefas[i].turno, &tarefas[i].prazo, &tarefas[i].paus, &tarefas[i].espadas, &tarefas[i].ouros, &tarefas[i].copas, &tarefas[i].premios);
  }
  */
  //definindo listas
  lista = CriaLista();
  mao = CriaLista();

  //definindo filas
  //fila = criaFila();

  //inserindo elementos na lista
  for (i=0; i<52; i++) {
    InsereElemPosLista(&lista, cartas[i], i+1);
  }

  //inserindo elementos na fila
  /*
  for (i=0; i<10; i++) {
    insereNoFila(fila, &tarefas[i]);
  }
*/
  //sortear cartas
  for (i=1; i<6; i++) {
    numeroSorteado = (rand() % numeroCartas) + 1;

    noSolto = RemovePosLista(&lista, numeroSorteado);
    InsereNoPosLista(&mao, noSolto, i);

    numeroCartas--;
  }

  do {
    printf("\n----------MENU-----------\n\n");
    printf("\nP: %d - O: %d - S: %d - C: %d\n\n", paus, ouros, espadas, copas);
    //imprimeNoFila(fila->prim);
    ImprimeLista(mao);
    printf("---------Bonus: %d\n\n", valorBonus);
    printf("Digite uma das opções abaixo: \n1 - Reposicionar carta \n2 - Descartar cartas \n3 - Cumprir tarefa \n4 - Finalizar turno \n5 - Sair \n");
    scanf("%d", &numEscolhido);

    switch (numEscolhido) {
      case 1:
        //reposicionar carta
        
        printf("Digite a posição da carta que deseja reposicionar: \n");
        scanf("%d", &origem);

        printf("Digite a posição da carta que deseja ser colocado: \n");
        scanf("%d", &destino);

        MudaPosLista(&mao, origem, destino);
        
      break;
      case 2:
        //descartar carta

        printf("Digite quantas cartas quer descartar: ");
        scanf("%d", &numCartasDescarte);
        printf("teste");

        if (numCartasDescarte > 5 || numCartasDescarte < 0) {
          printf("\nQuantidade inválida!\n");
          printf("teste");
          break;
        }

        for (i=0; i<numCartasDescarte; i++) {
          noSolto = RemovePosLista(&mao, 1);
          InsereNoPosLista(&bonus, noSolto, i);
        }
        calculaRecurso(bonus, numCartasDescarte, &paus, &ouros, &espadas, &copas);
        valorBonus = calculaBonus(bonus, numCartasDescarte);

      break;
      case 3:
        //cumprir tarefa

        

      break;
      default:
        printf("Opção inválida!");
      break;

    }

    

  } while (numEscolhido != 5);

  return 0;
}