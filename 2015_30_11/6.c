struct node * add(struct node * first, struct node * second)
{
	struct node * list=NULL;
	int s = 0,flag=0,tmp=0;
	if (first == NULL)
		return second;
	if (second == NULL)
		return first;
	while (first != NULL && second != NULL){
		if (first->val + second->val > 9){
			tmp = (first->val + second->val) % 10;
			list = insert(list, tmp + flag);
			flag = (first->val + second->val) / 10;
		}
		else{
			list = insert(list, first->val + second->val + flag);
			flag = 0;
		}
		first = first->nxt;
		second = second->nxt;
	}
	if (first == NULL && second == NULL && flag != 0)
		list = insert(list, flag);
	while (first != NULL){
		tmp = first->val + flag;
		if (tmp > 9){
			flag = tmp % 10;
			list = insert(list, tmp + flag);
		}
		else{
			list = insert(list, tmp + flag);
			flag = 0;
		}
		first = first->nxt;
	}
	while (second != NULL){
		tmp = second->val + flag;
		if (tmp > 9){
			flag = tmp % 10;
			list = insert(list, tmp + flag);
		}
		else{
			list = insert(list, tmp + flag);
			flag = 0;
		}
		second = second->nxt;
	}
	return reverse(list); // to reverse the linked list.
}