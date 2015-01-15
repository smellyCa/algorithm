//Find the kth to last element of a singly linked list

#include<stdio.h>
#include<stdlib.h>

#define LENGTH 10
#define K 1

typedef struct _list{
	int data;
	struct _list* next;
}Node;

int findTheBottomKth(Node* list,int k){
	int i;
	if(list==NULL){
		return 0;
	}
	i=findTheBottomKth(list->next,k)+1;
	if(i==k){
		printf("%d\n",list->data);
	}
	return i;
}

int main(){
	Node* list=NULL;
	int i;
	int len=0;
	Node* current=list;
	for(i=0;i<LENGTH;i++){
		Node* newNode=(Node*)malloc(sizeof(Node));
		newNode->data=rand()%10;
		newNode->next=list;
		list=newNode;
	}
	findTheBottomKth(list,K);
	return 0;
}