class Solution {
public:
    int solve(string & num1 , string & num2 , int i , int j , vector<vector<int>>& dp ){

     if(i==num1.size())
     return num2.size()-j;

      if( j == num2.size() ){
        return num1.size() - i ;
      }  

      if( dp[i][j] != -1 ) return dp[i][j] ; 

    if( num1[i] == num2[j] ){
       return dp[i][j] = solve(num1 , num2 , i + 1 , j + 1 , dp ) ; 
    }
    int ans = INT_MAX ; 
      
    ans = 1 + solve( num1 , num2 , i  , j + 1 , dp ) ; 
    
    ans = min( ans ,  1 + solve( num1 , num2  ,i + 1  , j , dp )) ; 

    ans = min( ans ,  1 + solve( num1 , num2 , i + 1 , j + 1 , dp )) ; 

    return dp[i][j] = ans ; 

    }

    int minDistance(string word1, string word2) {

        vector<vector<int>> dp( word1.size(), vector<int> ( word2.size() , - 1 )) ; 
        
    return solve(word1 , word2 , 0 , 0  , dp) ;       

    }
};