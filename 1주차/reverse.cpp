//for 문을 사용하여 reverse string 출력

#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;

void Reverse(char c[], int n)
{
    stack<char> s;//stack은 LIFO
    for(int i=0; i<n; ++i)
    {
        s.push(c[i]);
    }
    
    for(int i=0; i<n; ++i)
    {
        c[i] = s.top();//stack의 마지막 데이터를 반환
        s.pop();//stack의 마지막 데이터를 삭제
    }
}

int main() {
    char c[20];
    printf("Enter a string: ");
    gets(c);//위에서 입력한 문자열을 받아 \n기준으로 char c[]에 저장
    Reverse(c, strlen(c));//위의 Reverse 실행
    printf("output : %s\n", c);
    return 0;
    
}