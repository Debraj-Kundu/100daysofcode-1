#include <bits/stdc++.h>
using namespace std;


class Node{
  public:
  int data;
  Node* left, *right;
  Node(int val){
    data = val;
    left = right = nullptr;
  }
};

int getHeight(Node* root){
  if(!root){
    return 0;
  }
  return max(getHeight(root->left), getHeight(root->right))+1;
}

void getSum(Node* root, int lv, vector<double>& sumArr, vector<int>& cntArr){
  if(!root){
    return;
  }
  sumArr[lv] += root->data;
  cntArr[lv] += 1;
  getSum(root->left, lv+1, sumArr, cntArr);
  getSum(root->right, lv+1, sumArr, cntArr);
}

vector<double> lvSum(Node* root){
  int h = getHeight(root);
  vector<double> sumArr(h);
  vector<int> cntArr(h);
  getSum(root, 0, sumArr, cntArr);
  for(int i=0; i<h; i++){
    sumArr[i] /= cntArr[i];
  }
  return sumArr;
}

int main(){

  Node* root = new Node(1);
  root->left = new Node(2);root->right = new Node(3);
  root->left->left = new Node(4);root->right->left = new Node(5);
  root->left->right = new Node(5);root->right->right = new Node(6);
  vector<double> ans =  lvSum(root);
  for(auto x: ans){
    cout << x << " ";
  }
  
  return 0;
}