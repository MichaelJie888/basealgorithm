class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result;
	unordered_map<int, int> thenum;
	for (int i = 0; i < nums.size(); i++){
		if (thenum.count(target - nums[i])){
			result.push_back(i);
			result.push_back(thenum[target - nums[i]]);
			break;
		}
		thenum[nums[i]] = i;
	}
	return result;
    }
};