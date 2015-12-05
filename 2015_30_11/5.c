int find(struct node * list, int r){
	int i = 0;
	struct node * t = list;
	while (i < r){
		t = t->nxt;
		i++;
	}
	return t->val;
}

struct node * mergelist(struct node * first, struct node * second){
	struct node * third = NULL;
	if (first == NULL)
		return second;
	if (second == NULL)
		return first;
	while (first->nxt!= NULL && second->nxt!= NULL){
		if (first->val < second->val){
			third = insert(third, first->val);
			first = first->nxt;
		}
		else if (second->val < first->val){
			third = insert(third, second->val);
			second = second->nxt;
		}
		else{
			third = insert(third, first->val);
			first = first->nxt;
			second = second->nxt;
		}
	}
	while (first != NULL){
		third = insert(third, first->val);
		first = first->nxt;
	}
	while (second != NULL)	{
		third = insert(third, second->val);
		second = second->nxt;
	}
	return third;
}