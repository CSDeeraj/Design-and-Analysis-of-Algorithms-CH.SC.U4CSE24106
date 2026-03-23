//CH.SC.U4CSE24106
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

int partition_last(int a[],int low,int high){
	int pivot=a[high];
	int i=low-1;

	for(int j=low;j<high;j++){
		if(a[j]<pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return i+1;
}

int partition_first(int a[],int low,int high){
	swap(&a[low],&a[high]);
	return partition_last(a,low,high);
}

int partition_random(int a[],int low,int high){
	int r=low+rand()%(high-low+1);
	swap(&a[r],&a[high]);
	return partition_last(a,low,high);
}

void quicksort(int a[],int low,int high,int ch){
	if(low<high){
		int p;
		if(ch==1)
			p=partition_first(a,low,high);
		else if(ch==2)
			p=partition_last(a,low,high);
		else
			p=partition_random(a,low,high);

		quicksort(a,low,p-1,ch);
		quicksort(a,p+1,high,ch);
	}
}

int main(){
	int a[]={157,110,147,122,111,149,151,141,123,112,117,133};
	int n=12;
	int ch;

	srand(time(NULL));

	printf("Original list:\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);

	printf("\n\nChoose pivot type:\n");
	printf("1. First element as pivot\n");
	printf("2. Last element as pivot\n");
	printf("3. Random element as pivot\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);

	quicksort(a,0,n-1,ch);

	printf("\nSorted list:\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);

	printf("\nRoll number: CH.SC.U4CSE24106");

	return 0;
}
