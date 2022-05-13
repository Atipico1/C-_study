/*Tree.h에서 정의한 Tree class로 Tree instance를 만들어보는 cpp파일. 
Tree는 특별한 조건 없이 입력된 순서대로 만들어진다.*/
#include "Tree.h"
#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream> //endl
using namespace std;

int main(void){
    vector<int> input_vector = {1,2,3,4,5,6,7,8}; //tree로 만들 node_val  //해당 값을 input으로 받을 순 없을까?
    queue<Tree*> tree_element; //작업용: 입력 순서대로 작업하기 위한 queue
    queue<int> element_que; //저장용: node_val을 담을 queue

    Tree* tree = new Tree(); // Tree instance
    cout << "Initial tree node_val: " << tree->node_val <<endl;

    for (auto n: input_vector)
        element_que.emplace(n); //queue.emplace : push와 결과가 동일

    tree_element.emplace(tree);

    while (!tree_element.empty()) {  //input_order에 남은 node가 없을 때까지
        //current node
        Tree* curNode = tree_element.front();
        tree_element.pop(); //C++의 pop은 값을 반환하지 않고 삭제만 한다.
        
        int left, right;

        //left node
        left = element_que.front();
        element_que.pop();

        curNode->insert_left(left);
        tree_element.emplace(curNode->getLeft());
        if (element_que.empty()) 
            break;

        //right node
        right = element_que.front();
        element_que.pop();

        curNode->insert_right(right);
        tree_element.emplace(curNode->getRight());
    }

    //print tree
    cout << "Print start" <<endl;
    queue<Tree*>().swap(tree_element);

    tree_element.emplace(tree);
    while (!tree_element.empty()){
        
        Tree* curNode = tree_element.front();
        tree_element.pop();

        cout << curNode->getLeft()->node_val << " ";
        if (curNode -> getLeft()->left_Check())
            tree_element.emplace(curNode->getLeft());
        
        cout << curNode->getRight()->node_val << " ";
        if (curNode -> getRight()->right_Check())
            tree_element.emplace(curNode->getRight());
    }
    
    return 0;
}