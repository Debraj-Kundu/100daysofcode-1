#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left, *right;
  Node(int val){
    data = val;
    left = right = nullptr;
  }
  int printAnc(Node* root, Node* node){
    if(root == nullptr)
      return 0;
    if(root->left == node || root->right == node || printAnc(root->left, node) || printAnc(root->right, node)){
      cout << root->data << " ";
      return 1;
    }
    //cout << node->data;
    return 0;
  }
};


int main(){

  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);//70
  root->left->right = new Node(5);//80
  root->right->left = new Node(6);//100
  root->right->right = new Node(7);
  root->printAnc(root, root->right->right);

  return 0;
}