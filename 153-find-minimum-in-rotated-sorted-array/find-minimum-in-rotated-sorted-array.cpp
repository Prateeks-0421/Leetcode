class Solution {
public:
    int findMin(vector<int>& nums) {
        

    int l = 0 ;
    int r = nums.size() - 1;

    if(nums.size() == 1 )return nums[0] ; 

     if(nums[0] < nums[1] and nums[0] < nums[nums.size() - 1 ]) return nums[0] ; 


    while( l <=r ){

        int mid = l + ( r-l)/2 ;
   

      if( mid > 0 and mid < nums.size() - 1 and nums[mid] < nums[mid+1] and nums[mid] < nums[mid-1] ) {
        return nums[mid] ; 
      }

      else if( mid == 0 and mid < nums.size() - 1 and nums[mid] < nums[mid+1] and nums[mid] < nums[nums.size() - 1] ) {
        return nums[mid] ; 
      }
      else if( mid > 0 and mid == nums.size() - 1 and nums[mid] < nums[0] and nums[mid] < nums[mid-1]  ) {
        return nums[mid] ; 
      }

      else if(nums[l] > nums[mid]){
        r = mid - 1 ; 
      }
      else if(nums[mid] > nums[r]){
        l = mid + 1 ; 
      }
      else {
          return nums[l] ; 
      }

    }
      return -1 ;
    }
};