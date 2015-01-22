//Implement a MyQueue class which
//implements a queue using two stacks

#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
	int data;
	struct _node* next;
}Node;

typedef struct _stack{
	Node* head;
}Stack;

typedef struct _queue{
	Stack* stack;
	Stack* queue;
}Queue;

Stack* createStack(){
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->head=NULL;
	return s;
}

void push(Stack* s,int data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	//newNode->next=s->head==NULL?NULL:s->head;
	if(s->head==NULL){
		newNode->next=NULL;
	}
	else{
		newNode->next=s->head;
	}
	s->head=newNode;
}

void pop(Stack* s){
	Node* head=s->head;
	s->head=s->head->next;
	free(head);
}

Queue* createQueue(){
	Queue* q=(Queue*)malloc(sizeof(Queue));
	q->stack=createStack();
	q->queue=createStack();
	return q;
}

void reverse(Queue* q){
	if(q->queue->head==NULL){
		Node* current=q->stack->head;
		while(current!=NULL){
			push(q->queue,current->data);
			current=current->next;
		}
	}
}

void enqueue(Queue* q,int data){
	push(q->stack,data);
}

void dequeue(Queue* q){
	reverse(q);
	pop(q->queue);
}
int peek(Queue* q){
	reverse(q);
	return q->queue->head->data;
}

void printNode(Node* n){
	Node* current=n;
	while(current!=NULL){
		printf("%d ",current->data);
		current=current->next;
	}
	printf("\n");
}

void printQueue(Queue* q){
	if(q->queue->head!=NULL){
		printf("Queue: ");
		printNode(q->queue->head);
	}
	else{
		printf("Stack: ");
		printNode(q->stack->head);
	}
}

int main(){
	Queue* q=createQueue();
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	enqueue(q,4);
	enqueue(q,5);
	printQueue(q);

	dequeue(q);
	printQueue(q);	
	dequeue(q);
	printQueue(q);	
	dequeue(q);
	printQueue(q);

	return 0;
}