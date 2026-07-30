class Solution {
public:
    int sumOfMultiples(int n) {

     int count = 0 ;   
        
    for(int i = 1 ; i <= n ; i++ ){

      if(i % 7 == 0 or i % 3 == 0 or i % 5 == 0 ) count = count + i ; 

    }
    return count ; 

    }
};