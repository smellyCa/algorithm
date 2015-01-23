//Given two sorted array A and B,
//where A has a large enough buffer at the end to hold B.
//Write a method to merge B into A in sorted order.

#define LENGTH_A 10
#define LENGTH_B 6

#include<stdio.h>
#include<stdlib.h>

//To avoid shifting the existing element everytime we insert
//a element from B to A, we will do this in backward order.

void merge(int a[],int b[],int size_a){
	int size_b=LENGTH_B-1;
	int tail_a=size_a+size_b;
	size_a--;
	while(size_b>=0){
		if(a[size_a]<b[size_b]){
			a[tail_a]=b[size_b];
			size_b--;
		}
		else{
			a[tail_a]=a[size_a];
			size_a--;
		}
		tail_a--;
	}
}

void print_array(int a[]){
	int i=0;
	while(a[i]!='\0'){
		printf("%d ",a[i++]);
	}
	printf("\n");
}

int main(){
	int a[LENGTH_A]={-1,2,4,6,0,0,0,0,0,0};
	int b[LENGTH_B]={1,3,5,7,8,9};
	int size_a=4;

	printf("A: ");
	print_array(a);
	printf("B: ");
	print_array(b);
	
	merge(a,b,size_a);

	printf("A2: ");
	print_array(a);

	return 0;
}

