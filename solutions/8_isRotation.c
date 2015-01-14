#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isSubstring(char* s1,char* s2){
	int len1=strlen(s1);
	int len2=strlen(s2);
	int i;
	for(i=0;i<len1-len2;i++){
		if(*(s1+i)==*s2){
			int j;
			for(j=0;j<len2;j++){
				if(*(s1+i+j)!=*(s2+j)){
					break;
				}
			}
			if(j==len2){
				return 1;
			}
		}
	}
	return 0;
}

int isRotation(char* s1,char* s2){
	if(strlen(s1)==strlen(s2)){
		char* s1s1=(char*)malloc(2*strlen(s1)*sizeof(char));
		int i=0;
		while(i++<2){
			int len=strlen(s1);
			int j;
			for(j=0;j<len;j++){
				*(s1s1+j+(i-1)*len)=*(s1+j);
			}
		}
		return isSubstring(s1s1,s2);
	}
	return 0;
}

int main(){
	char* s1="waterbottle";
	char* s2="erbottlewat";

	if(isRotation(s1,s2)){
		printf("%s is a rotation of %s\n",s2,s1);
	}
	else{
		printf("%s is not a rotation of %s\n",s2,s1);
	}
}