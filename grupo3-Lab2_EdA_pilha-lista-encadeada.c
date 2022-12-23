/*
Laboratório 2 de Estruturas de Dados
Pilha com Lista Encadeada

Eric Ruas Leão - 2110694
Gusthavo Macedo - 2021030
Marina Schuler Martins - 2110075
Wladimir Ramos - 2110104
*/

#include <stdio.h>
#include <stdlib.h>

/*estrutura da pilha*/
struct pilha {
  int info;
  struct pilha* prox;
};
typedef struct pilha Pilha;

Pilha *busca(Pilha * pilha,int val);
Pilha *criaPilha(void);
void liberaPilha(Pilha *pilha);
Pilha* pilha_insere (Pilha* pilha, int val);
Pilha* pilha_retira (Pilha* pilha);
int pilha_vazia (Pilha* pilha);
void imprime_pilha(Pilha *pilha);

/*cria pilha*/
Pilha *criaPilha(void){
  return NULL; 
}

/*libera pilha*/
void liberaPilha(Pilha *pilha){
  Pilha *topo = pilha;
  Pilha *proximo;
  while (topo != NULL) {
    proximo = topo->prox; 
    free(topo); 
    topo = proximo;
  }
}

/*insere na pilha*/
Pilha* pilha_insere (Pilha* pilha, int val){
  Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
  if (novo == NULL){
    printf("Stack overflow\n");
    exit(1);
  }
  novo->info = val;
  novo->prox = pilha;
  return novo;
}

/*retira da pilha*/
Pilha* pilha_retira (Pilha* pilha){
  Pilha* aux;
  aux = pilha;
  if (aux == NULL){ 
    printf("Stack underflow\n");
    exit(1);
  }
  pilha = pilha->prox;
  free(aux);
  return pilha;
}

/*verifica se pilha está vazia*/
int pilha_vazia (Pilha* pilha) {
  return (pilha == NULL);
}

/*exibe a pilha*/
void imprime_pilha(Pilha *pilha){
  Pilha *p;
  for (p = pilha;p != NULL;p = p->prox)
    printf("%d,",p->info);
  printf("\n");
  return;
}

/*busca na pilha*/
Pilha *busca(Pilha * pilha,int val){
  Pilha * aux;
  for ( aux = pilha; aux != NULL; aux = aux->prox)
    if(aux->info == val)
      return aux;
  return NULL;
}

int main(void) {
  Pilha *l = criaPilha();
  Pilha *aux,*aux2;
  if(pilha_vazia(l)){
    printf("A pilha esta vazia\n");
  }
  else 
    printf("A pilha nao esta vazia\n");
  l = pilha_insere (l,1);
  l = pilha_insere (l,2);
  l = pilha_insere (l,3);
  l = pilha_insere (l,4);
  l = pilha_insere (l,5);
  printf("Pilha com todos os elementos:\n");
  imprime_pilha(l);
  l = pilha_retira (l);
  l = pilha_retira (l);
  printf("Pilha com alguns elementos removidos:\n");
  imprime_pilha(l);
  aux = busca(l,2);
  if (aux != NULL)
    printf("Info da busca: %d\n",aux->info);
  else
    printf("Nao achei o elemento :()");

  aux2 = busca(l,5);
  if (aux2 != NULL)
    printf("Info da busca: %d\n",aux2->info);
  else
    printf("Nao achei o elemento :(\n");
  if(pilha_vazia(l)){
    printf("A pilha esta vazia\n");
  }
  else 
    printf("A pilha nao esta vazia\n");
  liberaPilha(l);
  return 0;
}