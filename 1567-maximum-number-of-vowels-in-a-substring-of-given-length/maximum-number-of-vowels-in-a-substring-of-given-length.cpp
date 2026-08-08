class Solution {
public:
    int maxVowels(string s, int k) {

   int count = 0 ;
   int maximum = 0 ; 

   int i = 0 ;
   int j = 0 ;

   while( j < s.size()){

    if(s[j] == 'a' or s[j] == 'e' or s[j] == 'o' or s[j] == 'i' or s[j] == 'u'){

     count++ ; 

    }
    if( j - i + 1 == k ){

     maximum = max(count , maximum ) ; 
         if(s[i] == 'a' or s[i] == 'e' or s[i] == 'o' or s[i] == 'i' or s[i] == 'u'){

     count-- ; 

    }

    i++ ; 

    }

    j++ ;

   }

   return maximum ; 

    }
};