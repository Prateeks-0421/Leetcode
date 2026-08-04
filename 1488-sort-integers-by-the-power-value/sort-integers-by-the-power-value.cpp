class Solution {
public:
    int getKth(int lo, int hi, int k) {

     vector<vector<int>> power( hi - lo + 1 , vector<int> ( 2 , 0 )) ; 
     int l = 0 ; 
    for( int i = lo ; i <= hi; i++ ){

        int target = i ; 

       int count = 0 ; 
       while( target != 1){
        if(target % 2 == 0 ){
            target = target / 2;
        }
        else target = target * 3 + 1 ; 
        count++ ; 
       
    }
     power[l][0] = i ;
     power[l][1] = count ; 
     l++ ; 

    }
   sort(power.begin(), power.end(), [](vector<int>& a, vector<int>& b) {
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
     });

    return power[k-1][0] ; 

    }
};