class Solution {
public:
bool isPowerOfFour(int n) {
        if(n<=0)
        return false;
        while(n!=1){
        if(n % 2 == 0){
             n=n/2;
        } 
        else return false;
        }
       return true;
        
    }

    int binaryGap(int n) {
        int k = 0;
        int j = 0;
        int i = 0;
        int m = n;
        if( isPowerOfFour(n))
        return 0;
        while( m != 0){
            if( m % 2 == 1)
            break;
            i--;
            m = m/2;
        }
        while( n != 0 ){
            i++;
        if( n % 2 == 1){
            if( i - j > k)
                k = i - j ;
                j = i;
            }
            n = n /2;
        }
        return k;
    }
};