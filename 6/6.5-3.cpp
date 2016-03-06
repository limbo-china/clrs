#include <stdio.h>
#include <limits.h>

#define Parent(i) (i/2)
#define LeftChild(i) (2*i)
#define RightChild(i) (2*i+1)
#define ArraySize 10

int a[ArraySize+10];
int HeapSize = ArraySize;

void MIN_HEAPIFY(int *A, int i){
	int smallest,l,r;
	l=LeftChild(i);
	r=RightChild(i);
	if(l<=HeapSize && A[l]<A[i])
		smallest=l;
	else
		smallest=i;
	if(r<=HeapSize && A[r]<A[smallest])
		smallest=r;
	if(smallest!=i){
		int temp=A[i];
		A[i]=A[smallest];
		A[smallest]=temp;
		MIN_HEAPIFY(A,smallest);
	}
}

void BUILD_MIN_HEAP(int *A){
	for(int i=ArraySize/2;i>0;i--)
		MIN_HEAPIFY(A,i);
}

void HEAP_SORT(int *A){
	while(HeapSize>=2){
		int temp=A[HeapSize];
		A[HeapSize]=A[1];
		A[1]=temp;
		HeapSize--;
		MIN_HEAPIFY(A,1);	
	}
}

int HEAP_MINIMUM(int *A){
	return A[1];
}

int HEAP_EXTRACT_MIN(int *A){
	if(HeapSize<1){
		printf("the heap is empty\n");
		return 0;
	}
	int max=A[1];
	A[1]=A[HeapSize];
	HeapSize--;
	MIN_HEAPIFY(A,1);
	return max;
}

void HEAP_DECREASE_KEY(int *A,int i,int key){
	if(key>A[i]){
		printf("new key is not smaller\n");
		return ;
	}
	A[i]=key;
	while(i>1 && A[i]<A[Parent(i)]){
		int temp = A[i];
		A[i]=A[Parent(i)];
		A[Parent(i)]=temp;
		i=Parent(i);
	}
}

void MIN_HEAP_INSERT(int *A,int key){
	HeapSize++;
	A[HeapSize]=INT_MAX;
	HEAP_DECREASE_KEY(A,HeapSize,key);
}

int main(){
	FILE *fp;
	if((fp=fopen("6.5-3_input.txt","r"))==NULL){
		printf("not open!");
		return 0;
	}
	
	for(int i=1;i<=ArraySize;i++)
		fscanf(fp,"%d",&a[i]);
	
	a[0]=INT_MIN;
	
	BUILD_MIN_HEAP(a);
	
	printf("build the heap:\n");
	int n=2;
	for(int i=1;i<=HeapSize;i++){	
		printf("%d ",a[i]);
		if(i>=n-1){
			printf("\n");
			n*=2;
		}
	}
	printf("\n");
	
	MIN_HEAP_INSERT(a,0);
	
	printf("insert a number:\n");
	n=2;
	for(int i=1;i<=HeapSize;i++){	
		printf("%d ",a[i]);
		if(i>=n-1){
			printf("\n");
			n*=2;
		}
	}
	printf("\n");
	
	MIN_HEAP_INSERT(a,50);
	
	printf("insert a number:\n");
	n=2;
	for(int i=1;i<=HeapSize;i++){	
		printf("%d ",a[i]);
		if(i>=n-1){
			printf("\n");
			n*=2;
		}
	}
	printf("\n");
	//HEAP_SORT(a);
	
	//for(int i=1;i<=ArraySize;i++)
	//printf("%d ",a[i]);
	
	return 0;
}
