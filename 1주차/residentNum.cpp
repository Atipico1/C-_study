#include <string>
#include <stdio.h>

/* <주민번호 입력받아 형태바꿔 출력하기>
이 프로그램은 주민번호(XXXXXX-XXXXXXX)를 인풋으로 받고
1. 성별과 2. 탄생년도, 3.생일을 선택적으로 출력한다.
- 출처: https://codeup.kr/problem.php?id=1020 */

//짝수 홀수 판별기
bool isEven(int val){
    return (val & 1) == 0; //짝수 정수는 가장 우측의 비트가 0이므로 (짝수 정수) & 1 == 0 이 나온다. 
}

int main(){
    int first_half_num = 0;
    int last_half_num = 0;
    printf("주민등록번호를 입력하세요(123456-1234567) : \n");
    scanf("%d-%d", &first_half_num, &last_half_num);
    
    // integer to string //string의 특정 부분만 뽑아내기
    std::string first_half_str = std::to_string(first_half_num);
    std::string last_half_str = std::to_string(last_half_num);

    //bd_year
    int bd_year = std::stoi(first_half_str.substr(0,1));

    //bd_date
    int bd_date = std::stoi(first_half_str.substr(2));
    
    //sex
    int sex_num = last_half_str[0]-'0';
    std::string sex;
    if (isEven(sex_num)){
        sex = "여성";
    }
    else{
        sex = "남성";
    }
    
    //Select answer
    int num = 0;
    printf("탄생 년도는 1, 생일은 2, 성별은 3을 입력하세요 : ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        printf("당신의 탄생 년도는 %d년도 입니다.", bd_year);
        break;
    case 2: 
        printf("당신의 생일은 %d입니다.", bd_date);

    case 3:
        printf("당신의 성별은 %s입니다.", sex);
    default:
        break;
    }

    return 0;
}

