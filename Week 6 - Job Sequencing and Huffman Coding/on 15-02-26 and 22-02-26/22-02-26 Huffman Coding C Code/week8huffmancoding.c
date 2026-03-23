#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//CH.SC.U4CSE24106 - Week 8 - Huffman Coding

struct node{
	char ch;
	int freq;
	struct node *left,*right;
};

struct node* createnode(char ch,int freq){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->ch=ch;
	temp->freq=freq;
	temp->left=temp->right=NULL;
	return temp;
}

void swapptr(struct node** a,struct node** b){
	struct node* temp=*a;
	*a=*b;
	*b=temp;
}

void sortbyfreq(struct node* arr[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]->freq>arr[j+1]->freq){
				swapptr(&arr[j],&arr[j+1]);
			}
		}
	}
}

void printcodes(struct node* root,int code[],int depth){
	int i;
	if(root->left){
		code[depth]=0;
		printcodes(root->left,code,depth+1);
	}
	if(root->right){
		code[depth]=1;
		printcodes(root->right,code,depth+1);
	}
	if(!root->left && !root->right){
		printf("%c: ",root->ch);
		for(i=0;i<depth;i++) printf("%d",code[i]);
		printf("\n");
	}
}

int main(){
	char str[]="DATAANALYTICSANDINTELLIGENCELABORATORY";
	int freq[256]={0};
	int i;

	for(i=0;str[i];i++) freq[str[i]]++;

	struct node* list[256];
	int count=0;

	for(i=0;i<256;i++){
		if(freq[i]>0){
			list[count++]=createnode(i,freq[i]);
		}
	}

	while(count>1){
		sortbyfreq(list,count);

		struct node* left=list[0];
		struct node* right=list[1];

		struct node* parent=createnode('#',left->freq+right->freq);
		parent->left=left;
		parent->right=right;

		list[0]=parent;
		list[1]=list[count-1];
		count--;
	}

	int code[100];
	printf("huffman codes:\n");
	printcodes(list[0],code,0);

	return 0;
}