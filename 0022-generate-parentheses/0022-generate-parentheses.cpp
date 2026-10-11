
class Solution {
public:
    void solve(string current, int open, int close, int n,
               vector<string>& ans) {

        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        if (open < n) {
            solve(current + '(', open + 1, close, n, ans);
        }

        if (close < open) {
            solve(current + ')', open, close + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", 0, 0, n, ans);
        return ans;
    }
};
