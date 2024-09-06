//
// Created by Younghusband on 2024/9/2.
//

#include <stddef.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while(ptrA != ptrB) {
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }
        return ptrA;
    }

};

// int main() {
//
// }

