/* Structure is same as previous sructure */

void recursiveReverse(struct node** head)
{
    struct node* start;
    struct node* temp;
      
    if (*head == NULL)
       return;   
 
    start = *head;  
    temp  = start->nxt;
 
    if (temp == NULL)
       return;   
 
    recursiveReverse(&temp);
    start->nxt->nxt  = start;  
     
    start->nxt  = NULL;           
    *head = temp;              
}

// 2nd method

void reverse(node **head)
{
    if (!head)
        return;
    rev(*head, NULL, head);
}
 
void rev(node *curr, node *prev, node **head)
{
    if (!curr->nxt){
        *head = curr;
        curr->nxt = prev;
        return;
    }
 
    node *nxt = curr->nxt;
 
    curr->nxt = prev;
 
    rev(nxt, curr, head);
}

