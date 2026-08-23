class Solution {
public:

    const int MOD = 1000000007;

    long long solve(
        string &nums,
        int minimum,
        int maximum,
        int i,
        int sum,
        bool tight,
        vector<vector<vector<long long>>> &dp
    ) {

        if(i == nums.size()) {
            return (sum >= minimum && sum <= maximum);
        }

        if(dp[i][sum][tight] != -1)
            return dp[i][sum][tight];

        int limit = tight ? nums[i] - '0' : 9;

        long long ans = 0;

        for(int d = 0; d <= limit; d++) {

            int newSum = sum + d;

            if(newSum > maximum)
                continue;

            bool newTight =
                tight && (d == nums[i] - '0');

            ans = (
                ans +
                solve(
                    nums,
                    minimum,
                    maximum,
                    i + 1,
                    newSum,
                    newTight,
                    dp
                )
            ) % MOD;
        }

        return dp[i][sum][tight] = ans;
    }

    int count(
        string num1,
        string num2,
        int min_sum,
        int max_sum
    ) {

        // num1 = num1 - 1
        for(int i = num1.size() - 1; i >= 0; i--) {

            if(num1[i] == '0') {
                num1[i] = '9';
            }
            else {
                num1[i]--;

                if(i == 0 && num1[i] == '0')
                    num1.erase(num1.begin());

                break;
            }
        }

        vector<vector<vector<long long>>> dp1(
            num1.size(),
            vector<vector<long long>>(
                max_sum + 1,
                vector<long long>(2, -1)
            )
        );

        vector<vector<vector<long long>>> dp2(
            num2.size(),
            vector<vector<long long>>(
                max_sum + 1,
                vector<long long>(2, -1)
            )
        );

        long long right =
            solve(num2, min_sum, max_sum, 0, 0, true, dp2);

        long long left =
            solve(num1, min_sum, max_sum, 0, 0, true, dp1);

        return (right - left + MOD) % MOD;
    }
};