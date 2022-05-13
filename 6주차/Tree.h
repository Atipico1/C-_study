/* Tree�� �����ϴ� �������. Tree�� �ش� ����� ���� left/right node���� �����͸� ���� �ִ�.
���� ��α��� �ڵ��� �ۼ���. <https://hwan-shell.tistory.com/262> */
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
