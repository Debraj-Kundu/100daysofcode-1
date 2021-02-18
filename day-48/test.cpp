#include <bits/stdc++.h>
using namespace std;

int fun(int a, int b){
  return a+b;
}

bool cmp(int a, int b){
  if(a<b) return true;
  return false;
}

void mysort(int* arr, bool (*cmp)(int, int)){
  for(int i=0; i<5; i++){
    for(int j=i+1; j<5; j++){
      if(cmp(arr[i],arr[j])){
        swap(arr[i], arr[j]);
      }
    }
  }
}

int main(){

  int (*p)(int, int) = fun;//function pointers
  //cout << p(3,4);
  int arr[5] = {5, 1, 2, 8, 9};
  mysort(arr, cmp);
  for(auto x:arr)
    cout << x << " ";

  return 0;
}