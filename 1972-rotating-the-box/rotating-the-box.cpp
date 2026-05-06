class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& arr ) {

        int n = arr.size() ;
        int m = arr[0].size() ; 
        
    for(int i = 0 ;  i < n ; i++ ){

          int k = 1 ; 

        for( int j = m - 1   ; j > 0 ; j-- ){

           if( arr[i][j] == '.' and arr[i][j-1] == '#' ){

            arr[i][j - 1 + k ] = '#' ;
            arr[i][j-1] = '.' ; 

           } 
         
           else if( arr[i][j] == '.' and arr[i][j-1] == '.' ){

               k++ ; 

           } 
           else if( arr[i][j] == '*') k = 1 ; 


        }
    }   
      
      vector<vector<char>> transpose(m, vector<char>(n));

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        transpose[j][i] = arr[i][j];
    }

}   

    for(int i = 0 ; i < m  ; i++ ){

     for(int j = 0 ; j < n / 2; j++ ){

        swap(transpose[i][j] , transpose[i][n - 1 - j ]) ; 

     }

    }



return transpose ; 
    }
};