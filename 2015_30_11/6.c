typedef struct node{
	int val;
	struct node *nxt,*prv; // Doubly linked list
}NODE;


struct node * add(struct node * list1, struct node * list2){
	if(list1==NULL)
		return list2;
	else if(list2==NULL)
		return list1;
	while(list1->nxt!=NULL)
		list1=list1->nxt;
	while(list2->nxt!=NULL)
		list2=list2->nxt;
	int r=0,c=0;
	struct node *res=NULL;
	while(list1!=NULL&&list2!=NULL){
		r=list1->val+list2->val+c;
		if(r>9){
			r=r%10;
			c=1;
		}
		else
			c=0;
		res=create(res,r);
		list1=list1->prv;
		list2=list2->prv;
	}
	while(list1!=NULL){
		r=list1->val+c;
		if(r>9){
			r=r%10;
			c=1;
		}
		else
			c=0;
		res=create(res,r);
		list1=list1->prv;
	}
	while(list2!=NULL){
		r=list2->val+c;
		if(r>9){
			r=r%10;
			c=1;
		}
		else
			c=0;
		res=create(res,r);
		list2=list2->prv;
	}
	res=reverse(res); //reversing a doubly linked list
}
