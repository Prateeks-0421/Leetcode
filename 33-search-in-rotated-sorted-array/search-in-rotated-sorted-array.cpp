class Solution {
public:
    int search(vector<int>& nums, int target) {
        
      int i = 0 ; 
      int j =  nums.size() - 1 ;

      while( i <= j ){
        int mid = i + ( j - i ) /  2 ; 

          if(nums[mid] == target ) return mid ; 
       
         else if( nums[i] > nums[mid] and target >= nums[i] and target >= nums[mid]) {

             j = mid - 1 ;

         }
           else if( nums[i] > nums[mid] and target <= nums[i] and target <= nums[mid]) {

             j = mid - 1 ;

         }

           else if( nums[i] < nums[mid] and target >= nums[i] and target <= nums[mid]) {

             j = mid - 1 ;

         }

         else {
            i = mid + 1 ; 

         }
        
      }
      return -1 ; 
    }
};