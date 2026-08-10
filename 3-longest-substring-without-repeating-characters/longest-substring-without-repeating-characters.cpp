class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        
     unordered_map<char,int> freq ; 

     int i = 0 ;
     int j = 0 ;
     int ans = 0  ; 
     while( j < nums.size()){
        freq[nums[j]]++ ; 

     while(freq[nums[j]] > 1 ){
        freq[nums[i]]-- ; 
        i++ ; 
     }

     ans = max( ans , j - i + 1 ) ; 

     j++ ;  
     }
    return ans ; 

    }
};