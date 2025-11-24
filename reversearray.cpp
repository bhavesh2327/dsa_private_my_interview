#include <bits/stdc++.h>
using namespace std;

/* ============================================================
   📌 Approach 1: Two-Pointer (In-Place)
   Time: O(n), Space: O(1)
============================================================ */
void reverseTwoPointer(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

/* ============================================================
   📌 Approach 2: For Loop Swap (In-Place)
   Time: O(n), Space: O(1)
============================================================ */
void reverseForLoop(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - i - 1]);
    }
}

/* ============================================================
   📌 Approach 3: Using Extra Array (Not In-Place)
   Time: O(n), Space: O(n)
============================================================ */
vector<int> reverseExtraArray(vector<int> arr) {
    vector<int> result;
    for(int i = arr.size() - 1; i >= 0; i--)
        result.push_back(arr[i]);
    return result;
}

/* ============================================================
   📌 Approach 4: Recursive Approach
   Time: O(n), Space: O(n) (recursion stack)
============================================================ */
void reverseRecursiveHelper(vector<int>& arr, int left, int right) {
    if(left >= right) return;
    swap(arr[left], arr[right]);
    reverseRecursiveHelper(arr, left + 1, right - 1);
}
void reverseRecursive(vector<int>& arr) {
    reverseRecursiveHelper(arr, 0, arr.size() - 1);
}

/* ============================================================
   📌 Approach 5: STL reverse()
   Time: O(n), Space: O(1)
============================================================ */
void reverseSTL(vector<int>& arr) {
    reverse(arr.begin(), arr.end());
}

/* ============================================================
   📌 Approach 6: Swap Using Arithmetic (⚠ Overflow Risk)
   Time: O(n), Space: O(1)
============================================================ */
void reverseArithmetic(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        arr[left] = arr[left] + arr[right];
        arr[right] = arr[left] - arr[right];
        arr[left] = arr[left] - arr[right];
        left++, right--;
    }
}

/* ============================================================
   Helper: Print Array
============================================================ */
void printArray(vector<int> arr) {
    for(int x : arr) cout << x << " ";
    cout << endl;
}

/* ============================================================
   MAIN: Demonstrating All Approaches
============================================================ */
int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    cout << "\n🔹 Original Array: ";
    printArray(arr);

    vector<int> arr1 = arr;
    reverseTwoPointer(arr1);
    cout << "1️⃣ Two Pointer:      ";
    printArray(arr1);

    vector<int> arr2 = arr;
    reverseForLoop(arr2);
    cout << "2️⃣ For Loop:         ";
    printArray(arr2);

    cout << "3️⃣ Extra Array:      ";
    printArray(reverseExtraArray(arr));

    vector<int> arr4 = arr;
    reverseRecursive(arr4);
    cout << "4️⃣ Recursive:        ";
    printArray(arr4);

    vector<int> arr5 = arr;
    reverseSTL(arr5);
    cout << "5️⃣ STL reverse():   ";
    printArray(arr5);

    vector<int> arr6 = arr;
    reverseArithmetic(arr6);
    cout << "6️⃣ Arithmetic Swap: ";
    printArray(arr6);

    return 0;
}
