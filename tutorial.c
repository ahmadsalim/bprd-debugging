#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "trace.h"

#define XUP 100
#define YUP 20
#define YMID (YUP/2)

void plot_sine() {
  char chart[XUP][YUP];
  int ix, iy;
  for (ix = 0; ix < XUP; ix++) {
    for (iy = 0; iy < YUP; iy++) {
      if (ix == 0 && iy == YMID) {
        chart[ix][iy] = '+';
      } else if (ix == 0) {
        chart[ix][iy] = '|';
      } else if (iy == YMID) {
        chart[ix][iy] = '-';
      } else {
        chart[ix][iy] = ' ';
      }
    }
  }
  for (ix = 0; ix < XUP; ix++) {
    int val = floor(sin(ix / 10.0) * 10.0);
    //TRACE_INFO("%d", val);
    chart[ix][val] = 'x';
  }
  for (iy = 0; iy < YUP; iy++) {
    for (ix = 0; ix < XUP; ix++) {
        printf("%c", chart[ix][iy]);
    }
    printf("\n");
  }
}

void swap(int i, int j, int arr[]) {
  int t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
}

//Inspired by pseudocode from https://users.cs.cf.ac.uk/C.L.Mumford/tristan/QuickPage.html
int partition(int p, int r, int arr[]) {
  int i = p;
  int j = r + 1;
  int pivot = arr[p];
  do {
    do i++; while (arr[i] < pivot);
    do j--; while (arr[j] > pivot);
    if (i < j) swap(i, j, arr);
  } while (i < j);
  swap(p, j, arr);
  return j;
}

void quicksort_helper(int p, int r, int arr[]) {
  if (p < r) {
    int q = partition(p, r, arr);
    quicksort_helper(p + 1, q, arr);
    quicksort_helper(q + 1, r, arr);
  }
}


void quicksort(int N, int arr[N]) {
  quicksort_helper(0, N - 1, arr);
}

void print_array(int N, int arr[N]) {
  int i;
  for (i = 0; i < N; i++) {
    if (i != 0) printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
}

typedef struct _node {
  int data;
  struct _node *next;
} node;


node *new_node(int d, node *n) {
  node *nd = malloc(sizeof(node));
  nd->data = d;
  nd->next = n;
  return nd;
}

typedef struct _queue {
  node *front, *back;
} queue;

queue *new_queue() {
  queue *q = malloc(sizeof(queue));
  q->front = NULL;
  q->back  = NULL;
  return q;
}

int is_empty(queue *q) {
  return q->front == NULL;
}

void enqueue(int item, queue *q) {
  node *nd = new_node(item, NULL);
  if (is_empty(q)) {
    q->front = q->back = nd;
  } else {
    q->back->next = nd;
    q->back = q->back->next;
  }
}

int dequeue(queue *q) {
  int d = q->front->data;
  q->front = q->front->next;
  return d;
}

void print_queue(queue *q) {
  if (is_empty(q)) {
    printf("empty");
  } else {
    node *n;
    for (n = q->front; n != NULL; n = n->next) {
      if (n != q->front) {
        printf(",");
      }
      printf("%d", n->data);
    }
  }
  printf("\n");
}

void free_queue(queue *q) {
  node *n, *p;
  for (n = q->front; n != NULL; n = p) {
    p = n->next;
    free(n);
  }
}

void test_qs() {
  int test[] = { 8, 10, 6, 13, 16, 18, 2, 4, 11, 19, 20, 7, 14, 5, 15, 3, 9, 12, 17, 1 };
  print_array(20, test);
  quicksort(20, test);
  print_array(20, test);
}

void test_queue() {
  queue *q = new_queue();
  enqueue(1, q);
  print_queue(q);
  enqueue(2, q);
  print_queue(q);
  enqueue(3, q);
  print_queue(q);
  dequeue(q);
  print_queue(q);
  dequeue(q);  
  print_queue(q);
  enqueue(4, q);
  print_queue(q);
  dequeue(q);
  print_queue(q);
  dequeue(q);
  print_queue(q);
  dequeue(q);
  print_queue(q);
}

int main(int argc, const char *argv[])
{
  plot_sine();
  test_qs();
  test_queue();
  return 0;
}
