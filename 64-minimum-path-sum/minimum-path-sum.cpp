class Solution {
public:

    long long solve( int i , int j , int n , int m , vector<vector<int>>& grid ,vector<vector<int>> & dp ){


    if ( i >= n or j >= m or i < 0 or j < 0 ) return INT_MAX ;  
    if(i ==  n - 1 and j == m - 1 )   return grid[i][j] ; 

    if(dp[i][j] != -1 ) return dp[i][j] ; 

    return dp[i][j] =  min( grid[i][j] +  solve( i + 1 , j , n , m , grid , dp ) , 
    grid[i][j] + solve( i , j + 1 , n , m , grid , dp ) ) ;  


    }
    int minPathSum(vector<vector<int>>& grid) {

    int n = grid.size() ; 
    int m = grid[0].size() ;  

    vector<vector<int>> dp ( n , vector<int> ( m , -1 )) ; 
    

    return solve( 0 , 0 , n , m , grid , dp ) ; 


    }
};


























// class Solution {
// public:
//      int solve(int m , int n , vector<vector<int>>& grid , int i , int j ,  vector<vector<int>> & dp ){

//     if( i >= m or j >= n  ) return pow(10, 9) ;
//     if( i == m - 1 and j == n - 1 ) {
//         return grid[i][j] ; 
//     } 
//     if(dp[i][j] != -1 ) return dp[i][j] ; 
//     return  dp[i][j] = grid[i][j] + min(solve( m , n , grid ,  i + 1 , j , dp ) , solve( m , n , grid , i , j + 1 , dp ) ); 

//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m  = grid.size() ;
//         int n = grid[0].size() ;
//         vector<vector<int>> dp( m , vector<int> ( n , -1 ) ) ;  
//      return solve(m , n ,grid , 0 , 0 , dp  ) ; 

//     }
// };