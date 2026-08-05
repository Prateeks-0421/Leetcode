class Solution {
public:
    string minWindow(string s, string t) {
        
    unordered_map<int,int> freq ;
     unordered_map<int,int> window ; 

    for(int i = 0 ; i < t.size() ; i++ ){
        freq[t[i]]++ ; 
    }
    int need = freq.size() ; 

    int i = 0 ;
    int j = 0 ;
    int ans = INT_MAX ; 
    int have = 0 ; 
    int startindex = 0 ;
    int endindex = 0 ;

    while( j < s.size()){

    window[s[j]]++ ;   

    if(window[s[j]] == freq[s[j]]){
         have = have + 1 ; 
    }

     if(need == have ){
      
        while( need == have ){

             window[s[i]]-- ; 
             if(freq[s[i]] > window[s[i]]){
                have = have - 1 ; 
                 break ; 
             }
            i++ ; 
        }

     if( ans > j - i + 1 ){
      startindex = i ;
      endindex = j ;
      ans = j - i + 1 ; 

     }
      i++ ; 

     }
     j++ ; 

    }
    // cout<<ans<<endl ; 

    if(ans == INT_MAX) return "" ; 

    return s.substr(startindex , endindex - startindex + 1 ) ;

    }
};