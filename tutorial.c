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
    quicksort_helper(p, q - 1, arr);
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

int main(int argc, const char *argv[])
{
  int test[] = { 8, 10, 6, 13, 16, 18, 2, 4, 11, 19, 20, 7, 14, 5, 15, 3, 9, 12, 17, 1 };
  print_array(20, test);
  quicksort(20, test);
  print_array(20, test);
  plot_sine();
  return 0;
}
