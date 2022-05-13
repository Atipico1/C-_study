/*Tree class¸¦ Á¤ÀÇÇÏ´Â cppÆÄÀÏ*/
#include "Tree.h"
#include <queue>

using namespace std;

Tree::Tree(void){   //Initialize
    node_val = 0; 
    left = NULL;  //NULL Pointer
    right = NULL;   //NULL Pointer
}

Tree::~Tree(void){
    delete(right);
    delete(left);
}

void Tree::set_node_val(int num){
    node_val = num;
}

Tree* Tree::getLeft(void){
    return left;
}

Tree* Tree::getRight(void){
    return right;
}

void Tree::insert_left(int num){
    left = new Tree();
    left->set_node_val(num);
}

void Tree::insert_right(int num){
    right = new Tree();
    right->set_node_val(num);
}

bool Tree::left_Check() {
        if (left == NULL) return false;
        else return true;
}

bool Tree::right_Check() {
    if (right == NULL) return false;
    else return true;
}



