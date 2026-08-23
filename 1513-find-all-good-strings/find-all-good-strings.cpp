class Solution {
public:

    const int MOD = 1000000007;

    string evil;
    int n, m;

    vector<vector<int>> transition;

    vector<int> buildLPS() {

        vector<int> lps(m, 0);

        int len = 0;

        for(int i = 1; i < m; ) {

            if(evil[i] == evil[len]) {

                lps[i] = ++len;
                i++;

            }
            else if(len != 0) {

                len = lps[len - 1];

            }
            else {

                lps[i] = 0;
                i++;
            }
        }

        return lps;
    }


    void buildTransition() {

        vector<int> lps = buildLPS();

        transition.assign(m, vector<int>(26));

        for(int state = 0; state < m; state++) {

            for(int c = 0; c < 26; c++) {

                char ch = 'a' + c;

                int j = state;

                while(j > 0 && evil[j] != ch) {
                    j = lps[j - 1];
                }

                if(evil[j] == ch) {
                    j++;
                }

                transition[state][c] = j;
            }
        }
    }


    long long solve(
        const string &bound,
        int pos,
        int matched,
        bool tight,
        vector<vector<vector<long long>>> &dp
    ) {

        if(pos == n) {
            return 1;
        }

        if(dp[pos][matched][tight] != -1) {
            return dp[pos][matched][tight];
        }

        char limit = tight ? bound[pos] : 'z';

        long long ans = 0;

        for(char ch = 'a'; ch <= limit; ch++) {

            int newMatched =
                transition[matched][ch - 'a'];

            // evil found
            if(newMatched == m) {
                continue;
            }

            bool newTight =
                tight && (ch == bound[pos]);

            ans += solve(
                bound,
                pos + 1,
                newMatched,
                newTight,
                dp
            );

            ans %= MOD;
        }

        return dp[pos][matched][tight] = ans;
    }


    string decrement(string s) {

        int i = n - 1;

        while(i >= 0 && s[i] == 'a') {
            s[i] = 'z';
            i--;
        }

        if(i >= 0) {
            s[i]--;
        }

        return s;
    }


    int findGoodStrings(
        int N,
        string s1,
        string s2,
        string Evil
    ) {

        n = N;
        evil = Evil;
        m = evil.size();

        buildTransition();

        // --------------------------------
        // F(s2)
        // --------------------------------

        vector<vector<vector<long long>>> dp2(
            n,
            vector<vector<long long>>(
                m,
                vector<long long>(2, -1)
            )
        );

        long long right =
            solve(s2, 0, 0, true, dp2);


        // --------------------------------
        // F(s1 - 1)
        // --------------------------------

        long long left = 0;

        bool allA = true;

        for(char c : s1) {

            if(c != 'a') {
                allA = false;
                break;
            }
        }

        if(!allA) {

            string previous = decrement(s1);

            vector<vector<vector<long long>>> dp1(
                n,
                vector<vector<long long>>(
                    m,
                    vector<long long>(2, -1)
                )
            );

            left =
                solve(previous, 0, 0, true, dp1);
        }

        return (right - left + MOD) % MOD;
    }
};