class Solution {
public:
    int trap(vector<int>& height) {
        
     int l = 0 ;
     int ans = 0 ; 

    vector<int> next(height.size() , -1 ) ; 
    stack<int> st ; 
    

    for(int i = height.size() - 1 ; i >= 0 ; i-- ){

     while( !st.empty() and height[st.top()] < height[i] ){

       st.pop() ; 

     }

    if(st.empty()) next[i] = -1  ; 
    
    else next[i] = st.top() ; 

    st.push(i) ; 

    }

    while( l < height.size()  ){

        int maxindex = -1 ;
        int maximum = 0 ; 

        if(next[l] == -1  ) {
           
       for(int i = l + 1 ; i < height.size() ; i++ ){
           if( maximum < height[i]){
             maximum = height[i]  ; 
            maxindex = i ; 
           }
       }

        }
        int r = 0  ; 
       if( next[l] != -1 )
       r = next[l] ; 
       else  r = maxindex ; 

       if( r == -1 ) break ;

       for(int i = l + 1 ; i < r ; i++ ){

        
        ans = ans + ( min(height[l],height[r]) - height[i]) ; 
       }
       l = r ; 

    }
    return ans ;

    }
};