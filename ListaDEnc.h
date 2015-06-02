#define TRUE 1
#define FALSE 0

#define OK 1
#define ESTRUTURA_NAO_INICIALIZADA -1
#define ESTRUTURA_VAZIA -2

typedef struct {
  int item;
  struct No* proximo;
  struct No* anterior;
} No;

typedef struct {
  No* inicio;
  No* fim;
} ListaDEnc;

ListaDEnc* criarLista();
int insereNoInicio(ListaDEnc *lista, int item);
int insereNoFim(ListaDEnc *lista, int item);
int estahVazia(ListaDEnc *lista);
int removeDoInicio(ListaDEnc* lista, int *item);
int removeDoFim(ListaDEnc* lista, int *item);
int liberarLista(ListaDEnc* lista);
void imprimir(ListaDEnc* lista);
