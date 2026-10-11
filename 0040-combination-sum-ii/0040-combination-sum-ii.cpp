class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, int index,
               vector<int>& current) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);

            solve(candidates, target - candidates[i], i + 1, current);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {
        sort(candidates.begin(), candidates.end());

        ans.clear();
        vector<int> current;

        solve(candidates, target, 0, current);

        return ans;
    }
};