//k번 노드에서 가장 멀리 떨어진 노드의 갯수 구하기
//가장 멀리 떨어진 노드란 최단경로로 이동했을 때 간선의 개수가 가장 많은 노드들을 의미
//노드의 개수 n: 2 이상 20,000 이하
//edge는 양방향, 1개 이상 50,000개 이하
//예시: 노드 간 edge에 대한 vector:[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]가 입력으로 들어감
//bfs 이용

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// make class about bfs
class graph{
  public:
    int node[20000];
    vector<int> v[50000];
    int max_node;
    int node_num;
    void count_node(vector<vector<int>>);
    void bfs(int);
};


void graph::count_node(vector<vector<int>> edge){
    vector<int> unique_vec;
    for(int i=0;i<edge.size();++i){
        for(int j=0;j<edge[i].size();++j){
            unique_vec.push_back(edge[i][j]);
        }
    }
    sort(unique_vec.begin(), unique_vec.end());
    unique_vec.erase(unique(unique_vec.begin(), unique_vec.end()), unique_vec.end());

    node_num = unique_vec.size();
    cout << "node_num: " << node_num << "\n";
}

void graph::bfs(int node_n){
    queue<int> q;
    q.push(node_n);

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int i=0; i<v[cur].size(); i++){
            if((node[v[cur][i]]==0)&&(v[cur][i]!=1)){
                node[v[cur][i]] = node[cur] + 1;
                q.push(v[cur][i]);
                max_node = max(max_node, node[v[cur][i]]);
            } 
        }
    }
    cout << "bfs completed\n";
}

int main(){

    graph g;
    char ch;
    vector<int> input;
    vector<vector<int>> input_vector;
    int k;

    cout << "Please enter the vector - example: if [3, 6], enter 3 then 6(enter between vectors) next-> [4, 3]...\n if you want to end, type #\n";
    cin >> ch;
    int t = 0;
    while(ch !='#'){
        int x = ch - '0';
        cin >> ch;
        input.push_back(x);
        if(t%2==1){
            input_vector.push_back(input);
            vector<int>().swap(input);
        }
        t++;
    }

    for (int i=0; i<input_vector.size(); i++){
        for (int j=0; j<input_vector[i].size(); j++){
            cout << input_vector[i][j] << "; ";
        }
    }

    cout << "input vector's size is: " << input_vector.size() << "\n";

    for(int i=0; i<input_vector.size();i++){
        g.v[input_vector[i][0]].push_back(input_vector[i][1]);
        g.v[input_vector[i][1]].push_back(input_vector[i][0]);
    }

    cout << "Please enter the number of node that you want to search - example: 3\n";
    cin >> k;
    g.bfs(k);

    int answer = 0;
    g.count_node(input_vector);
    for(int i=1; i<=g.node_num;i++){
        if(g.max_node==g.node[i])
            answer++;
    }
    cout << "node's number is : " << sizeof g.node << "\n";
    cout << "answer is :" << answer;
    return answer;
}