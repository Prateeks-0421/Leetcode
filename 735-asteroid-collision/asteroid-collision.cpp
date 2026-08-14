class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

    stack<int> st ; 
    vector<int> ans ;

    for(int i = asteroids.size() - 1 ; i >= 0 ; i-- ){

       int temp = asteroids[i] ; 

      bool flag = 0 ; 

     while( !st.empty() and temp > 0 and  st.top() < 0  ){

         if( abs(temp) < abs(st.top()) ) {
               
               temp = st.top() ; 
         }
        else if( abs(temp) == abs(st.top()) ) {
               
               temp = -st.top() ; 
               st.pop() ; 
               flag = 1 ; 
               break ; 

         }

         st.pop() ;    

     }
     if(flag) continue ; 
     st.push(temp ); 

    }
    
    while( !st.empty() ) {
        
        ans.push_back(st.top() ) ; 
        st.pop() ; 
    }

     return ans ;
    }
};