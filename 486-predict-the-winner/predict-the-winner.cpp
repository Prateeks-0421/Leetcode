class Solution {
public:
    int solve(vector<int>& nums , int i , int j , vector<vector<int>> & dp , int flag ) {

     if(   i > j ) return 0 ; 

     if( flag == 0 ){

       return max( nums[i] + solve( nums , i + 1 , j , dp , 1 ) , nums[j] + solve( nums , i , j - 1 , dp , 1)) ; 

     }


       return min(  solve( nums , i + 1 , j , dp , 0 ) - nums[i] , solve( nums , i , j - 1 , dp , 0 ) - nums[j]) ; 

     
    }
    bool predictTheWinner(vector<int>& nums) {

    vector<vector<int>> dp ( nums.size() , vector<int> ( nums.size() , -1 ))  ;    
        
    return solve(nums , 0 , nums.size() - 1 , dp , 0 )  >= 0 ;


    }
};