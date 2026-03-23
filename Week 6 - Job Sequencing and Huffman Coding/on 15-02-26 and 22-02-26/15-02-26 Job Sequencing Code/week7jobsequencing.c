#include<stdio.h>
//CH.SC.U4CSE24106 - Job Sequencing 
struct job{
	int id,profit,deadline;
};

void sort(struct job a[],int n){
	int i,j;
	struct job t;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j].profit<a[j+1].profit){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}

int main(){
	int n=14;
	struct job a[14]={
		{1,22,3},{2,19,3},{3,29,8},{4,28,6},{5,30,7},
		{6,21,5},{7,27,10},{8,25,4},{9,24,6},{10,26,12},
		{11,14,13},{12,27,2},{13,19,14},{14,11,1}
	};

	int i,j,maxd=0;
	for(i=0;i<n;i++){
		if(a[i].deadline>maxd) maxd=a[i].deadline;
	}

	sort(a,n);

	int slot[50];
	for(i=0;i<=maxd;i++) slot[i]=-1;

	int profit=0;

	for(i=0;i<n;i++){
		for(j=a[i].deadline;j>=1;j--){
			if(slot[j]==-1){
				slot[j]=a[i].id;
				profit+=a[i].profit;
				break;
			}
		}
	}

	printf("The Job sequence: ");
	for(i=1;i<=maxd;i++){
		if(slot[i]!=-1) printf("j%d ",slot[i]);
	}

	printf("\nmax profit: %d",profit);

	return 0;
}