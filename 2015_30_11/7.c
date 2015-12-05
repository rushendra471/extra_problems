struct node * arrage(struct node * first)
{
	struct node * t = first, prev=NULL, n1=NULL, n2=NULL;
	int count = 0;
	if (first == NULL)
		return first;
	while (t->nxt != NULL && count != 2){
		prev = t;
		t = t->nxt;
		if (t->val < prev->val){
			count++;
			if (count == 1)
				n1 = prev;
			if (count == 2)
				n2 = t;
		}
	}
	if (count != 0){
		n1->val = n1->val + n2->val;
		n2->val = n1->val - n2->val;
		n1->val = n1->val - n2->val;
	}
	return first;
}