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

int main(){

  Node* root = new Node(1);
  root->left = new Node(2);root->right = new Node(3);
  root->left->left = new Node(4);root->right->left = new Node(5);
  root->left->right = new Node(5);root->right->right = new Node(6);
  /* vector<int> ans =  maxLvSum(root);
  cout << ans[0] << " " << ans[1]; */
  
  return 0;
}