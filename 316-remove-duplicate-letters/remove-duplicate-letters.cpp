class Solution {
public:
    string removeDuplicateLetters(string s) {
        
    unordered_map<int,int> freq ; 
    vector<int>pushed(26 , 0 ) ; 

    for(int i = 0 ; i < s.size() ; i++ ){

        freq[s[i]]++ ; 

    }
    stack<int> st ;

    for(int i = 0 ; i < s.size() ; i++ ){

    while(!st.empty()  and st.top() > s[i] and freq[st.top()] > 0 and !pushed[s[i] - 'a'] ) {
        //   freq[st.top()]-- ; 
          pushed[st.top() - 'a'] = 0 ; 
          st.pop() ; 
    }
      freq[s[i]]-- ; 
     if(pushed[s[i] - 'a'] ) continue ; 
    st.push(s[i]) ; 
    pushed[s[i] - 'a'] = 1 ; 

    } 

    string str ;

    while(!st.empty()){

    str.push_back(st.top()); 
    st.pop() ; 

    }

    reverse(str.begin() , str.end()) ;

    return str ; 

    }
};