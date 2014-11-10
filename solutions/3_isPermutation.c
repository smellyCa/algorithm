#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isPermutation(char* s1,char* s2);
char* quicksort(char* s,int low,int high);

//Decide if a string is a permutation of the other string. 
int isPermutation(char* s1,char* s2){
	int len=strlen(s1);
	char* newS1=quicksort(s1,0,len-1);
	char* newS2=quicksort(s2,0,len-1);

	if(len!=(int)strlen(s2)){
		return 0;
	}
	
	if(strcmp(newS1,newS2)!=0){
		return 0;
	}
	return 1;
}

char* quicksort(char* s,int low,int high){
	//int mid=(low+high)/2;
	if(low<high){
		char key=*(s+low);
		char temp;
		int i;
		int bound=low;
		for(i=low+1;i<=high;i++){
			if(*(s+i)<=key){
				temp=*(s+(++bound));
				*(s+bound)=*(s+i);
				*(s+i)=temp;
			}
		}
		temp=*(s+low);
		*(s+low)=*(s+bound);
		*(s+bound)=temp;

		quicksort(s,low,bound);
		quicksort(s,bound+1,high);
	}
	return s;
}

int main(){
	char s1[]="dsfhiua";
	char s2[]="fsuacih";
	int is=isPermutation(s1,s2);
	if(is==1){
		printf("%s is a permutation of %s\n",s1,s2);
	}
	else{
		printf("%s is NOT a permutation of %s\n",s1,s2);
	}
}