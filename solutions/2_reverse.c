#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//reverse a null-terminated string. 
char* reverse_string(char* s){
	char* start=s;
	char* end=s;
	char temp;
	while(*end!='\0'){
		end++;
	}
	end--;
	while(start<end){
		temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
	return s;
}

int main(){
	char s[]="asdf"; //如果用char* s会报错，因为这样的话s指向的是字符串常量，存放常量的空间不和普通的一样，它有专门的空间，并且这些空间是只读，不能写。
	char* newString=reverse_string(s);
	printf("%s\n",newString);
}