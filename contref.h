#ifndef _CONTREF_H
#define _CONTREF_H

typedef struct heap{
  void* address;
  int cont;
  struct heap *prox;
}heap;

heap *lista = NULL;

void *malloc2(int tamanho);

void atrib2(void* endereco, void* endereco2);

void dump();

#endif