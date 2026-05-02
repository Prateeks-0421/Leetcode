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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    ListNode* temp = head ;
    int length = 0 ;

    while( temp ){
        temp = temp -> next ; 
        length++ ;
    }

    n = length - n + 1 ; 

    temp = head ;
    ListNode* prev = nullptr ; 

    while( temp ){


      if( n == 1 ){
          
          if( prev == nullptr ){

             head = temp -> next ;
             delete temp ;
             return head ; 
          }

        else {

             prev -> next = temp -> next ; 
             delete temp ;
             return head ; 

        }
     
      }
   
      prev = temp ; 
      temp = temp -> next ;
      n-- ; 



    }

     return head ; 
    }
};