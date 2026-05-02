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
    ListNode* rotateRight(ListNode* head, int k) {
        
    ListNode* temp = head ;
    int length = 0 ;
      ListNode* first = head ;
      if( k == 0 or head == nullptr or head -> next == nullptr ) return head ; 
    while( temp ){
        temp = temp -> next ; 
        length++ ;
    }
    k = k % length ; 


     k = length - k + 1 ; 

    ListNode* prev = nullptr ;
    temp = head ; 

       while( temp ){

        if( k == 1 ){

          head = temp ; 
          if( prev )
          prev -> next = nullptr ; 


         while( temp -> next ){

            temp = temp -> next ; 

         }
         temp -> next = first ; 
         return head ; 

        }

         prev = temp ; 
        temp = temp -> next ; 
           k-- ; 

            }

    return head ; 
    }
};