#pragma once
#include <iostream>
#include <set>
using namespace std;

namespace ariel {

template<typename T>
class BinaryTree {

//init type name iterator
using iterator = typename set<T>::iterator;

// node init
struct Node {
        T key;
        Node* left;
        Node* right;
        Node(T k) : key(k), right(nullptr), left(nullptr){}
};

private:
  Node* root;
  set<T> list;
public:
  BinaryTree<T>() : root(nullptr){ }

  BinaryTree<T>& add_root(T k){
          root= new Node(k);
          return *this; }

  BinaryTree<T>& add_left(T parent, T child){return *this;}

  BinaryTree<T>& add_right(T parent, T child){return *this;}

  iterator begin_preorder() {return list.end();}

  iterator end_preorder() {return list.end();}

  iterator begin_inorder() {return list.end();}

  iterator end_inorder() {return list.end();}

  iterator begin_postorder(){return list.end();}

  iterator end_postorder(){return list.end();}

  iterator begin(){return list.end();}

  iterator end(){return list.end();
  }
  friend ostream& operator<<(ostream& os,const BinaryTree<T>& binaryTree){
          return os; }
};
}
