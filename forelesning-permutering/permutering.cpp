
#include <iostream>

void bytt(int & a1, int & a2){

  int aa = a1;
      a1 = a2;
      a2 = aa;
}

void roterVenstre(int a[]m int i) {

  int x, k;
  x = a[i]
}

void perm(int i) {
  int t; 
  if (i == N - 1)
    display(arr);
  else {
    perm(i + 1);
    
    for(t = i + 1; t < N; t++) {
      bytt(arr[i], arr[t]);

      perm(i + 1);
    }
    roterVenstre(arr, i);
  }
}

// Selection sort
// Insertion sort
// Bubble sort
// Shellsort
// Quicksort
// Heapsort
// Mergesort
