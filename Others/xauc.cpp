#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;
main() {
  char str[50]="Ha Noi";
  char s1[50]="\0";
  strcat(s1,str);
  strrev(str);
  cout<<str;
  cout<< s1;
  return 0;
}
