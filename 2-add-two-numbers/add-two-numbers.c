/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * createLinkedList(struct ListNode * head, int val){
    struct ListNode * temp=head;
    struct ListNode * newNode=(struct ListNode *) malloc(sizeof(struct ListNode));
    newNode->val=val;
    newNode->next=NULL;
    if(head == NULL){
        return newNode;
    }
    while(temp->next != NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    long long sum=0,carry=0,temp=0;
    struct ListNode *head=NULL;
    while(l1!=NULL && l2!=NULL){
        temp=(l1->val)+(l2->val);
        if(carry>0){
            temp=carry+temp;
            carry=0;
        }
        if(temp>9){
        
        carry=temp/10;
        temp=temp%10;
        }
        head=createLinkedList(head,temp);
        l1=l1->next;
        l2=l2->next;
    }
    while(l1!=NULL){
        temp=l1->val;
        if(carry>0){
            temp=carry+temp;
            carry=0;
        }
        if(temp>9){
        
        carry=temp/10;
        temp=temp%10;
        }
        head=createLinkedList(head,temp);
        l1=l1->next;
    }
    while(l2!=NULL){
        temp=l2->val;
        if(carry>0){
            temp=carry+temp;
            carry=0;
        }
        if(temp>9){
        
        carry=temp/10;
        temp=temp%10;
        }
        head=createLinkedList(head,temp);
        l2=l2->next;
    }
    if(carry>0){
        head=createLinkedList(head,carry);
    }
    return head;
}