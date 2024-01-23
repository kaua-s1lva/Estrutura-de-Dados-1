typedef struct cartas {

  char face[3];
  char naipe[2];
  int valor;
  char nome[30];

} tcarta;

typedef struct no {
  tcarta carta;
  void *prox;
} tno;

tno *CriaLista();
int ListaVazia(tno *lista);
void LiberaLista(tno **lista);
tno *CriaNoLista(tcarta elem);
void InsereNoPosLista(tno **lista, tno *novoNo, int pos);
void InsereElemPosLista(tno **lista, tcarta elem, int pos);
tno *RemovePosLista(tno **lista, int pos);
tno *AcessaPosLista(tno *lista, int pos);
void MudaPosLista(tno **lista, int posOrig, int posDest);
void ImprimeLista(tno *lista);