class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     for(int i=0; i<nums.size(); i++)
         for(int j=0; j<nums.size(); j++)
             if(i!=j)
                 if(nums[i] + nums[j] == target){
                    vector<int> v = {i, j};
                    return v;
                 }
    }
};
