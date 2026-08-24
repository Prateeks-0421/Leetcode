class Solution {
public:

    int dp[11][2][1024][2];

    int solve(vector<int>& nums,
              int i,
              bool tight,
              int mask,
              bool started) {

        // Finished constructing the number
        if(i == nums.size()) {
            return started;
        }

        // Check DP
        if(dp[i][tight][mask][started] != -1) {
            return dp[i][tight][mask][started];
        }

        int limit = tight ? nums[i] : 9;

        int ans = 0;

        for(int d = 0; d <= limit; d++) {

            bool newtight =
                tight && (d == nums[i]);

            // Leading zero
            if(!started && d == 0) {

                ans += solve(
                    nums,
                    i + 1,
                    newtight,
                    mask,
                    false
                );

                continue;
            }

            // Digit already used
            if(mask & (1 << d)) {
                continue;
            }

            int newmask =
                mask | (1 << d);

            ans += solve(
                nums,
                i + 1,
                newtight,
                newmask,
                true
            );
        }

        return dp[i][tight][mask][started] = ans;
    }


    int countSpecialNumbers(int n) {

        vector<int> nums;

        while(n > 0) {
            nums.push_back(n % 10);
            n /= 10;
        }

        reverse(nums.begin(), nums.end());

        memset(dp, -1, sizeof(dp));

        return solve(
            nums,
            0,
            true,
            0,
            false
        );
    }
};