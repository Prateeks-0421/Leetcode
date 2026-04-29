
class Solution {
public:
    
    int solve( int i ,vector<int>& nums , int n ,  vector<int> & dp ){

    if ( i >= n ) return pow(10 , 9 ) ; 

    if( i == n - 1 ) return 0 ;  
     int value = nums[i] ; 

    if( dp[i] != -1 ) return dp[i] ;    

     if( value == 0 ) return pow(10,9) ;
    
    int flag =  pow(10,9) ; 

    for(int j = i + 1 ; j <= i + nums[i] ; j++ ){   

    flag = min(flag , 1 + solve( j , nums , n , dp )) ; 

    }
    return dp[i] = flag ; 

    }


    int jump(vector<int>& nums) {

    int n =  nums.size() ; 
        
     vector<int>dp ( n , -1 ) ; 

    return solve(0 , nums , n  , dp) ; 

    }
};