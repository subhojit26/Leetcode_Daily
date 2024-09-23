// 2707. Extra Characters in a String
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

// Return the minimum number of extra characters left over if you break up s optimally.

 

// Example 1:

// Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
// Output: 1
// Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

// Example 2:

// Input: s = "sayhelloworld", dictionary = ["hello","world"]
// Output: 3
// Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
 

// Constraints:

// 1 <= s.length <= 50
// 1 <= dictionary.length <= 50
// 1 <= dictionary[i].length <= 50
// dictionary[i] and s consists of only lowercase English letters
// dictionary contains distinct words



class Solution {
public:
    int solve(string s, int ind, unordered_map<string, int> mp, unordered_map<int, int> &memo){
        if(ind==s.length()){
            return 0;
        }
        if(memo.find(ind)!=memo.end()){
            return memo[ind];
        }
        int extra=INT_MAX;
        string tmp="";

        for(int i=ind;i<s.length();i++){
            tmp+=s[i];

            if(mp.find(tmp)!=mp.end()){
                extra=min(extra, solve(s,i+1,mp,memo));
            }
        }
        extra=min(extra, 1+solve(s, ind+1,mp,memo));
        return memo[ind]=extra;

    }
    int minExtraChar(string s, vector<string>& dictionary) {
       int ind=0;
       unordered_map<string, int> mp;
       for(auto &val:dictionary){
            mp[val]++;
       }
       unordered_map<int, int> mem;

       return solve(s, ind, mp, mem);
    }
};