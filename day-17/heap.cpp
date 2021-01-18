#include <bits/stdc++.h>
using namespace std;

class Heap{
  int* arr;
  int capacity, heap_size;
  void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  int parent(int child){ return (child-1)/2; }
  int leftChild(int parent){ return (2*parent)+1; }
  int rightChild(int parent){ return (2*parent)+2; }
  void heapify(int i){
    int left = leftChild(i);
    int right = rightChild(i);
    int maxE = i;
    if(left < heap_size && arr[left] > maxE){
      maxE = left;
    }
    if(right < heap_size && arr[right] > maxE){
      maxE = right;
    }
    if(maxE != i){
      swap(&arr[maxE], &arr[i]);
      heapify(maxE);
    }
  }
  
public:
  Heap(int sz){
    heap_size = 0;
    capacity = sz;
    arr = new int[capacity];   
  }

  void insertItem(int val){
    if(heap_size == capacity)
      return;
    heap_size++;
    int i = heap_size-1;
    arr[i] = val;
    while(i>0 && arr[parent(i)] < arr[i]){
      swap(&arr[parent(i)], &arr[i]);
      i = parent(i);
    }
  }

  int getMax(){
    if(heap_size==0)
      return -1;
    if(heap_size==1){
      heap_size--;
      return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[--heap_size];
    heapify(0);
    return root;
  }

};

int main(){

  Heap h(10);;
  h.insertItem(1000);h.insertItem(1);
  h.insertItem(20);h.insertItem(100);
  h.insertItem(15);
  cout << h.getMax();

  return 0;
}