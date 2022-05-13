/*Tree.h���� ������ Tree class�� Tree instance�� ������ cpp����. 
Tree�� Ư���� ���� ���� �Էµ� ������� ���������.*/
#include "Tree.h"
#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream> //endl
using namespace std;

int main(void){
    vector<int> input_vector = {1,2,3,4,5,6,7,8}; //tree�� ���� node_val  //�ش� ���� input���� ���� �� ������?
    queue<Tree*> tree_element; //�۾���: �Է� ������� �۾��ϱ� ���� queue
    queue<int> element_que; //�����: node_val�� ���� queue

    Tree* tree = new Tree(); // Tree instance
    cout << "Initial tree node_val: " << tree->node_val <<endl;

    for (auto n: input_vector)
        element_que.emplace(n); //queue.emplace : push�� ����� ����

    tree_element.emplace(tree);

    while (!tree_element.empty()) {  //input_order�� ���� node�� ���� ������
        //current node
        Tree* curNode = tree_element.front();
        tree_element.pop(); //C++�� pop�� ���� ��ȯ���� �ʰ� ������ �Ѵ�.
        
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