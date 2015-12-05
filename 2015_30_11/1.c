#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int val;
	struct node *nxt;
}NODE;

NODE* create(NODE*,int);
void display(NODE*);
float median(NODE*);

main(){
	int n,s,i;
	NODE* head=NULL;
	
	printf("Enter no.of nodes:-");
	scanf("%d",&s);
	
	printf("Enter node values:-\n");
	for(i=0;i<s;i++){
		scanf("%d",&n);
		head=create(head,n);
	}
	
	display(head);
	
	printf("\nMedian:%f",median(head));
}

NODE* create(NODE* head,int n){
	NODE *cur,*temp;
	
	if(head==NULL){
		head=(NODE*)malloc(sizeof(NODE*));
		head->val=n;
		head->nxt=NULL;
	}
	else{
		cur=head;
		while(cur->nxt!=NULL)
			cur=cur->nxt;
		temp=(NODE*)malloc(sizeof(NODE*));
		temp->val=n;
		temp->nxt=NULL;
		cur->nxt=temp;
	}
	
	return head;
}

void display(NODE *start){
	printf("list is:");
	while(start!=NULL){
		printf("%3d",start->val);
		start=start->nxt;
	}
}

float median(NODE *head){
	NODE *cur=head;
	
	while(head!=NULL){
		if(head->nxt==NULL)
				return (cur->val);
		
		else if(head->nxt->nxt==NULL)
				return ((cur->val)+(cur->nxt->val)*1.0)/2;
		
		else{
			head=head->nxt->nxt;
			cur=cur->nxt;
		}
	}
}

