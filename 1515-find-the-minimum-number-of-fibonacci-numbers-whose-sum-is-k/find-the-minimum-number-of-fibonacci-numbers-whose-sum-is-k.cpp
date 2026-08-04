class Solution {
public:
    int findMinFibonacciNumbers(int k) {
            
    vector<int> vect ; 
    
     vect.push_back( 1 ) ; 
     vect.push_back( 1 ) ; 
     int i = 2 ; 
     while( 1 ){
         vect.push_back( vect[i-1] + vect[i-2]) ; 
         if( vect[i] > k )
          break ; i++ ; 
     }
    vect.pop_back() ; 
    long long  sum = 0 ; int cnt = 0 ; 
    for( int i = vect.size() - 1  ; i >= 0 ; i--){
         if( sum + vect[i] == k ){
            cnt++ ; break ; 
         }
         else if( sum + vect[i] < k ) {
            sum += vect[i] ; cnt++ ; 
         }
    }
    return cnt ; 
    }
};