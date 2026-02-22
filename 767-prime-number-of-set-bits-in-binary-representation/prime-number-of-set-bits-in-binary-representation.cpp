class Solution {
public:
    int f(int a){
        if( a ==1)
        return 0;
        for(int i =2 ; i < a ; i++){
            if( a % i == 0 )
            return 0;
        }
        return 1;
    }
    int countPrimeSetBits(int left, int right) {
        int j = 0;
        int a =0;
        int m =0;
        while ( left + j <= right){
        int n = left + j;
        a =0;
        while ( n != 0 ){
            if( n % 2 == 1 )
            a++;
            n = n /2;
        }
        if ( f(a) == 1)
        m++;
        j++; }
        return m;
    }
};