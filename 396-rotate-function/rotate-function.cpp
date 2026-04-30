class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
    int temp = 0 ; 
    int sum = 0 ; 

    for(int i = 0 ; i < nums.size() ; i++ ) {

     temp = temp + i * nums[i] ;
     sum += nums[i] ;  

    }
    
    int maxi = temp ; 
    for( int i = nums.size() - 1  ; i > 0 ; i-- ){

     temp = temp + sum - nums[i] * (nums.size()) ;

     maxi  = max( maxi , temp ) ;
     
    }
    return maxi ; 

    }
};