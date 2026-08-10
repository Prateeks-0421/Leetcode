class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int k = words.size() * words[0].size();
        int n = words[0].size();

             vector<int> ans;

        unordered_map<string, int> freq;
        for (int x = 0; x < words.size(); x++) {
            freq[words[x]]++;
        }

        for (int start = 0; start < n; start++){

            int i = start;
           int j = start;
          unordered_map<string, int> window;

           while (j + n <= s.size()) {

            string word = s.substr(j, n);

         
            if (!freq.contains(word)) {

                window.clear();

                j += n;
                i = j;

                continue;
            }

            window[word]++;

            
            while (window[word] > freq[word]) {

                string leftWord = s.substr(i, n);

                window[leftWord]--;

                i += n;
            }

            j += n;

        
            if (j - i == k) {

                ans.push_back(i);

                string leftWord = s.substr(i, n);

                window[leftWord]--;

                i += n;
            }
        }

        }

        return ans;
    }
};