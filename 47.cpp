class Solution {
private:
  vector<vector<int>> ans;
  void permute(vector<int> nums, int start) {
    if (start == nums.size() - 1) {
      ans.push_back(nums);
      return;
    }
    for (int i = start; i < nums.size(); ++i) {
      if (i != start && nums[i] == nums[start]) continue;
      swap(nums[i], nums[start]);
      permute(nums, start + 1);
    }
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    permute(nums, 0);
    return ans;
  }
};