#include <bits/stdc++.h>
using namespace std;
/**
 * @brief sort stack using recursion
*/


void insertEle(stack<int>& s, int e){
  if(s.empty() || e > s.top()){
    s.push(e);
    return;
  }
  int temp = s.top();
  s.pop();
  insertEle(s, e);
  s.push(temp);
  return;
}
void sortStack(stack<int>& s){
  if(s.empty()){
    return;
  }
  int temp = s.top();
  s.pop();
  sortStack(s);
  insertEle(s, temp);
}

int main() {
	stack<int> s;
  s.push(2);s.push(3);s.push(1);
  s.push(8);s.push(0);
  sortStack(s);
  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
	
	return 0;
}