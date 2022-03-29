#include <iostream>
using namespace std;

string result;

int main(void) {
    string start;
    do {
        cout << "신속MBTI검사입니다. 질문을 잘 읽어보시고 Y 혹은 N을 입력해주세요. 계속하려면 go를 입력하세요 : ";
        cin >> start;
        }
    while (start != "go");

    cout << "문제가 생겼을 때 당신은 말이 많아지는 편(Y)인가요 생각이 많아지는 편인가요(N)? " << endl;
    string answer1;
    cin >> answer1;
    if (answer1 == "Y" || answer1 == "y")
    result += "E";
    else
    result += "I";

    cout << "문제가 생겼을 때 당신은 '그냥 그런가 보다'라고 생각하는 편인가요(Y) '어떻게 그럴 수 있지'라고 생각하는 편인가요(N)? "<< endl;
    string answer2;
    cin >> answer2;
    if (answer2 == "Y" || answer2 == "y")
    result += "S";
    else
    result += "N";

    cout << "당신은 이해가 안되도 공감을 할 수 있는 편인가요(Y) 이해가 돼야 공감을 하는 편인가요(N)? "<< endl;
    string answer3;
    cin >> answer3;
    if (answer3 == "Y" || answer3 == "y")
    result += "F";
    else
    result += "T";

    cout << "당신은 한다면 하는 편(Y)인가요 뭐부터 할지 고민하는 편인가요(N)? "<< endl;
    string answer4;
    cin >> answer4;
    if (answer4 == "Y" || answer4 == "y")
    result += "J";
    else
    result += "P";

    do {
        cout << "MBTI를 계산 중입니다... 결과를 확인하려면 result를 입력하세요 : ";
        cin >> start;
        }
    while (start != "result"); 

    cout << "당신의 MBTI는 < " << result << " >입니다.";

    return 0;
}
