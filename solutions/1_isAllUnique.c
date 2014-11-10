#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//return 1 if the string has all unique characters. Otherwise return 0. 
int is_unique(char* s){
	//int* set=malloc(128*sizeof(int));
	int set[128]={0};
	int i;
	int len=strlen(s);
	if(len>128){
		return 0;
	}
	for(i=0;i<len;i++){
		int chr=*(s+i); //get the ascii of current character
		if(*(set+chr)==1){
			return 0;
		}
		else{
			*(set+chr)=1;
		}
	}
	return 1;
}

int main(){
	char* s="abca";
	int isUnique=is_unique(s);
	if(isUnique){
		printf("%s has all unique characters!\n",s);
		return 0;
	}
	else{
		printf("%s does not have all unique characters!\n",s);
		return 0;	
	}
}