#include <iostream>
#include <cstring>
using namespace std;
char *clip(char *);

int main()
{
	char s1[20];
    //cin>>s1;
	strcpy(s1, "Hello World      ");
	cout << "before |" << s1 << "|" << endl;
	clip(s1);
	cout << "after |" << s1 << "|" << endl;
	return 1;
}

//function : removes string trailing blanks
char *clip(char *str)
{
  char *p;
  int len = strlen(str);

  //point to last char of string
  p = &str[len-1];

  //loop backward, look for non-blank char
  while(*p == ' ')
   --p;
  ++p;

  //null string
  *p = '\0';
  return str;
}
