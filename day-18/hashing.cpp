#include <bits/stdc++.h>
using namespace std;

class Hash{
  int bucket;
  list<int> *map;
public:
  Hash(int val){
    bucket = val;
    map = new list<int>[bucket];
  }
  void insertItem(int val){
    int i = hashFn(val);
    map[i].push_back(val);
  }
  void deleteItem(int val){
    int key = hashFn(val);
    list<int>::iterator i;
    for(i = map[key].begin(); i!=map[key].end(); i++){
      if(*i == val)
        break;
    }
    if(i != map[key].end()){
      map[key].erase(i);
    }
  }
  int hashFn(int x){
    return x%bucket;
  }
  void showTable(){
    for(int i=0; i<bucket; i++){
      cout << i << "-->";
      for(auto x:map[i]){
        cout << x << "->";
      }
      cout<<'\n';
    }
  }
};

int birthdateProb(double p){
  return ceil(sqrt(2*365*log(1/(1-p)))); 
}

int main(){
  
  /*int a[] = {15, 11, 27, 8, 12}; 
  int n = sizeof(a)/sizeof(a[0]); 
  Hash h(7);
  for (int i = 0; i < n; i++)  
    h.insertItem(a[i]);   
  h.deleteItem(12); 
  h.showTable(); 
*/
  cout << birthdateProb(0.5);

  return 0;
}