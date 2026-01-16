class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // approach 1 
        int n = nums.size();
         int newlen = 2 * n;
         vector<int>ans(newlen);
         for(int i=0;i<n;i++){
            ans[i] = nums[i];
         }
         //start filling from n to newlen-1
         for(int i=0;i<n;i++){
            ans[n+i] = nums[i];
         }

         return ans;

    }
};