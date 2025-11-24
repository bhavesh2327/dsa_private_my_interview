#include <bits/stdc++.h>
using namespace std;

/* --------------------------------------------------------------------
   Approach 1: Brute Force (O(n²))
-------------------------------------------------------------------- */
vector<int> removeDuplicatesBruteForce(vector<int> arr) {
    vector<int> result;
    for(int i = 0; i < arr.size(); i++) {
        bool found = false;
        for(int j = 0; j < result.size(); j++) {
            if(arr[i] == result[j]) {
                found = true;
                break;
            }
        }
        if(!found) result.push_back(arr[i]);
    }
    return result;
}

/* --------------------------------------------------------------------
   Approach 2: Sorting + Linear Scan (O(n log n))
-------------------------------------------------------------------- */
vector<int> removeDuplicatesSorting(vector<int> arr) {
    vector<int> result;
    
    if(arr.empty()) return result;
    
    sort(arr.begin(), arr.end());
    result.push_back(arr[0]);
    
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] != arr[i - 1])
            result.push_back(arr[i]);
    }
    return result;
}

/* --------------------------------------------------------------------
   Approach 3: Using Hash Set (O(n))
-------------------------------------------------------------------- */
vector<int> removeDuplicatesHashSet(vector<int> arr) {
    unordered_set<int> s;
    vector<int> result;

    for(int x : arr) {
        if(!s.count(x)) {
            s.insert(x);
            result.push_back(x);
        }
    }
    return result;
}

/* --------------------------------------------------------------------
   Approach 4: Two Pointer (Optimized for Sorted Array)
   Time: O(n), Space: O(n) (if storing new array), or O(1) in-place
-------------------------------------------------------------------- */
vector<int> removeDuplicatesTwoPointer(vector<int> arr) {
    vector<int> result;
    if(arr.empty()) return result;

    sort(arr.begin(), arr.end()); // Ensure sorted
    result.push_back(arr[0]);
    
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] != arr[i - 1])
            result.push_back(arr[i]);
    }
    return result;
}

/* --------------------------------------------------------------------
   BONUS: Floyd’s Cycle Detection (Find Duplicate in linked-array)
   NOT for removing duplicates — Just finds repeated element.
-------------------------------------------------------------------- */
int findDuplicateFloyd(vector<int>& arr) {
    int slow = arr[0];
    int fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

/* --------------------------------------------------------------------
   Helper: Print Vector
-------------------------------------------------------------------- */
void printVector(const vector<int>& v) {
    for(int x : v) cout << x << " ";
    cout << endl;
}

/* --------------------------------------------------------------------
   Main: Test All Approaches
-------------------------------------------------------------------- */
int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5};

    cout << "\nOriginal Input: ";
    printVector(arr);

    cout << "\n1️⃣ Brute Force Result: ";
    printVector(removeDuplicatesBruteForce(arr));

    cout << "2️⃣ Sorting + Scan Result: ";
    printVector(removeDuplicatesSorting(arr));

    cout << "3️⃣ Hash Set Result: ";
    printVector(removeDuplicatesHashSet(arr));

    cout << "4️⃣ Two Pointer (Optimized) Result: ";
    printVector(removeDuplicatesTwoPointer(arr));

    // Only print Floyd result if input follows linked structure rules
    vector<int> floydTest = {1,3,4,2,2}; // Example valid structure
    cout << "\n🎁 Floyd's Cycle Detection (Duplicate Finder) Input: ";
    printVector(floydTest);
    cout << "Duplicate Found: " << findDuplicateFloyd(floydTest) << endl;

    return 0;
}
