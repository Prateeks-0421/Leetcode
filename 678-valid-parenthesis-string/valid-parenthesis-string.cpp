class Solution {
public:

    bool solve( string s , int i , int l , int r , vector<vector<vector<int>>> & dp  ){

    if( i == s.size() and l == 0 ) return true ;

    if( i == s.size()) return false ;   

    if( dp[i][l][r] != -1 ) return dp[i][l][r] ;   

    if( l == 0 and  s[i] == ')' ){

     return false ; 

    }    

    if( s[i] == '(' ){

     return dp[i][l][r] = solve( s , i + 1 , l + 1 , r , dp  ) ; 

    }
    
    else if( l > 0 and  s[i] == ')' ){

     return dp[i][l][r] = solve( s , i + 1 , l - 1  ,  r + 1 , dp ) ; 

    }
    if( l > 0  ) 
    return dp[i][l][r] = solve( s , i + 1 , l + 1 , r , dp ) or solve( s , i + 1 , l - 1 , r + 1 , dp ) or solve( s , i + 1 , l , r , dp ) ;
    
    return dp[i][l][r] = solve( s , i + 1 , l + 1 , r , dp ) or  solve( s , i + 1 , l , r , dp ) ; 

    }
    bool checkValidString(string s) {

    vector<vector<vector<int>>> dp ( s.size() , vector<vector<int>> ( s.size() , vector<int>  ( s.size() , -1 ) ) ); 
        
    return solve( s , 0 , 0 , 0 , dp  ) ; 


    }
};