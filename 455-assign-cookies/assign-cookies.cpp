class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int left = 0;

        for (int i = 0; i < g.size(); i++) {

            int l = left;
            int r = s.size() - 1;
            int ans = -1;

            while (l <= r) {

                int mid = l + (r - l) / 2;

                if (s[mid] >= g[i]) {
                    ans = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }

            if (ans == -1)
                break;

            count++;
            left = ans + 1;
        }

        return count;
    }
};