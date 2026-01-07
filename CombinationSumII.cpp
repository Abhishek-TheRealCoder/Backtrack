// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

#include<bits/stdc++.h>
using namespace std;

void solve(int idx,int n,vector<int>&arr,int target,vector<vector<int>>&ans,vector<int>&res){
    if(target == 0){
        ans.push_back(res);
        return ;
    }

    for(int i = idx;i < n;i++){
        if(i > idx && arr[i] == arr[i-1]) continue;
        if(target >= arr[i]){
            res.push_back(arr[i]);
            solve(i+1,n,arr,target-arr[i],ans,res);
            res.pop_back();
        }
    }
    return ;
}
vector<vector<int>> combinationSum2(vector<int>&arr, int target) {
    int n = arr.size();
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    vector<int>res;
    solve(0,n,arr,target,ans,res);
    return ans;
}

int main(){
    vector<int>arr = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>>ans = combinationSum2(arr,target);
    for(vector<int>res:ans){
        for(auto x : res){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}