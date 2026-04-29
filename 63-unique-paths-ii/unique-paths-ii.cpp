class Solution {
public:
    int solve(int n , int m , int i , int j ,  vector<vector<int>> & dp , vector<vector<int>>& grid ){
    
    if(  i >= n or j >= m )  return 0 ;
    if(grid[i][j] == 1) return 0 ;
    if( i == n - 1 and j == m - 1 ) {
        return 1 ; 
    } 
    if(dp[i][j] != -1 ) return dp[i][j] ; 
    return  dp[i][j] = solve( n , m , i + 1 , j , dp , grid ) + solve( n , m  , i , j + 1 , dp , grid ) ; 

    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

     int n = grid.size() ; 
     int m = grid[0].size() ;    
     
     vector<vector<int>> dp( n , vector<int> ( m , -1 ) ) ;  
     
     return solve(n , m , 0 , 0 , dp , grid ) ;
     
    } 
};
