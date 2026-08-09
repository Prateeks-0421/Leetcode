class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int count = 0 ; 
        sort(nums.begin(), nums.end()) ; 
    for(int i = 0 ; i < nums.size() ; i++ ){
        for(int j = i + 1 ; j < nums.size() ; j++ ){

         int l = j + 1 ; 
         int r = nums.size() - 1 ;
         int ans = - 1;
         int target = nums[i] + nums[j] - 1 ; 

         while( l <= r ){
            int mid = l + ( r-l)/2 ; 

            if(nums[mid]  <=  target ){

                l = mid + 1 ; 
                ans = mid ; 
            }
            else r = mid - 1 ; 
         }
         if(ans != -1 )
          count = count + ( ans - j ) ; 
        }
    }
     return count ; 
    }
};