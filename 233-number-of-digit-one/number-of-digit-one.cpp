class Solution {
public:
    int solve( vector<int> & nums , int i , bool tight , int count , vector<vector<vector<int>>>& dp ){

    if( i == nums.size() ) return count ;    

    if(dp[i][count][tight] != -1 ) return dp[i][count][tight] ; 

    int limit = tight ? nums[i] : 9 ; 

    int ans = 0 ; 

    for(int d = 0 ; d <= limit ; d++ ){

    bool newtight = tight && ( d == nums[i] ) ; 

    int newCount = count;

    if(d == 1)
    newCount++;

    ans = ans + solve( nums , i + 1 , newtight , newCount , dp ) ; 

    }
 
    return dp[i][count][tight] = ans ; 

    }
    int countDigitOne(int n) {

      vector<int> nums ; 

      while(n){
        nums.push_back(n % 10 ) ; 
        n = n / 10 ;

      }
      reverse(nums.begin() , nums.end() ) ; 

      vector<vector<vector<int>>> dp( nums.size() , vector<vector<int>> ( nums.size() , vector<int> ( 2 , -1 ))) ;

     return solve( nums , 0 , true , 0  , dp ) ;   

    }
};