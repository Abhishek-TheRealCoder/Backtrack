// Given an array of distinct integers candidates and a target integer target, return a list of all 
// unique combinations of candidates where the chosen numbers sum to target. You may return the 
// combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. 
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target 
// is less than 150 combinations for the given input.

// Example 1:
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []

#include<bits/stdc++.h>
using namespace std;

void solve(int index,int n, int target, vector<int>&arr,vector<vector<int>>&res,vector<int>&ans){
    if(0 == target){
        res.push_back(ans);
        return;
    }
    
    for(int i = index ;i < n;i++){
        if(arr[i] <= target){
            ans.push_back(arr[i]);
            solve(i,n,target-arr[i],arr,res,ans);
            ans.pop_back();
        }
    }
    // // include
    // if(arr[i] >= target){
    //     ans.push_back(arr[i]);
    //     solve(i,target - arr[i],arr,res,ans);
    // }
    // // exclude
    // solve(i+1,target,arr,res,ans);
    // ans.pop_back();
    return;
}


vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>>res;
    vector<int>ans;
    int sum = 0;
    solve(0,n,target,arr,res,ans);
    return res;
}

int main(){
    vector<int>arr = {2,3,6,7};
    int k = 7;
    vector<vector<int>>ans = combinationSum(arr,k);
    for(vector<int>res:ans){
        for(auto x: res){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}