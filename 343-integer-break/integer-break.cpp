class Solution {
public:

    long long solve( int n , int i , vector<int> & dp  ){

    if( i < 0 ) return INT_MIN ;     

    if( i == 0 ) return 1 ; 

    if( dp[i] != -1 ) return dp[i] ; 

     long long maxi = INT_MIN ; 
    for(int j = 1 ; j <= i ; j++ ){

     if( j == n ) continue ;   

     maxi = max( j * solve( n , i - j , dp )  , maxi  ) ; 

    }
    return dp[i] = maxi ; 

    }
    int integerBreak(int n) {

     vector<int>dp ( n + 1 , -1 )   ;  
    
    return solve( n , n , dp  ) ;       

    }

};