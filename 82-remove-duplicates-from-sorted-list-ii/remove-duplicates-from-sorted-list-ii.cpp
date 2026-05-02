class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

     ListNode* curr = head ;   
     ListNode* prev = nullptr ; 

     int m = 0 ;  

     while( curr && curr -> next  ){
        if( curr -> val == curr -> next -> val){
             ListNode* temp = curr -> next ;
             curr -> next = temp -> next ;
             delete temp ;
             m = 1 ; 
        }

        else if( m == 1 ) {
              
        if( prev == nullptr ){

        //   ListNode*  temp = curr ;

        //     curr = curr -> next ;
        //     delete temp ; 

        ListNode* temp = head ;
        head = head -> next ; 
        delete temp ; 
        curr = head ; 

        }
        else {
            prev -> next = curr -> next ; 
            delete curr ; 
            curr = prev -> next ; 
        }
          m = 0 ; 

        }
        else{ 

            prev = curr ; 
            curr = curr -> next ; 
            m = 0 ;

        }
     }

     if( m == 1 ){

          if( prev == nullptr ){

        ListNode* temp = head ;
        head = head -> next ; 
        delete temp ; 
        curr = head ; 

        }
        else {
            prev -> next = curr -> next ; 
            delete curr ; 
            curr = prev -> next ; 
        }

     }
        return head ; 


    }
};





















