#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

static const int STATE_NUM = 100;  //Seed: $1~100; Index: 0~99
static const int ACTION_NUM = int(STATE_NUM/2); //Bet: $1~50; Index: 0~49
static const int START_STATE = 29; //Initial Seed: $30; Index: 29
static const int TERMINAL_STATE = STATE_NUM - 1; //Goal: $100; Index: 99
static const int EPISODE_NUM = 100000;
static const int MAX_STEP = 10000;
static const int EPSILON = 1;
static const double GAMMA = 1.0;
static const double ALPHA = 0.01;

//Assign a predetermined winning probability (0~90%) for each state
void prob_assign(int (*arr)) {
    for (int i = 0; i < STATE_NUM-1; i++) {
        arr[i] = + rand() %80; //arr[i] =50;
    }
}

//Assign a large negative Q value to unreachable actions
void Q_assign(double (*table)[ACTION_NUM]) {
    for (int i = 0; i < STATE_NUM; i++) {
        for (int j = 0; j < ACTION_NUM; j++) {
            if (i == TERMINAL_STATE) {
                if (j != 0) {
                    table[i][j] = -999999999999999;
                }
            }
            else {
                if (i < j || TERMINAL_STATE - i < j + 1) {
                    table[i][j] = -999999999999999;
                }
            }
        }
    }
}

//Choose an action from a current state based on an epsilon-greedy policy
int choose_action(int curState, double (*table)[ACTION_NUM]){
    int random_num = rand() %100;
    int maxbet = min(curState + 1, TERMINAL_STATE - curState);
    int action;
    
    if (random_num > EPSILON) {
        action = int(max_element(table[curState], table[curState] + maxbet) - table[curState]);
    }
    else {
        action = int(rand() % maxbet);
    }
    return action;
}

//Find the maximum value of Q reachable from the next state
double maxQ(int curState, double (*table)[ACTION_NUM]){
    int maxbet = min(curState + 1, TERMINAL_STATE - curState);
    double max_q;
    max_q = *max_element(table[curState], table[curState] + maxbet);
    return max_q;
}

//Take the selected action and observe the reward
int take_action(int curState, int action, int (*arr)){
    int random_num = rand() %100;
    int prob = arr[curState];
    int r;
    if (prob > random_num) {
        r = action + 1;
    }
    else {
        r = - (action + 1);
    }
    return r;
}

//Print the final policy
void print_policy(double (*table)[ACTION_NUM], int (*arr)) {
    int pi[STATE_NUM];
    for (int i = 0; i < STATE_NUM - 1; i++) {
        pi[i] = int(max_element(table[i], table[i] + ACTION_NUM) - table[i]);
        cout <<  "Seed : " << i + 1 << "$, Prob : " << arr[i] << "%, Bet : $" << pi[i] + 1 << endl;
    }
}

//Print the final result
void print_result(int (*arr)) {
    int add = 0;
    double result_first;
    double result_best;
    int window = 100;
    double result_arr[EPISODE_NUM - window];
    for (int k = 0; k < EPISODE_NUM - window; k++){
        add = 0;
        for (int i = 0; i < window; i++) {
            add += arr[k + i];
        }
        result_arr[k] = (double) add / (double) window;
    }
    result_first = result_arr[0];
    result_best = *max_element(result_arr, result_arr + EPISODE_NUM - window);
    cout << "First 100 Games = " << result_first << endl;
    cout << "Best 100 Games = " << result_best << endl;
}

int main() {
    //Initialization
    srand(int(time(0)));
    int result[EPISODE_NUM] = {0};
    
    int prob_arr[STATE_NUM-1];
    prob_assign(prob_arr);
    
    double q_table[STATE_NUM][ACTION_NUM] = {0.0};
    Q_assign(q_table);
    
    //Q-Learning algorithm
    for (int i = 0; i < EPISODE_NUM; i++) {
        int curState = START_STATE;
        
        for (int j = 0; j < MAX_STEP; j++) {
            int action = choose_action(curState, q_table);
            int r = take_action(curState, action, prob_arr);
            int q_max = maxQ(curState + r, q_table);
            if (curState + r == TERMINAL_STATE) {
                q_table[curState][action] += ALPHA * ((double) 1.0 + GAMMA * q_max - q_table[curState][action]);
            }
            else {
                q_table[curState][action] += ALPHA * ((double) -1.0 + GAMMA * q_max - q_table[curState][action]);
            }
            curState += r;

            if (curState == TERMINAL_STATE || curState < 0){
                if (curState == TERMINAL_STATE) {
                    result[i] = 1;
                    cout <<  "Episode #: " << i+1 << ", Step #: "<< j+1 << " >> Win" << endl;
                }
                else {
                    cout <<  "Episode #: " << i+1 << ", Step #: "<< j+1 << " >> Lose" << endl;
                }
                break;
            }
        }
    }
    print_policy(q_table, prob_arr);
    print_result(result);
    return 0;
}
