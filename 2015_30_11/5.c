// structure is same as previous one. create and display functions are also same as in 1st programme

int getElement(int n1, int n2, int r) {

	struct node * list1 = NULL, *list2 = NULL, *cur = NULL, *start = NULL, *t = NULL;
	int i;

	for (i = 1; i <= r; i++){
		list1 = create(list1, (n1 * i));
		list2 = create(list2, (n2 * i));
	}

	printf("\nlist1:-");
	display(list1);

	printf("\nlist2:-");
	display(list2);

	while (list1 != NULL && list2 != NULL) {
		if (list1->val < list2->val) {
			t = list1;
			list1 = list1->nxt;
		}
		else if (list1->val > list2->val) {
			t = list2;
			list2 = list2->nxt;
		}
		else {
			t = list1;
			list1 = list1->nxt;
			list2 = list2->nxt;
		}
		
		if (start == NULL)
			start = cur = t ;
		else{
			cur->nxt = t;
			cur = cur->nxt;
		}
	}

	if (list1 != NULL)
		cur->nxt = list1;
	else
		cur->nxt = list2;

	printf("\nMerged list:-");
	display(start);

	i = 1;
	cur = start;
	while (i != r) {
		cur = cur->nxt;
		i++;
	}

	return cur->val;
}
