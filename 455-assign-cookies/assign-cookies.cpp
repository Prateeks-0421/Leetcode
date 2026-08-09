class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
     sort(s.begin() , s.end() ) ;
     sort(g.begin() , g.end());
     int count = 0 ; 
     int prevtarget = -1 ; 

     for(int i = 0 ; i < g.size() ; i++ ){

        if(s.size() == 0 )break ; 

      int l = prevtarget + 1 ;
      int r = s.size() - 1 ; 
      int target = g[i] ;
      int ans = -1 ; 

      while( l <= r ){
        int mid = l + ( r - l)/ 2 ;

       
         if(s[mid] >= target ){

           r = mid - 1 ;
           ans = mid ; 

        }
      else {
        l = mid + 1 ;

      }
 
      }
      if( ans != -1 ){
        count++ ; 
        // s.erase(s.begin() + ans ) ; 
        prevtarget = ans ; 

      }
      else return count ; 

     }

    return count ; 

    }
};