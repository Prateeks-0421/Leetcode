/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
    if( head == nullptr or head -> next == nullptr ) return head ; 

    ListNode* temp = head ; 
    ListNode* curr = temp -> next ; 

    ListNode* future = nullptr ; 
    temp -> next = nullptr ; 

    while( curr != nullptr  ){

    future = curr -> next ; 

    curr -> next = temp ;
    // temp -> next = nullptr ;

     temp =  curr ;
     curr = future ; 

    }
     return temp ; 

    }
};