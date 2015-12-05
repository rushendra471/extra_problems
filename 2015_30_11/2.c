#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int val;
	struct node *nxt;
}NODE;

NODE* create(NODE*, int);
void display(NODE*);
NODE* merge(NODE*, NODE*);

main(){
	int n, s, i;
	NODE *l1 = NULL, *l2 = NULL;

	printf("Enter no.of nodes:-");
	scanf_s("%d", &s);

	printf("Enter node values:-\n");
	for (i = 0; i<s; i++){
		scanf_s("%d", &n);
		l1 = create(l1, n);
	}

	printf("Enter no.of nodes:-");
	scanf_s("%d", &s);

	printf("Enter node values:-\n");
	for (i = 0; i<s; i++){
		scanf_s("%d", &n);
		l2 = create(l2, n);
	}

	l1 = merge(l1, l2);

	display(l1);

	fflush(stdin);
	getchar();
}

NODE* create(NODE* head, int n){
	NODE *cur, *temp;

	if (head == NULL){
		head = (NODE*)malloc(sizeof(NODE*));
		head->val = n;
		head->nxt = NULL;
	}
	else{
		cur = head;
		while (cur->nxt != NULL)
			cur = cur->nxt;
		temp = (NODE*)malloc(sizeof(NODE*));
		temp->val = n;
		temp->nxt = NULL;
		cur->nxt = temp;
	}

	return head;
}

void display(NODE *start){
	printf("list is:");
	while (start != NULL){
		printf("%3d", start->val);
		start = start->nxt;
	}
}

NODE* merge(struct node* a, struct node* b){

	NODE *result = NULL;

	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);


	if (a->val <= b->val){
		result = a;
		result->nxt = merge(a->nxt, b);
	}
	else{
		result = b;
		result->nxt = merge(a, b->nxt);
	}

	return result;
}