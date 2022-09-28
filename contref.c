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
}

void atrib2(void* endereco, void* endereco2){
  heap *aux = lista;
  heap *aux2=NULL;
  
  //falta atribuir endereco=endereco2
 
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
}

void dump(){
  heap *aux=lista;

  while(aux!=NULL){
    printf("Endereço: %p, Contador de referência: %d\n", aux->address, aux->cont);
    aux = aux->prox;
  }
  printf("\n");
}

// void altera(void *endereco,int inc){
//     heap *aux=lista;
//     while(aux!=NULL && aux->end!=endereco){
//         aux=aux->prox;
//     }//percorre a lista até que encontre o endereço
    
//     if(aux!=NULL && aux->end==endereco){
//         aux->cont = aux->cont+inc;
//     }
// }//altera o contador, pra +1 ou -1, recebe o endereço

// void atrib2(void *a,void *b){
//     heap *aux=lista;
//        while(aux!=NULL){
//             if(aux->end==a){
//                 altera(aux->end,-1);
//             }else if(aux->end==b){
//                 altera(aux->end,1);
//             }
//             aux=aux->prox;
//         } 
//     a=b;
// }// varre a lista, atribuição de ponteiros em C

// void dump(){ //varre lista até achar alguem q tenha 0 no contador, se tiver zero da free
//     heap *ant=lista;
//     heap *aux=ant->prox;
//     if(ant->cont==0){ //saber se o primeiro elemento tem contador 0, se sim, libera a memoria
//         lista=aux;
//         free(ant);
//     }else{
//         while(aux!=NULL){
//             if(aux!=NULL && aux->cont==0){
//                 ant->prox=aux->prox; 
//                 free(aux);
//                 //aux=ant->prox;
//             }
//             ant=aux;
//             aux=aux->prox;
//         }
//     }
// }
