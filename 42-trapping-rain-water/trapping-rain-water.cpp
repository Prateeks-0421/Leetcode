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
    int maxi = 0 ; 
    int maxiindex = height.size() - 1 ; 
    vector<int> smaller(height.size() , -1 ) ; 

    for(int i = height.size() - 1 ; i >= 0 ; i--){

        if( height[i] > maxi ){
            maxiindex = i ;
            maxi = height[i] ; 
        }
        smaller[i] = maxiindex ; 

    }



    while( l < height.size()  ){

        int maxindex = -1 ;
        int maximum = 0 ; 

        if(next[l] == -1  ) {
          
            if( l + 1 < height.size())
            maxindex = smaller[l+1]; 
       }

        // if(maxindex == -1 ) break ; 

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