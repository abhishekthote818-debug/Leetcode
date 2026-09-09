class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums, int index) {
        // Current subset ko answer mein add karo
        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {
            // Element choose karo
            temp.push_back(nums[i]);

            // Next element par jao
            solve(nums, i + 1);

            // Element remove karo (backtrack)
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};