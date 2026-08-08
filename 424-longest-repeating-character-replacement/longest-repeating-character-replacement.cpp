class Solution {
public:
    int characterReplacement(string s, int k) {
        
  int i = 0 ;
  int j = 0 ;
  int ans = 0 ; 

  unordered_map<int,int> freq ; 
  int maximum = 0 ; 

  while( j < s.size() ){
  

   freq[s[j]]++ ; 
  
    maximum = max(maximum , freq[s[j]] ) ; 
   

   if( j - i + 1 > maximum + k ){

    while( j - i + 1 > maximum + k ){

        freq[s[i]]-- ;
        i++ ; 
    }

   }
       
    ans = max( ans , j - i + 1 ) ;
   j++ ;

  }
  return ans ; 

    }
};