class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
   long long p = 1 ;
   int i = 0 ; 
   int j = 0 ;
   int count = 0 ;


   while( j < nums.size()){

     p = p * nums[j] ; 

    if( p >= k ){

      while( i < nums.size() and p >= k ){
        p = p / nums[i] ; 
        i++ ; 
      }

    }
      count = count + ( j - i + 1 ) ;
    j++ ; 
   }
    return count ;

    }
};