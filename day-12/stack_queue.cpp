#include <bits/stdc++.h>
using namespace std;

class Stack{
  int *arr;
  int sp;
  int size;
public:
  Stack(int size){
    sp=-1;
    this->size = size;
    arr = new int[size];
    memset(arr, 0, size);
  }
  void push(int val){
    if(sp == size-1){
      return;
    }
    sp++;
    arr[sp] = val;
  }
  void pop(){
    if(sp == -1){
      return;
    }
    sp--;
  }
  int top(){
    if(sp == -1){
      return -1;
    }
    return arr[sp];
  }
};

class Queue{
  int *arr;
  int front, rear;
  int size;
public:
  Queue(int size){
    front = -1;rear = -1;
    this->size = size;
    arr = new int[size];
  }
  bool isEmpty(){
    if(front== -1 && rear == -1)
      return true;
    return false;
  }
  bool isFull(){
    if((rear+1)%size == front)
      return true;
    return false;
  }
  void enque(int val){
    if(isFull()){
      return;
    } else if(isEmpty()){
      front = rear= 0;
    } else{
      rear = (rear+1)%size;
    }
    arr[rear] = val;
  }
  void deque(){
    if(isEmpty()){
      return;
    } else if(front == rear){
      front = rear = -1;
    } else{
      front = (front+1)%size;
    }
  }
  int showfront(){
    if(front != -1)
      return arr[front];
    return -1;
  }
};

int main(){
  
  Stack s1(10);
  s1.push(10);s1.push(20);
  cout << "\ntop: " << s1.top();
  s1.push(30);s1.push(40);
  cout << "\ntop: " << s1.top();
  s1.pop();
  cout << "\ntop: " << s1.top();
  cout << "\n--------------------------------";
  Queue q1(10);
  q1.enque(10);q1.enque(20);
  cout << "\nfront: " << q1.showfront();
  q1.deque();q1.deque();
  cout << "\nfront: " << q1.showfront();
  //min stack
  stack<pair<int, int>> minStack;
  int item = 5;
  int minEle = minStack.empty() ? item : min(item, minStack.top().second);
  minStack.push(make_pair(item , minEle));
  int item2 = 20;
  minEle = minStack.empty() ? item2 : min(item2, minStack.top().second);
  minStack.push(make_pair(item2 , minEle));
  int item3 = 15;
  minEle = minStack.empty() ? item3 : min(item3, minStack.top().second);
  minStack.push(make_pair(item3 , minEle));
  cout << "\nstack top: " << minStack.top().first << " min ele: " 
  << minStack.top().second;
  //

  
  
  return 0;
}