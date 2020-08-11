//--------
// 主要思路是双指针一直走,A相交前的长度为a，B相交前的长度为b，
// 假设链表A和B相交，相交后公共长度为c;A走到头后指向B的开头，B走到头后指向A的开头，最后两者相交时，长度正好为 a+c+b = b+c+a;
// 假设不相交,c=0，则结果为a+b = b+a,双指针相等时都为NULL走到了尾部
// ----

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *i = headA;
        ListNode *j = headB;
        if(headA == NULL || headB == NULL) return NULL;
        while(i != j)
        {
            if( i == NULL)
                i =headB;
            else
                i = i->next;
            if(j == NULL)
                j = headA;
            else
                j = j->next;
        }
        if(i != NULL)
            return i;
        else
            return NULL;
    }
};