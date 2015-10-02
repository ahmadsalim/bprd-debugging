#include <stdio.h>
#include <stdlib.h>
#include "trace.h"

typedef struct _list {
  int head;
  struct _list *tail;
} list;

list *nil() { return NULL; }

list *cons(int head, list *tail) {
  list *this = malloc(sizeof(list));
  this->head = head;
  this->tail = tail;
  return this;
}

int is_nil(list *l)  { return !l; }
int is_cons(list *l) { return !!l;  }

list *nats(int max) {
 if (max <= 0) {
   return nil();
 } else {
    int i;
    list *res;
    for (i = 0; i < max; i++) {
      res = cons(i + 1, res);
    }
    return res;
 }
}

void print_list(list *l) {
  do {
    printf("%d :: ", l->head);
    l = l->tail;
  } while(is_cons(l));
  printf("nil");
}

void free_list(list *l) {
  while (is_cons(l)) {
    free(l);
    l = l->tail;
  }
}

int main(int argc, const char *argv[])
{
  list *l = nats(10);
  print_list(l);
  free_list(l);
  return EXIT_SUCCESS;
}
