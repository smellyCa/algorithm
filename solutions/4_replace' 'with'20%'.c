#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void replace(char s[],int len){
	int i,spaceNum=0,newLength;
	for(i=0;i<len;i++){
		if(s[i]==' '){
			spaceNum++;
		}
	}
	newLength=len+spaceNum*2;
	s[newLength]='\0';
	for(i=len-1;i>=0;i--){ //倒序遍历字符串
		if(s[i]==' '){
			s[newLength-1]='0';
			s[newLength-2]='2';
			s[newLength-3]='%';
			newLength-=3;
		}
		else{
			s[newLength-1]=s[i];
			newLength-=1;
		}
	}
}

int main(){
	char s[25]="you are a loser.";
	replace(s,16);
	printf("%s\n",s);
}
