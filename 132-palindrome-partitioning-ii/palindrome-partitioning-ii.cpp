class Solution {
public:
    bool ispalindrome(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    int solve(string &s, int i, int j, vector<vector<int>> &dp){

        if(i == s.size()) return 0;

        if(j == s.size()) return INT_MAX;

        if(j == s.size() - 1 && ispalindrome(s, i, j)){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(ispalindrome(s, i, j)){
            return dp[i][j] = min(
                1 + solve(s, j + 1, j + 1, dp),
                solve(s, i, j + 1, dp)
            );
        }

        else return dp[i][j] = solve(s, i, j + 1, dp);
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, 0, dp);
    }
};





































// class Solution {
// public:
    
//      bool palindrome(string & s  , int i , int l ){
       
//         int j = i + l - 1  ;

//         while( i <= j ){
//             if(s[i] != s[j]) return false ;
//             i++ ; j-- ; 
//         }
//         return true ; 
//     }

//     int solve( string & s , int i , int l ,  vector<vector<int>> & dp  ){
     
//      if( i >= s.size()) return 0 ; 
//      if( l > s.size()  - i ) return pow( 10 , 9 ) ;
      
//      if(dp[i][l] != -1 ) return dp[i][l] ; 
//      if( palindrome( s , i , l )){

//        return dp[i][l] =  min( 1 + solve( s , i + l , 1 , dp ) , solve( s, i , l + 1 , dp ) ) ;  

//      }
//      else return  dp[i][l] = solve( s , i , l + 1 , dp  ) ; 

//     }
//     int minCut(string s) {
        
//       vector<vector<int>> dp ( s.size() + 1 , vector<int> ( s.size() + 1 ,  -1 ) ) ;   
//    return solve(s , 0 , 1  , dp ) - 1  ;

//     }
// };