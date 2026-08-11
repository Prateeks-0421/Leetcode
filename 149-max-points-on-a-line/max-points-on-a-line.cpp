class Solution {
public:

    int gcd(int a, int b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    int maxPoints(vector<vector<int>>& points) {

        int n = points.size();

        if (n <= 2)
            return n;

        int answer = 0;

        for (int i = 0; i < n; i++) {

            unordered_map<string, int> freq;

            int best = 0;

            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(abs(dx), abs(dy));

                dx /= g;
                dy /= g;

                // Canonical sign
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                // Handle vertical line
                if (dx == 0)
                    dy = 1;

                // Handle horizontal line
                if (dy == 0)
                    dx = 1;

                string slope = to_string(dy) + "#" + to_string(dx);

                freq[slope]++;

                best = max(best, freq[slope]);
            }

            answer = max(answer, best + 1);
        }

        return answer;
    }
};