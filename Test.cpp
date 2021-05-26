#include "doctest.h"
#include "sources/BinaryTree.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("check add root"){
  // check "int tree"
  BinaryTree<int> tree;

    CHECK_NOTHROW(tree.add_root(0));
    for (int i = 0; i <= 15; i++)
      {
          CHECK_NOTHROW(tree.add_root(i));
          CHECK_EQ(i,  *tree.begin_preorder());
          CHECK_EQ(i,  *tree.end_preorder());
      }
       CHECK_NOTHROW(tree.add_root(1).add_root(2).add_root(3));

      // check "char tree"
      BinaryTree<char> tree2;
      CHECK_NOTHROW(tree2.add_root('0'));

      for (int i = 0; i <= 12; i++)
      {
          CHECK_NOTHROW(tree2.add_root((char)i));
          char c = i;
          CHECK_EQ(c,  *tree2.begin_preorder());
          CHECK_EQ(c,  *tree2.end_preorder());
      }

}

TEST_CASE("check add left and add right child"){
  BinaryTree<int> tree;

  // can't adding without root
  CHECK_THROWS(tree.add_left(0,1));
  CHECK_THROWS(tree.add_right(0,1));
  CHECK_NOTHROW(tree.add_root(0));

  for (size_t i = 1; i <= 10; i++) {
  CHECK_NOTHROW(tree.add_left(i-1,i));
  }
}

// -----------------------postorder : left--> right--> root--------------------
  TEST_CASE("check postorder "){
    BinaryTree<int> tree;

  tree.add_root(1)
  .add_left(1, 9)      // Now 9 is the left child of 1
  .add_left(9, 4)      // Now 4 is the left child of 9
  .add_right(9, 5)     // Now 5 is the right child of 9
  .add_right(1, 3)     // Now 3 is the right child of 1
  .add_left(1, 2);

  int i=0;
  for (auto it=tree.begin_postorder(); it!=tree.end_postorder(); ++it) {
    if(i==0){
        CHECK_EQ((*it),  4);}
    if(i==1){
        CHECK_EQ((*it),  5);}
    if(i==2){
        CHECK_EQ((*it),  2);}
    if(i==3){
        CHECK_EQ((*it),  3);}
    if(i==4){
        CHECK_EQ((*it),  1);}
    i++;

  }  // prints: 4 5 2 3 1
}

// ---------------------preorder : root--> left--> right-------------------
TEST_CASE("check preorder"){
  BinaryTree<int> tree;
  tree.add_root(1)
  .add_left(1, 9)      // Now 9 is the left child of 1
  .add_left(9, 4)      // Now 4 is the left child of 9
  .add_right(9, 5)     // Now 5 is the right child of 9
  .add_right(1, 3)     // Now 3 is the right child of 1
  .add_left(1, 2);
    
int i=0;
  for (auto it=tree.begin_preorder(); it!=tree.end_preorder(); ++it) {
    if(i==0){
        CHECK_EQ((*it),  1);}
    if(i==1){
        CHECK_EQ((*it),  2);}
    if(i==2){
        CHECK_EQ((*it),  4);}
    if(i==3){
        CHECK_EQ((*it),  5);}
    if(i==4){
        CHECK_EQ((*it),  3);}
    i++;
  }
  // prints: 1 2 4 5 3
  }


// -------------------inorder : left-->  root--> right---------------------
  TEST_CASE("check inorder "){
    BinaryTree<int> tree;

  tree.add_root(1)
  .add_left(1, 9)      // Now 9 is the left child of 1
  .add_left(9, 4)      // Now 4 is the left child of 9
  .add_right(9, 5)     // Now 5 is the right child of 9
  .add_right(1, 3)     // Now 3 is the right child of 1
  .add_left(1, 2);

  int i=0;
  for (auto it=tree.begin_inorder(); it!=tree.end_inorder(); ++it) {
    if(i==0){
        CHECK_EQ((*it),  4);}
    if(i==1){
        CHECK_EQ((*it),  2);}
    if(i==2){
        CHECK_EQ((*it),  5);}
    if(i==3){
        CHECK_EQ((*it),  1);}
    if(i==4){
        CHECK_EQ((*it),  3);}
    i++;

  }  // prints: 4 2 5 1 3
}



