class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        
    int l = 0 ;
    int r = nums.size() - 1 ;

    while( l <= r ){

        int mid = l + (r-l)/2 ; 

     if( mid > 0 and mid < nums.size() - 1 and nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]){
        return mid ; 
     }
     else if( l > 0 and l < nums.size() - 1 and nums[l] > nums[l-1] and nums[l] > nums[l+1] ){

        return l ; 

     }
      else if( r > 0 and r < nums.size() - 1 and nums[r] > nums[r-1] and nums[r] > nums[r+1] ){

        return r ; 

     }
    else if(nums[l] < nums[l+1] and nums[mid] < nums[mid-1]){
        r = mid - 1 ; 
     }
     else l = mid + 1 ; 

    }
    return 0 ; 
    }
};