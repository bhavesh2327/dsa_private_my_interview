class Solution {
public:
    bool containsDuplicate(vector<int>& nums)  {
// // approach 1 O(N^2) 
//        int n = nums.size();
//        for(int i = 0; i<n; i++){
//         for(int j = i+1; j<n; j++){
//             if(nums[i] == nums[j])
//             {
//                 return true;
//             }
//         }
//        }
//         return false;

//APPROACH -2 USING THE SORTING METHOD // 
//   sort(nums.begin(), nums.end());
//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] == nums[i - 1])
//                 return true;
//         }
//         return false;
//     }

          unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
        }
        return false;
    }   
};