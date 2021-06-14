//works
struct ListNode* reverseList(struct ListNode* head){

    struct ListNode *t;
    struct ListNode *nxt;
    struct ListNode *tmp = head;
    if(head == NULL)
        return NULL;
    if(tmp->next == NULL)
        return tmp;
    else {
        t = tmp->next;
        tmp->next=NULL;
        while(tmp!=NULL) {
            nxt =  t;
            if(nxt!=NULL) {
                t = nxt->next;//until this all the 3 ptrs are stored
                nxt->next = tmp;//sawp is done
                tmp = nxt;//this is to iterate
            } else {
                return tmp; //needed to handle the corner case of last element
            }
        }
        return tmp;
    }
    return tmp;
}
//replace the head's reference in place
void rev(struct node **head) {
  //struct node *tmp, *prev, *last = NULL; doesn't work
  struct node *tmp = NULL;
  struct node *prev = NULL;
  struct node *last = NULL;

  struct node *cur = *head;
  if (cur == NULL) {
    return;
  }
  if (cur->next == NULL) {
    return;
  }
  while(cur != NULL && cur->next != NULL) {
    if (cur->next->next == NULL) {
      cur->next->next = cur;
      last = cur->next;
      cur->next = prev;
      *head = last;
      return;
    }
    tmp = cur->next->next;
    cur->next->next = cur;
    last = cur->next;
    cur->next = prev;
    cur = tmp;
    prev = last;
  }
  /*
  if (cur == NULL) {
    *head = prev;
    return;
  }
  */
  if (cur->next == NULL) {
    cur->next = prev;
  }
  *head = cur;
  return;
}
