class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int t;
       
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = i ; j < matrix.size() ; j++){
                t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            } }
        int sum;
       for(int i = 0 ; i < matrix.size() ; i++){
         for(int j = 0 ; j < matrix.size()/2 ; j++){
             sum = matrix[i][j] ;
             matrix[i][j] = matrix[i][matrix.size() - 1 - j];
             matrix[i][matrix.size() - 1 - j] = sum; }
       } }
};