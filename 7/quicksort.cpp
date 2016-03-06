#include <stdio.h>

#define N 10

int PARTITION(int *A,int p,int r){
	
	int i = p-1;
	for(int j=p;j<r;j++){
		if(A[j]<=A[r]){
			i++;
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	int temp=A[i+1];
	A[i+1]=A[r];
	A[r]=temp;
	
	return i+1;
}

void QUICKSORT(int *A,int p,int r){
	if(p<r){
		int q = PARTITION(A,p,r);
		QUICKSORT(A,p,q-1);
		QUICKSORT(A,q+1,r);
	}
}

int main(){
	int a[N];
	
	FILE *fp;
	if((fp=fopen("quicksort_input.txt","r"))==NULL){
		printf("not open!\n");
		return 0;
	}
	
	for(int i=0;i<N;i++)
		fscanf(fp,"%d",&a[i]);
	
	QUICKSORT(a,0,N-1);
	
	for(int i=0;i<N;i++)
		printf("%d ",a[i]);
}
