class Solution {
public:
    int solve(vector<int>& nums, int k ){

    int count = 0 ;
    int i = 0 ;
    int j = 0 ;
    int ans = 0 ; 

    if(k == -1) return 0 ; 

    while( j < nums.size()){

    if(nums[j] == 1 ){
        count++ ; 
    }

    if(count > k ){

     while( count > k ){
         if( i < nums.size() and nums[i] == 1 ) count-- ; 
         i++ ; 
     }


    }
      ans = ans + ( j - i + 1 ) ;

     j++ ;
    }

     return ans ; 

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        
    return solve(nums , goal) - solve(nums , goal - 1 ) ; 

 
    }
};