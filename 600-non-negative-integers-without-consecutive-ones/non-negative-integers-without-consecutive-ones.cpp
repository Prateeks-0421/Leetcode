class Solution {
public:

    int solve( vector<int> & nums , int i , bool tight , int prev , vector<vector<vector<int>>>& dp ){

    if( i == nums.size() ) return 1 ;    

    if(dp[i][prev][tight] != -1 ) return dp[i][prev][tight] ; 

    int limit = tight ? nums[i] : 1 ; 

    int ans = 0 ; 

    for(int d = 0 ; d <= limit ; d++ ){  

    bool newtight = tight && ( d == nums[i] ) ; 

    if( prev == 1 and d == 1 ) continue ; 

    ans = ans + solve( nums , i + 1 , newtight , d , dp ) ; 

    }
 
    return dp[i][prev][tight] = ans ; 

    }
    int findIntegers(int n) {
        
     vector<int> nums ; 

      while(n){
        nums.push_back(n % 2 ) ; 
        n = n / 2 ;

      }

      reverse(nums.begin() , nums.end() ) ; 

      vector<vector<vector<int>>> dp( nums.size() , vector<vector<int>> ( 3 , vector<int> ( 2 , -1 ))) ;

     return solve( nums , 0 , true , 2 , dp ) ;   

    }
};