class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
    int i = 0 ; 
    int j = 0 ;
    int length = nums.size() + 1 ;
    int sum = 0 ;

    while( j < nums.size() ){

        sum = sum + nums[j] ;

    if(sum >= target ) {

     while( sum >= target ){

     sum = sum - nums[i] ; 
     length = min(length , j - i + 1 ) ; 

     i++ ; 

     }
     
    }

     j++ ;

    }
      if( length == nums.size() + 1 ) return 0 ; 
      return length ; 
    }
};