class Solution {
public:
    bool ispalindrome( string s ){

     int r = s.size() - 1 ;
     int l = 0 ;

     while( l < r ){
        if( s[l] != s[r]) return false ; 
        l++ ;
        r-- ; 
     }

     return true ; 

    }

    void solve(vector<vector<string>> & ans , string s , int i , int j , vector<string> & temp ){

    if( i == s.size() ) {

     ans.push_back(temp) ; 
     return ; 

    }

    if(j == s.size() ){
        return ; 
    }

    if(ispalindrome(s.substr( i , j - i + 1  ))){

    temp.push_back(s.substr( i , j - i + 1 )) ; 

     solve( ans , s , j + 1 , j + 1 , temp ) ; 

     temp.pop_back() ; 

    }

    solve( ans , s , i , j + 1 , temp ) ; 

      return ; 
    }


    vector<vector<string>> partition(string s) {

    vector<vector<string>> ans ;
    vector<string> temp ; 

    solve( ans , s , 0 , 0 , temp ) ;

    return ans ;

    }
};