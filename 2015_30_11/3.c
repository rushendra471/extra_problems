/* Structure of node is same as previous structure */

struct node * AddFront(struct node * tail, int num){
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	
	temp->val = num;
	temp->nxt = temp;	
	
	if (tail == NULL) 
		return temp;
	
	temp->nxt = tail->nxt;
	tail->nxt = temp;
	
	return tail;
}
