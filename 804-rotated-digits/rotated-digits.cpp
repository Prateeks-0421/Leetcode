class Solution {
public:
bool goodnumber(int n){

     int flag = 0 ; 

   while( n ){

    int digit = n % 10 ;

    if( digit == 3 or  digit == 7 or digit == 4 ){

       return false ;

    }
    else if( digit == 2 or digit == 5 or digit == 6 or digit == 9  ){
        flag = 1 ;
    }

    n = n / 10 ; 

   }
    return flag == 1 ; 

}
    int rotatedDigits(int n) {

        int count = 0 ; 

    for(int i = 1 ; i <= n ; i++ ){
        if(goodnumber(i)) count++ ; 
    }


    return count ;

    }
};