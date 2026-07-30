class Solution {
public:

    bool check(vector<int> & nums , int freq , int k ){

        long long operations = 0 ;
        vector<long long> prefix(nums.size() , 0 ) ; 
        prefix[0] = nums[0] ; 
        if(freq == 1) return true ;

        for(int i = 1 ; i < nums.size() ; i++ ){

            prefix[i] =prefix[i-1] + nums[i] ; 

        }

    for(int i = nums.size() - 1 ; i >= freq - 1 ; i-- ){

        if( i - freq < 0  ){
            operations =  (long long)nums[i] * (freq-1) - (prefix[i-1] ) ; 
        }

     else operations = (long long)nums[i] * (freq-1) - (prefix[i-1] - prefix[i - freq ]) ; 

     if(operations <=k ) return true ;

    }
     return false ; 

    }
    int maxFrequency(vector<int>& nums, int k) {
        
    sort(nums.begin() , nums.end() ) ; 

    int l = 1 ;
    int r = nums.size()  ;
    int ans = 0 ; 

    while( l <= r ){

     int mid = l + ( r-l )/2 ;

     if(check(nums , mid , k )){

      l = mid + 1;
      ans = mid ;

     }
     else {
        r = mid - 1 ; 
     }

    }
      return ans ;

    }
};