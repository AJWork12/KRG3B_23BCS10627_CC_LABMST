/*Distinct Subsets
Difficulty: MediumAccuracy: 50.0%Submissions: 38K+Points: 4Average Time: 30m
You are given an array arr[] of positive integers (which may contain duplicates), your task is to find all the unique or distinct subsets of the array.

Note: You can return the subsets in any order, the driver code will print them in sorted order.

Examples:

Input: arr[] = [1, 5, 6]
Output: [[], [1], [1, 5], [1, 5, 6], [1, 6], [5], [5, 6], [6]]
Explanation: The number of all the possible subsets will be 2n.
Now the unique subsets are [], [1], [1, 5], [1, 5, 6], [1, 6], [5], [5, 6], [6].
Input: arr[] = [1, 2, 2]
Output: [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]
Explanation: The number of all the possible subsets will be 2n.
Now the unique subsets are [], [1], [1, 2], [1, 2, 2], [2], [2, 2].
Constraints
1 ≤ arr.size() ≤ 15
1 ≤ arr[i] ≤  105
*/

class Solution {
  public:
  
    void solve(int idx, vector<int>& arr, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);   
        for (int i=idx;i<arr.size();i++) {
            if (i > idx && arr[i]==arr[i - 1]) continue;
            curr.push_back(arr[i]);
            solve(i+1,arr,curr,ans);
            curr.pop_back(); 
        }
    }
    vector<vector<int>> findSubsets(vector<int>& arr) {
        sort(arr.begin(), arr.end()); 
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, arr, curr, ans);
        return ans;
    }
};