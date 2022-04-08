//두 단어를 입력 받아 같은 알파벳이 있는지 비교 
#include <stdio.h>
#include <string.h>

int main() {
    char s1[30]=" ";
    char s2[30]=" ";
    int len1=0, len2 = 0;
    int max_len = 0;
    char* ps1, * ps2;
 
    scanf("%s", s1);//입력받는 단어1
    scanf("%s", s2);//입력받는 단어2
     len1 = strlen(s1);
    len2 = strlen(s2);
    
    if (len1 > len2) max_len = len1;
    else max_len = len2;
 
    ps1 = s1;
    ps2 = s2;
    int i = 0;
 
    for (i=0; i < max_len; i++) { //두개 비교 시작
 
        if (*(ps1+i) == *(ps2+i)) printf("O"); //같은면 o
        else printf("X"); //다르면 x 출력
    }
        return 0;
 
}
