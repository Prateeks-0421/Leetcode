class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
    int l = 0 ; 
    int r = nums.size() - 1 ; 

    while( l <= r ){

    int mid = l + ( r - l )/2 ; 

    // if(nums[mid] == target ) return true  ;

    if(nums[l] == target or nums[mid] == target or nums[r] == target ) return true ; 

    else if(nums[l] == nums[r] and nums[mid] == nums[r] ){

       // go to left 
       int start = mid ;

    while( start > 0 and nums[start] == nums[mid]) start-- ; 

    if(start == 0 ) l = mid + 1 ; 

    else r = mid - 1 ; 

    }

   else if(nums[l] > nums[mid] and nums[mid] < target and nums[l] < target ){

        r = mid - 1 ; 

    }

       else if(nums[l] > nums[mid] and nums[mid] > target and nums[l] > target ){

        r = mid - 1 ; 

    }

    else if(  nums[l] < target and nums[mid] > target ){

        r = mid - 1 ; 

    }
    else l = mid + 1 ;
    
    } 
    return false;

    }
};