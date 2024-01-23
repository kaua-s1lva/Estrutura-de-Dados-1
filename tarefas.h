typedef struct _nofila {

  int turno;
  int prazo;
  int paus;
  int espadas;
  int ouros;
  int copas;
  int premios;
  void *prox;
  
} tNoTarefa;

typedef struct _fila {

  tNoTarefa *prim;
  tNoTarefa *ult;

} tfila;

tNoTarefa *criaNoFila (tNoTarefa tarefa);
tfila *criaFila();
void insereNoFila(tfila *fila, tNoTarefa *tarefa);
tNoTarefa *removeFila(tfila *fila);
int verificaFilaVazia (tfila *fila);
int tamanhoFila (tfila *fila);
void imprimeNoFila (tNoTarefa *tarefa);