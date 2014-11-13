#include <stdio.h>
#include <stdlib.h>
#define M 5
#define N 3

void set_to_zero(int a[][N]){
	int row[M];
	int column[N];
	int i,j;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(a[i][j]==0){
				row[i]=1;
				column[j]=1;
			}
		}
	}
	for(i=0;i<M;i++){
		if(row[i]==1){
			for(j=0;j<N;j++){
				a[i][j]=0;
			}
		}
	}
	for(i=0;i<N;i++){
		if(column[i]==1){
			for(j=0;j<M;j++){
				a[j][i]=0;
			}
		}
	}
}
void print(int a[][N]){
	int i,j;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int a[M][N]={2,1,0,3,4,5,1,2,3,4,0,1,2,3,4};
	print(a);
	printf("------------------\n");
	set_to_zero(a);
	print(a);
	return 0;
}
