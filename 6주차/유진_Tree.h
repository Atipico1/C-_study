/* Tree를 정의하는 헤더파일. Tree는 해당 노드의 값과 left/right node로의 포인터를 갖고 있다.
다음 블로그의 코드대로 작성됨. <https://hwan-shell.tistory.com/262> */
using namespace std;

class Tree{
    private:
    

    public:
    int node_val;
    Tree *left;
    Tree *right;

    Tree(void);  //Condstructor 
    ~Tree(void);  //Delete
    
    void set_node_val(int num);

    Tree* getLeft();
    Tree* getRight();

    void insert_right(int num);
    void insert_left(int num);

    bool left_Check(void);
    bool right_Check(void); 
    
    // Tree makeTree(string num_list);
    
};
