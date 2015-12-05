struct node * arrage(struct node * first){
	struct node * t = first, prev=NULL, l1=NULL,list=NULL;
	int count = 0;
	if (first == NULL)
		return first;
	while (t->nxt != NULL){
		l1 = prev;
		prev = t;
		t = t->nxt;
		if (t->val < prev->val){
			list = reverse(l1->nxt);
			break;
		}
	}
		l1->nxt = list;
	return first;
}
