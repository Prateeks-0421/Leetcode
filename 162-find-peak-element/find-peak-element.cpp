class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    
    int l = 0 ;
    int r = nums.size() - 1 ;

    if(nums.size() == 1 ) return 0; 

    while( l <= r ){
        int mid = l + ( r - l )/2 ; 

        if(mid < nums.size() - 1 and mid > 0 and (nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]) ){

                return mid ; 

        }

        
        else if(mid == nums.size() - 1 and mid > 0 and nums[mid] > nums[mid-1]  ){

                return mid ; 

        }
        else if(mid == 0 and mid < nums.size() - 1 and nums[mid] > nums[mid+1]){

               return mid  ; 

        }


       else if( mid < nums.size() - 1 and nums[mid]  < nums[mid+1] ) {

            l = mid + 1 ; 
        }

       else if( mid > 0  and nums[mid]  < nums[mid-1] ) {

            r = mid - 1 ; 
        }
    }
      return -1 ; 
    }
};