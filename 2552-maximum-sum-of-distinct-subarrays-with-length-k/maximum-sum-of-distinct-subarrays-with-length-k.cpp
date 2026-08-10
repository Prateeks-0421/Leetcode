class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
    unordered_map<int,int> freq ; 

    int i = 0 ; 
    int j = 0 ; 
    long long ans = 0 ;
    long long sum = 0 ;  

    while( j < nums.size()){

     freq[nums[j]]++ ; 
     sum = sum + nums[j] ; 

     if(freq[nums[j]] > 1 ){

       while( freq[nums[j]] > 1 ){
        freq[nums[i]]-- ; 
        sum = sum - nums[i] ; 
        i++ ; 
       }
      
     }

    if( j - i + 1 == k ){
       ans = max( ans , sum ) ; 
       sum = sum - nums[i] ; 
       freq[nums[i]]-- ;
       i++ ; 
    }

      j++ ; 

    }
   return ans ; 


    }
};