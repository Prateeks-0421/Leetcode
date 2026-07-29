class Solution {
public:

    bool check(vector<int> & nums , int i  , int j ){

    int diff = nums[i+1] - nums[i] ;  ; 

    while(i < j ){

     if(diff != nums[i+1] - nums[i]) return false ; 
     diff = nums[i+1] - nums[i] ; 
     
     i++ ; 

    }
    return true ; 
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        
    int i = 0 ;
    int j = 2 ; 
    int ans = 0 ; 

    while ( j < nums.size() ){

    bool checked = check(nums , i , j ) ;  

     if(!checked){
        
     i++ ;
     if( j == i + 1 ) j = i + 2 ; 

     }

    else {

        ans = ans + (j-i-1) ;
        j++ ; 
    }

    }
     return ans ;
    }
};