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
