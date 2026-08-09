class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
     sort(s.begin() , s.end() ) ;
     int count = 0 ; 

     for(int i = 0 ; i < g.size() ; i++ ){

        if(s.size() == 0 )break ; 

      int l = 0 ;
      int r = s.size() - 1 ; 
      int target = g[i] ;
      int ans = -1 ; 

      while( l <= r ){
        int mid = l + ( r - l)/ 2 ;

        if(s[mid] == target ){

          ans = mid ; 
          break ; 

        }
        else if(s[mid] > target ){

           r = mid - 1 ;
           ans = mid ; 

        }
      else {
        l = mid + 1 ;

      }
 
      }
      if( ans != -1 ){
        count++ ; 
        s.erase(s.begin() + ans ) ; 

      }

     }

    return count ; 

    }
};