class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
    int minimum = piles[0] ; 
    int maximum = piles[0] ; 
    int ans = 0 ; 

    for(int i = 0 ; i < piles.size() ; i++ ){

      maximum = max( maximum , piles[i] ) ; 

    }
     int l = 1 ;
     int r = maximum ; 

     while( l <= r ){

      int mid = l + ( r - l )/2 ;

    long long hours = 0 ; 

    for(int i = 0 ; i < piles.size() ; i++ ){

      if(piles[i] % mid )  

      hours = hours + (piles[i] / mid ) + 1 ; 

      else hours = hours + (piles[i] / mid ) ;

    }

      if( hours > h ){
            l = mid + 1 ; 
      }
      else {

        r = mid - 1 ; 
        ans = mid ; 

      }

     }
     return ans ; 

    }
};