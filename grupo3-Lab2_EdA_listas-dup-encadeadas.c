/*
Laboratório 2 de Estruturas de Dados
Lista Duplamente Encadeada

Eric Ruas Leão - 2110694
Gusthavo Macedo - 2021030
Marina Schuler Martins - 2110075
Wladimir Ramos - 2110104
*/
#include <stdio.h>
#include <stdlib.h>

/*estrutura da lista*/
struct lista {
  int info;
  struct lista* ant;
  struct lista* prox;
};

typedef struct lista Lista;

Lista *busca(Lista * lst,int val);
Lista *criaLst(void);
void liberaLst(Lista *lst);
Lista* lst_insere (Lista* lst, int val);
Lista* lst_retira (Lista* lst, int val);
int lst_vazia (Lista* lst);
void imprime_lista(Lista *lst);

/*cria lista*/
Lista *criaLst(void){
  return NULL; 
}

/*libera lista*/
void liberaLst(Lista *lst){
  Lista *topo = lst;
  while (topo != NULL) {
    Lista *proximo = topo->prox; 
    free(topo); 
    topo = proximo;
  }
}

/*insere na lista*/
Lista* lst_insere (Lista* lst, int val){
  Lista* novo = (Lista*) malloc(sizeof(Lista));
  if (novo == NULL){
    printf("Nao foi possivel alocar espaco.\n");
    exit(1);
  }
  novo->info = val;
  novo->prox = lst;
  novo->ant = NULL;
  if (lst != NULL){ 
    lst->ant = novo;
  }
  return novo;
}

/*retira da lista*/
Lista* lst_retira (Lista* lst, int val){
  Lista* p = busca(lst,val); 
  if (p == NULL){ 
    return lst; 
  }if (lst == p){ 
    lst = p->prox;
  }else{ 
    p->ant->prox = p->prox;
  }if (p->prox != NULL) { 
    p->prox->ant = p->ant;
  }
  free(p);
  return lst;
}

/*verifica se lista está vazia*/
int lst_vazia (Lista* lst) {
  return (lst == NULL);
}

/*exibe a lista*/
void imprime_lista(Lista *lst){
  Lista *p;
  for (p = lst;p != NULL;p = p->prox)
    printf("%d,",p->info);
  printf("\n");
  return;
}

/*busca na lista*/
Lista *busca(Lista * lst,int val){
  Lista * aux;
  for ( aux = lst; aux != NULL; aux = aux->prox)
    if(aux->info == val)
      return aux;
  return NULL;
}

int main(void) {
  Lista *l = criaLst();
  Lista *aux,*aux2;
  if(lst_vazia(l)){
    printf("A lista esta vazia\n");
  }
  else 
    printf("A lista nao esta vazia\n");
  l = lst_insere (l,1);
  l = lst_insere (l,2);
  l = lst_insere (l,3);
  l = lst_insere (l,4);
  l = lst_insere (l,5);
  printf("Lista com todos os elementos:\n");
  imprime_lista(l);
  l = lst_retira (l,3);
  l = lst_retira (l,4);
  printf("Lista com alguns elementos removidos:\n");
  imprime_lista(l);
  aux = busca(l,2);
  if (aux != NULL)
    printf("Info da busca: %d\n",aux->info);
  else
    printf("Nao achei o elemento :()");
  aux2 = busca(l,3);
  if (aux2 != NULL)
    printf("Info da busca: %d\n",aux2->info);
  else
    printf("Nao achei o elemento :(\n");
  if(lst_vazia(l)){
    printf("A lista esta vazia\n");
  }
  else 
    printf("A lista nao esta vazia\n");
  liberaLst(l);
  return 0;
}