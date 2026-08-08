class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
   int i = 0 ;
   int j = 0 ;
   double sum = 0 ; 
   double maximum = INT_MIN ; 

   while( j < nums.size()){

   sum = sum + nums[j]  ;

   if(j - i + 1 == k ){

    maximum = max(maximum , sum ) ; 

    sum = sum - nums[i] ; 
    i++ ;

   }

   j++ ; 

   }
   return (double)maximum / k ; 

    }
};