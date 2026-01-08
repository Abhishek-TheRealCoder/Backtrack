// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination 
// twice, and the combinations may be returned in any order.

 

// Example 1:
// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.
// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

#include<bits/stdc++.h>
using namespace std;

void solve(int idx,int n, vector<int>&arr,int target,vector<vector<int>>&ans,vector<int>&res,int k){
    if(k == 0 && target == 0){
        ans.push_back(res);
        return ;
    }

    for(int i = idx;i < n;i++){
        if(arr[idx] <= target){
            res.push_back(arr[i]);
            solve(i+1,n,arr,target-arr[i],ans,res,k-1);
            //backtrack
            res.pop_back();
        }
    }
    return;
}

vector<vector<int>> combinationSum3(int k, int target) {
    vector<int>arr={1,2,3,4,5,6,7,8,9};
    int n = arr.size();
    vector<vector<int>>ans;
    vector<int>res;
    solve(0,n,arr,target,ans,res,k);
    return ans;
}

int main(){
    int k = 3;
    int target = 9;
    vector<vector<int>>ans = combinationSum3(k,target);
    for(vector<int>res:ans){
        for(auto x:res){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}