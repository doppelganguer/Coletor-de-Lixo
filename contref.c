#include <stdio.h>
#include <stdlib.h>
#include "contref.h"

void *malloc2(int tamanho){
  heap *aux=malloc(sizeof(heap));
  aux->address=malloc(tamanho);
  aux->cont=1;
  aux->prox=NULL;
  
  
  if(lista==NULL){
    lista=aux;
  } else{
    aux->prox=lista;
    lista=aux;
  }
  return aux->address;
}// Cria os componentes da lista

void atrib2(void* endereco, void* endereco2){
  heap *aux = lista;
  heap *aux2=NULL;
  
 
  while(aux!=NULL){
    if(aux->address==endereco){
      aux->cont = aux->cont - 1;
    
    }else if((aux->address==endereco2)&&(endereco2!=NULL)){
      aux->cont = aux->cont + 1;
    }
    if(aux->cont==0){
      if(aux2==NULL){
        aux2=aux->prox;
        free(aux->address);
        free(aux);
        aux=aux2;
      }else{
        aux2->prox=aux->prox;
        free(aux->address);
        free(aux);
        aux=aux2->prox;
      }
    
    }else{
    aux2=aux;
    aux=aux->prox;  
    }
  }
}//faz a atribuição de endereço na lista e se a lista chegar a zero exclui a lista

void dump(){
  heap *aux=lista;

  while(aux!=NULL){
    printf("Endereço: %p, Contador de referência: %d\n", aux->address, aux->cont);
    aux = aux->prox;
  }
  printf("\n");
}//imprime em tela os dados da lista

