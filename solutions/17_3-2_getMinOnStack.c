//Design a stack which, has function push pop and min
//All three functions operate in O(1) time

#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

typedef struct _stackNode{
	int data;
	struct _stackNode* next;
}Node;

typedef struct _minStack{
	Node* stack;
	int min;
	int size;
}MinStack;

typedef struct _stack{
	Node* stack;
	MinStack* minStack;
	int size;

}Stack;

Stack* createStack();
MinStack* createMinStack();
void push(Stack* s,int data);
void pushToMinStack(MinStack* s,int data);
int pop(Stack* s);
void popFromMinStack(MinStack* s,int popedData);
int getMin(Stack* s);
void printStack(Stack* s);

Stack* createStack(){
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->stack=NULL;
	s->size=0;
	s->minStack=createMinStack();
	return s;
}

MinStack* createMinStack(){
	MinStack* s=(MinStack*)malloc(sizeof(Stack));
	s->stack=NULL;
	s->min=INT_MAX;
	s->size=0;
	return s;
}

void push(Stack* s,int data){	
	Node* newNode=(Node*)malloc(sizeof(Node));
	//printf("Pushing %d\n",data);
	newNode->data=data;
	newNode->next=s->stack;
	s->stack=newNode;
	s->size++;

	pushToMinStack(s->minStack,data);
}

void pushToMinStack(MinStack* s,int data){
	if(data<s->min){
		Node* newNode=(Node*)malloc(sizeof(Node));
		//printf("Pushing to minStack: %d\n",data);
		newNode->data=data;
		newNode->next=s->stack;
		s->stack=newNode;
		s->size++;
		s->min=data;
	}
}

int pop(Stack* s){
	Node* temp=s->stack;
	int data=temp->data;
	
	//printf("Popping %d\n",data);
	s->stack=s->stack->next;
	free(temp);
	s->size--;
	popFromMinStack(s->minStack,data);
	return data;
}

void popFromMinStack(MinStack* s,int popedData){
	if(popedData==s->min){
		Node* temp=s->stack;	
		//printf("Popping from minStack: %d\n",popedData);
		s->stack=s->stack->next;
		free(temp);
		s->size--;
		s->min=s->stack->data;
	}
}

int getMin(Stack* s){
	int min=s->minStack->min;
	printf("Min element is: %d\n\n",min);
	return min;
}

void printStack(Stack* s){
	Node* head=s->stack;
	printf("-------------\n");
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
	printf("-------------\n");
}

int main(){
	Stack* stack=createStack();
	push(stack,4);
	printStack(stack);
	getMin(stack);
	
	push(stack,2);
	printStack(stack);
	getMin(stack);

	push(stack,7);
	printStack(stack);
	getMin(stack);

	push(stack,1);
	printStack(stack);
	getMin(stack);

	push(stack,3);
	printStack(stack);
	getMin(stack);

	pop(stack);
	printStack(stack);
	getMin(stack);

	pop(stack);
	printStack(stack);
	getMin(stack);

	pop(stack);
	printStack(stack);
	getMin(stack);

	pop(stack);
	printStack(stack);
	getMin(stack);

	printf("\n");
	return 0;
}
