class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {

     vector<int> ans(nums.size() , 0 ) ;

     stack<int> st ;

     int i = nums.size() - 1 ;

     while( i >= 0 ){

      while( !st.empty() and nums[st.top()] <= nums[i]){
        st.pop() ; 
      }

      if(!st.empty()){
        ans[i] = st.top() - i ; 

       }

       st.push(i) ;
       i-- ; 

     }

     return ans ; 
    }
};