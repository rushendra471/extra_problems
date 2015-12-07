/* Structure is same as previous sructure */
struct node * reverse(NODE *first){
	struct node *p = first,*q = NULL,*r,*s=first;
	while (p != NULL){
		r = q;
		q = p;
		p = p->nxt;
		q->nxt = r;
	}
	first->nxt = NULL;
	return q;
}
// 2nd method

struct node * reverse(struct node * start) {
	struct node * r = NULL;
	while (start) {
		NODE* cur = start->nxt;
		start->nxt = r;
		r = start;
		start = cur;
	}
	return r;
}
