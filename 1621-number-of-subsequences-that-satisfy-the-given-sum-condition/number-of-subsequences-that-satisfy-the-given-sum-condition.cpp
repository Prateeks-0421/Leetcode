class Solution {
public:


    int numSubseq(vector<int>& nums, int target) {
        
     int l = 0 ;
     int  r = nums.size( ) - 1; 
     long long janhvi = 0 ;
     sort(nums.begin() , nums.end()) ; 

     vector<long long> pow2(nums.size());

        pow2[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            pow2[i] = (pow2[i - 1] * 2) % 1000000007  ;
        }


     while( l <= r ){

    if(nums[l] + nums[r] > target ) r-- ; 

    else {

        long long terms = pow2[r-l] ; 
 
        janhvi = (janhvi + terms ) % 1000000007  ; 
        
        l++ ;

    }

     }

    return janhvi % 1000000007 ;

    }
};