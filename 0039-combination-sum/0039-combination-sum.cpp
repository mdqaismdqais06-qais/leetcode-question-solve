class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, int index,
               vector<int>& current) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (index == candidates.size())
            return;

        if (candidates[index] <= target) {
            current.push_back(candidates[index]);

            solve(candidates, target - candidates[index],
                  index, current);

            current.pop_back();
        }

        solve(candidates, target, index + 1, current);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {
        ans.clear();
        vector<int> current;

        solve(candidates, target, 0, current);

        return ans;
    }
};