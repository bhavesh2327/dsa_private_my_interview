Problem Statement

Given an array of integers, move all 0s to the end while maintaining the relative order of non-zero elements.

✅ Example
Input:  [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]

🧠 Optimal Approach — Two-Pointer Method

Use a pointer left to track where non-zero elements should be placed.

Iterate through the array:

Whenever a non-zero is found, swap it with the value at left and increment left.

🧾 Code (C++)
class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int left = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[left]);
                left++;
            }
        }
    }
};

⏱️ Complexity
Measure	Value
Time Complexity	O(n)
Space Complexity	O(1) (in-place)
Order Preserved?	✔ Yes
🧪 Dry Run

Input:

[0, 1, 0, 3, 12]

Step	i	Operation	Result
0	0	Skip (0)	[0, 1, 0, 3, 12]
1	1	swap(1,0)	[1, 0, 0, 3, 12]
2	2	Skip (0)	[1, 0, 0, 3, 12]
3	3	swap(3,0)	[1, 3, 0, 0, 12]
4	4	swap(12,0)	[1, 3, 12, 0, 0]
🎉 Final Output
[1, 3, 12, 0, 0]
