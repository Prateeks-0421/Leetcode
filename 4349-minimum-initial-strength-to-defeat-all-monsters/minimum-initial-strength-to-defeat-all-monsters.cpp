class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        
         vector<long long> diff(monsters.size() , 0 ) ; 
      for(int i = 0 ; i < boosts.size() ; i++ ){

         diff[boosts[i][0]] += boosts[i][2] ; 

         if( boosts[i][1] + 1 < monsters.size()) {
         diff[boosts[i][1] + 1 ] -= boosts[i][2] ; 
         }

      }

     vector<long long> bonus(diff.size() , 0) ;
     long long curr = 0 ; 

     for(int i = 0 ; i < diff.size() ; i++ ){
        curr = curr + diff[i] ; 
        bonus[i] = curr ;  

     } 
     long long strength = 0 ; 
    for(int i = monsters.size() - 1 ; i >= 0 ; i-- ){

     if(bonus[i] > monsters[i] and strength == 0 ){
        continue ; 
     }   

     if(strength == 0 ){
        long long paras =  (monsters[i] - bonus[i]) ;
        strength = min(strength + (long long)monsters[i] , paras) ; 
          continue ; 
     }

     strength = strength + monsters[i] ; 

      if( bonus[i] < monsters[i] and strength < (monsters[i] - bonus[i])  ){
        strength =  (monsters[i] - bonus[i]) ; 
     }

    }
     return strength ; 
    }
};