class Solution {
public:

   int solve(vector<int> & nums , int k ){

    unordered_map<int,int> freq ; 

    int i = 0 ;
    int j = 0 ;
    int count = 0 ;
    int ans = 0 ; 

    while( j < nums.size()){

       freq[nums[j]]++ ; 
     if(freq[nums[j]] == 1 ) count++ ; 

     if(count > k ){

       while( i < nums.size() and count > k ){

         if(freq[nums[i]] == 1 ) {
            count-- ;
          freq[nums[i]]-- ;
          i++ ; 
             break ; 
           }
           freq[nums[i]]-- ; 
           i++ ; 
       
       }

     }
    ans = ans + ( j - i + 1) ; 
    j++ ;

    }
    return ans ; 

   }



    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
     return solve(nums , k ) - solve(nums , k - 1 ) ; 


    }
};