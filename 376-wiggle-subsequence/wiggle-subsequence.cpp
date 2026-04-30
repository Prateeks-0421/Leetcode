class Solution {
public:
    int solve( vector<int> & nums , int i , int j , int sign ,  vector<vector<vector<int>>> & dp  ){

    if( i == nums.size() ) return 1 ; 

   int diff = nums[i] - nums[j] ;  

   if( dp[i][j][sign] != -1 ) return dp[i][j][sign] ;

   if( sign == 0 and diff > 0 ){

    return dp[i][j][sign] =  max( 1 + solve( nums , i + 1 , i , 1 , dp )  , solve(  nums , i + 1 , j , 0 , dp ) ) ; 

   }

    else if( sign == 0 and diff < 0 ){

    return dp[i][j][sign] = max( 1 + solve( nums , i + 1 , i , 2 , dp )  , solve(  nums , i + 1 , j , 0 , dp ) ) ; 


   }

   else if( sign == 1 and diff < 0 ){

    return dp[i][j][sign] = max( 1 + solve( nums , i + 1 , i , 2 , dp )  , solve(  nums , i + 1 , j , 1, dp ) ) ; 


   }

    else if( sign == 2 and diff > 0 ){

    return dp[i][j][sign] = max( 1 + solve( nums , i + 1 , i , 1 , dp )  , solve(  nums , i + 1 , j , 2 , dp ) ) ; 


   }

   return dp[i][j][sign] = solve( nums , i + 1 , j , sign , dp ) ; 


    }
    int wiggleMaxLength(vector<int>& nums) {

     int sign = 0 ; 
     vector<vector<vector<int>>> dp ( nums.size() + 1, vector<vector<int>> ( nums.size() + 1 , vector<int> ( 3 , -1 ))) ; 
        
    return solve( nums , 1 , 0 ,  sign , dp ) ; 
  
    }
};
















// class Solution {
// public:
//     int solve( vector<int> & nums , int idx , int prev , vector<vector<int>> & dp  ){

//      if( idx == nums.size() - 1 ) return 1 ; 
     
//      int diff = nums[idx+1] - nums[idx] ; 

//      if(dp[idx][prev] != -1 ) return dp[idx][prev] ; 
//      if( (prev == 0 or prev == 1) and diff < 0  ) {

//        return dp[idx][prev] = max( 1 + solve( nums , idx + 1 , 2 , dp  ) , solve( nums , idx + 1 , prev , dp ) ) ; 


//      }
//     else if(( prev == 0 or prev == 2 ) and diff > 0 ) {

//          return dp[idx][prev] =  max( 1 + solve( nums , idx + 1 , 1 , dp ) , solve( nums , idx + 1 , prev , dp ) ) ; 

//     }
//     else  return dp[idx][prev] = solve( nums , idx + 1 , prev , dp  ) ; 

//     }
//     int wiggleMaxLength(vector<int>& nums) {
        
//       vector<vector<int>> dp ( nums.size() + 1 , vector<int> ( 3  , -1 ))  ;
//      return solve( nums , 0 , 0 , dp  ) ; 

//     }
// };