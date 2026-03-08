class Solution {
public:
   string ans = "" ; 
    void solve(vector<string> & nums , string & str , int idx , int n ){
      bool flag = 0 ; 
      for(int i = 0 ; i < n ; i++){
        string temp = nums[i] ; 
         if(str == temp ) {
            flag = 1 ; 
             break ; 
         }
      }
      if(!flag) {
            ans = str ; 
            return ; 
      }
      if( idx >= n ) return ; 
       str[idx] = '1' ; 
       solve(nums , str , idx + 1 , n ) ; 
       str[idx] = '0' ; 
       solve(nums , str , idx + 1 , n ) ; 
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
       int n = nums.size() ; 
        string str = "" ;
        for(int i = 0 ; i < n ; i++){
            str += ('0') ;
        } 
        solve(nums , str , 0 , n ) ; 
        return ans ; 
    }
};