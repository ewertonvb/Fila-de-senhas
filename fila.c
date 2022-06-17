#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;

  struct node *prox;
};

typedef struct node Node;

int gerar_numero(int *senha){

  if(*senha == 0){
    *senha = 1;
  }else{
    *senha += 1;
  }
  return *senha;
}

void inserir_na_fila(Node **fila, int num){
  Node *aux, *novo = (Node*)malloc(sizeof(Node));

  if (novo){
    novo->info = num;
    novo->prox = NULL;
    if (*fila == NULL){
      *fila = novo;
    }else{
      aux = *fila;
      while (aux->prox)
        aux = aux->prox;
      aux->prox = novo;
    }
  }else{
    printf("Erro ao alocar memória!");
  }
}

void mostrar_senha_atual(Node *fila){
  Node *aux = fila;
  
  if (fila){
    printf("\nSenha atual: %d\n", aux->info);
  }else{
    printf("\nFila vazia\n");
  }
}

Node* remover_da_fila(Node **fila, int *cont){
  Node *remover = NULL;

  if (*fila){
    remover = *fila;
    *fila = remover->prox;
    *cont = *cont + 1;
  }
  return remover;
}

void imprimir_fila(Node *fila){
  Node *aux = fila;
  printf("\nNa fila: ");
  while (aux != NULL){
    printf("%d ", aux->info);
    aux = aux->prox;
  }
}

void consultar_atendimentos(int *cont){
  printf("\nTotal de atendimentos realizados: %d", *cont);
}

int main(){
  Node *fila = NULL;
  int senha = 0;
  int op = 0;
  int cont = 0;
  
  while (op != 5){
    printf("\n\n======= Menu =======\n1 - Gerar senha\n2 - Atender pessoa\n3 - Visualizar fila\n4 - Consultar atendimentos realizados\n5 - Sair\n\n");
    scanf("%d", &op);
    switch(op){
      case 1:
        system("clear");
        gerar_numero(&senha);
        inserir_na_fila(&fila, senha);
      break;
      case 2:
        system("clear");
        mostrar_senha_atual(fila);
        remover_da_fila(&fila, &cont);
        break;
      case 3:
        system("clear");
        imprimir_fila(fila);
        break;
      case 4:
        system("clear");
        consultar_atendimentos(&cont);
        break;
      case 5:
        break;
    }
  }
  return 0;
}
