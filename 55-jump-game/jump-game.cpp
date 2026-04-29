class Solution {
public:
    bool canJump(vector<int>& nums) {
            int k = 1 ; 
        for( int i = nums.size() -1 ; i>= 1 ; i--){
            if( nums[i-1] >= k ) {  k = 1 ; }
            if( nums[i-1] < k ) k++; 
        }

        return k==1 ; 
    }
};