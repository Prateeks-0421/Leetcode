class Solution {
public:
    string sortVowels(string s) {
        
     unordered_map<char,int> freq ; 

     for(int i = 0 ; i < s.size() ; i++ ){


        if( s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' )
        freq[s[i]]++ ; 

     }
    
    vector<pair<char, int>> vec( freq.begin(), freq.end());

      sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
   
        return a.second < b.second; 
         
    });
    
   
   int k = vec.size() - 1 ; 

    for(int i = 0 ; i  < s.size() ; i++ ){

      if( s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' ){

        s[i] = vec[k].first ;

        vec[k].second-- ; 
        if( vec[k].second == 0 ) k-- ; 

      }

    }
    return s ; 

    }
};