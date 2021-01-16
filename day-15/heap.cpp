#include <bits/stdc++.h>
using namespace std;

class Heap{
  void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  int heap_size, capacity, *arr;
public:
  Heap(int cap){
    heap_size = 0;
    capacity = cap;
    arr = new int[capacity];
  }
  int parent(int child){ return (child-1)/2; }
  int leftChild(int parent){ return (2*parent)+1; }
  int rightChild(int parent){ return (2*parent)+2; }

  void insertItem(int val){
    if(heap_size == capacity){
      return;
    }
    heap_size++;
    int i = heap_size - 1;
    arr[i] = val;
    while(i != 0 && arr[parent(i)] > arr[i]){
      swap(&arr[parent(i)], &arr[i]);
      i = parent(i);
    }
  }
  void decreasePtr(int i, int val){
    arr[0] = val;
    while(i != 0 && arr[parent(i)] > arr[i]){
      swap(&arr[parent(i)], &arr[i]);
      i = parent(i);
    }
  }
  int deleteItem(int key){
    decreasePtr(key, INT_MIN);
    getMin();
  }
  int getMin(){
    if(heap_size == 0){
      return -1;
    }
    if(heap_size == 1){
      heap_size--;
      return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    heapify(0);
    return root;
  }
  void heapify(int i){
    int left = leftChild(i);
    int right = rightChild(i);
    int min = i;
    if(left < heap_size && arr[left] < arr[min]){
      min = left;
    }
    if(right < heap_size && arr[right] < arr[min]){
      min = right;
    }
    if(min != i){
      swap(&arr[min], &arr[i]);
      heapify(min);
    }
  }
};

int main(){

  Heap h(10);
  
  h.insertItem(10);h.insertItem(20);
  h.insertItem(1);h.insertItem(100);
  h.insertItem(5);h.insertItem(-5);
  cout << h.getMin();
  cout << '\n';
  priority_queue<int> pq;//max_heap
  pq.push(10);pq.push(20);
  pq.push(1);pq.push(100);
  pq.push(5);pq.push(-5);
  cout << pq.top();


  return 0;
}