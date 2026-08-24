class Solution {
public:

    int n;
    int k;
    int target;

    vector<int> dp;

    bool solve(vector<int>& nums, int mask, int currSum) {

        // All elements have been used
        if(mask == (1 << n) - 1) {
            return true;
        }

        // Already calculated
        if(dp[mask] != -1) {
            return dp[mask];
        }

        for(int i = 0; i < n; i++) {

            // If already used
            if(mask & (1 << i))
                continue;

            // Can't exceed target
            if(currSum + nums[i] > target)
                continue;

            int newMask = mask | (1 << i);

            int newSum = currSum + nums[i];

            // Bucket completed
            if(newSum == target) {

                if(solve(nums, newMask, 0))
                    return dp[mask] = true;

            }
            else {

                if(solve(nums, newMask, newSum))
                    return dp[mask] = true;
            }
        }

        return dp[mask] = false;
    }


    bool canPartitionKSubsets(vector<int>& nums, int K) {

        n = nums.size();
        k = K;

        int total = 0;

        for(int x : nums)
            total += x;

        if(total % k != 0)
            return false;

        target = total / k;

        dp.assign(1 << n, -1);

        return solve(nums, 0, 0);
    }
};