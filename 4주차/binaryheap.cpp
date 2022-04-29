#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

class BinaryHeap {
private:
    const static int MAX_SIZE = 15;
    int heap[MAX_SIZE];
    int size;

public:
    BinaryHeap() {size = 0;} //constructor
    int parent(int i) {return (i) / 2; } //parent node의 index
    int leftChild(int i) {return 2*i;}  //left child의 index
    int rightChild(int i) {return 2*i +1;}  //right child의 index
    void swap(int *x, int *y) {int temp = *x; *x = *y; *y = temp;} //일반적인 swap function

    // insert the item at the appropriate position
    void insert(int data) {
        if (size >= MAX_SIZE) {
            cout<<"The heap is full. Cannot insert"<<endl;
            return;
        }
        heap[++size] = data; // index1부터 넣기 위한 방법. 
        // move up until the heap property satisfies
        int i = size;
        while (i != 1 && heap[parent(i)] < heap[i]) {
            swap(&heap[parent(i)], &heap[i]);
            i = parent(i);
        }
    }

    void maxHeapify(int i){
        // find left child node
        int left = leftChild(i);
        // find right child node
        int right = rightChild(i);
        // find the largest among 3 nodes
        int largest = i;
        // check if the left node is larger than the current node
        if (left <= size && heap[left] > heap[largest]) {
            largest = left;
        }
        // check if the right node is larger than the current node 
        // and left node
        if (right <= size && heap[right] > heap[largest]) {
            largest = right;
        }
        // swap the largest node with the current node 
        // and repeat this process until the current node is larger than 
        // the right and the left node
        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            maxHeapify(largest);
        }

    }
   
  // returns the  maximum item of the heap
  int pop();
};

int main() {
    int ARRAY_SIZE;
    cin>>ARRAY_SIZE; //array size받기
	int arr[ARRAY_SIZE];

	// 랜덤함수를 위한 srand와 seed
	srand(time(NULL));

	// 배열 초기화
	for (int i = 0; i < ARRAY_SIZE; i++) {
		// 1 ~ 50까지의 난수 생성
		arr[i] = rand() % 50 + 1;
	}

	
  BinaryHeap heap; //heap class 선언

	for (int i = 0; i < ARRAY_SIZE; i++) {
		heap.insert(arr[i]);
	}

	// pop 하면서 값들 하나씩 확인
	// Max Heap이기 때문에 값들이 내림차순으로 정렬됨 -> Heap Sort
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout<<" "<<heap.pop();
	}
	printf("\n");

	return 0;
}

int BinaryHeap::pop(){
	// 힙의 가장 첫번째 원소를 반환
	int result = heap[1]; //max 
	// 첫번째 원소를 힙의 가장 끝에 원소와 바꾸고 가장 끝은 이제 쓰지 않을 예정이니 size를 내려준다.
	swap(&heap[1], &heap[size]);
	size--;

	// 아래의 과정은 child를 parent와 비교하면서 알맞은 위치로 하나씩 내리는 부분
	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= size) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}

	while (child <= size && heap[parent] < heap[child]) {
		BinaryHeap::swap(&heap[parent], &heap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= size) {
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}
	}

	return result;
}
