class Solution {
public:
    bool checkInclusion(string p , string s ) {
        
    unordered_map<int,int> freq ; 
    unordered_map<int,int> window ; 
    vector<int> ans ;

    for(int i = 0 ; i < p.size() ; i++ ){

     freq[p[i]]++ ; 

    }
     int need = freq.size() ; 

    int i = 0 ; 
    int j = 0 ; 

    while( j < s.size()){

      window[s[j]]++ ; 

     bool flag = true ; 
     for(int k = 0 ; k < 26 ; k++ ){
        if(freq[k+'a'] != window[k + 'a']){
            flag = false ; 
        }
     }

     if(flag){

       ans.push_back(i) ; 
       window[s[i]]-- ; 
       i++ ; 

     }
    else if( j - i + 1 == p.size()) {
      window[s[i]]-- ; 
       i++ ; 
     }

    j++ ;  

    }
    return ans.size() > 0 ; 
         

    }
};