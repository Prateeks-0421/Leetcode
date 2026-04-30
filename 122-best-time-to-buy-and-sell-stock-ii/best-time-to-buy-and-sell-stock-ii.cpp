class Solution {
public:
    long long f(vector<int>& prices, int n, int flag, vector<vector<int>>& dp , int i ) {
       
    if( i == n and flag == 1 ) return 0 ; 
    if( i == n ) return INT_MIN ; 

    if( dp[i][flag] != -1 ) return dp[i][flag] ;     

    if(flag == 1 ){

    return dp[i][flag] = max( -prices[i] +   f( prices , n , 0 , dp , i + 1 ) , f(prices  , n , 1 , dp , i + 1 )) ;  

    }

     return dp[i][flag] =  max( prices[i] +   f( prices , n , 1 , dp , i ) , f(prices  , n , 0 , dp , i + 1  )) ; 

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(prices, n , 1 , dp , 0 );
    }
};
