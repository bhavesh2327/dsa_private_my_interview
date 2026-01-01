➕ Plus One – Code Explanation
🔹 Problem Statement

You are given a non-empty array of digits representing a non-negative integer.
Each element of the array contains a single digit.
The digits are stored such that the most significant digit is at the beginning of the array.

The task is to add 1 to the number and return the resulting digits as an array.

🔹 Approach Used

This solution simulates manual addition (like how we add numbers on paper), handling the carry from right to left. 



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry  = 1;
        for(int i=digits.size()-1; i>=0; i--) { 
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum/10;
        }
                if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;


    }
};





🔹 Code Explanation
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {


Defines a class Solution

The function plusOne takes a vector of digits by reference

        int carry = 1;


We start with carry = 1 because we want to add 1 to the number

        for(int i = digits.size() - 1; i >= 0; i--) {


Loop starts from the last digit (least significant digit)

Moves from right to left

            int sum = digits[i] + carry;


Add the current digit and carry

            digits[i] = sum % 10;


Store the unit digit of the sum at the current position

            carry = sum / 10;


Update carry:

0 if sum < 10

1 if sum ≥ 10

        }


Loop continues until all digits are processed

        if (carry) {
            digits.insert(digits.begin(), 1);
        }


If carry is still 1 after the loop (example: 999 + 1)

Insert 1 at the beginning of the vector

        return digits;
    }
};


Return the updated vector containing the final result

🔹 Example Walkthrough

Input:

digits = [9, 9, 9]


Process:

9 + 1 = 10 → write 0, carry 1
9 + 1 = 10 → write 0, carry 1
9 + 1 = 10 → write 0, carry 1


Final Carry = 1 → Insert at front

Output:

[1, 0, 0, 0]

🔹 Time & Space Complexity
Complexity	Value
Time	O(n)
Space	O(1) (in-place, excluding output)
