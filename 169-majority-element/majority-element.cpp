class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //approach1
    //     int n = nums.size();

    //     for (int i = 0; i < n; i++) {
    //         int count = 0;

    //         for (int j = 0; j < n; j++) {
    //             if (nums[i] == nums[j]) {
    //                 count++;
    //             }
    //         }

    //         if (count > n / 2) {
    //             return nums[i];
    //         }
    //     }

    //     return -1;
    // }

    //approach2 using the hashmaps
     unordered_map<int, int> freq;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;

            if (freq[nums[i]] > n / 2) {
                return nums[i];
            }
        }

        return -1; 
    }
};