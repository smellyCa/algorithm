//Use a single array to implement three stacks

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 30

int array[ARRAY_SIZE];
int stackTop[3]={-1,-1,-1};

int push(int stackNum,int data){
	int index=stackTop[stackNum]+1;
	//Initialize stack top pointer
	if(index==0){
		stackTop[stackNum]=(ARRAY_SIZE/3)*stackNum-1;
		index=stackTop[stackNum]+1;
	}
	//check full stack
	if(array[index]=='|'){
		return 0;
	}
	//push
	array[index]=data;
	stackTop[stackNum]++;
	return 1;
}

void pop(int stackNum){
	int index=stackTop[stackNum];
	array[index]=0;
	stackTop[stackNum]--;
}

int main(){
	int i;
	//set stack tail
	array[ARRAY_SIZE/3-1]='|';
	array[(ARRAY_SIZE*2)/3-1]='|';
	array[ARRAY_SIZE-1]='|';

	push(0,1);
	push(0,2);
	push(0,3);

	push(1,4);
	push(1,5);
	push(1,6);

	push(2,7);
	push(2,8);
	
	pop(0);
	pop(1);
	pop(2);

	for(i=0;i<ARRAY_SIZE;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
}
