class Solution {
public:
    bool isAnagram(string s, string t) {
        // approach 1 
        // sort(begin(s),end(s));
        // sort(begin(t),end(t));

        // return s == t ;

        // approach 2 
        // Step 1: Create an array to store count of each letter (a–z)
vector<int> count(26, 0);


for (char ch : s) {
    count[ch - 'a']++;
}


for (char ch : t) {
    count[ch - 'a']--;
}


for (int i = 0; i < 26; i++) {
    if (count[i] != 0) {
        return false;  
    }
}

return true;  



    }
};