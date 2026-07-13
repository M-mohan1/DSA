#include<bits/stdc++.h>
using namespace std;

// without dp TLE
class Solution {
public:
    vector<int>ans;
    unordered_map<string,int>skill_mp;
    vector<int>people_masks;
    vector<int>curr;
    int n;
    int m;

    void solve(int idx,vector<string>& req_skills,vector<vector<string>>& people,int mask){
        if(mask==(1<<n)-1){
            if(curr.size()<ans.size() || ans.empty()){
                ans=curr;
            }
            return ;
        }

        if(idx==m) return ;
        solve(idx+1,req_skills,people,mask);
        int person_mask=people_masks[idx];

        if ((mask | person_mask) != mask) {
            curr.push_back(idx);
            solve(idx + 1,req_skills,people,mask | person_mask);
            curr.pop_back();
        }
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n=req_skills.size();
        m=people.size();
        int mask=1<<n;

        skill_mp.clear();
        ans.clear();
        curr.clear();

        for(int i=0;i<n;i++){
            skill_mp[req_skills[i]]=i;
        }

        people_masks.assign(m,0);

        for (int i = 0; i < m; i++) {
            for (const string& skill : people[i]) {
                if (skill_mp.count(skill)) {
                    int bit_index = skill_mp[skill];
    
                    people_masks[i] = people_masks[i] | (1 << bit_index); 
                }
            }
        }
        solve(0,req_skills,people,0);

        return ans ;

    }
};

// memoization 

// think why memoize on above code not solve this problem . 
// why masking only on req skills solve it , see code below ;

class Solution {
public:
    vector<int> ans;
    vector<int> curr;
    vector<int> people_masks;
    vector<int> dp;
    unordered_map<string, int> skill_mp;
    int n;
    int m;

    void solve(int mask) {
        if (!ans.empty() && curr.size() >= ans.size()) {
            return;
        }

        if (mask == (1 << n) - 1) {
            ans = curr;
            return;
        }

        if (curr.size() >= dp[mask]) {
            return; 
        }

        dp[mask] = curr.size();

        int missing_skill = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) { 
                missing_skill = i;
                break;
            }
        }

        for (int i = 0; i < m; i++) {
            if (people_masks[i] & (1 << missing_skill)) {
                
                curr.push_back(i); 
                solve(mask | people_masks[i]); 
                curr.pop_back(); 
                
            }
        }
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();
        m = people.size();

        skill_mp.clear();
        ans.clear();
        curr.clear();
        dp.assign(1 << n, INT_MAX); 
        people_masks.assign(m, 0);

        for (int i = 0; i < n; i++) {
            skill_mp[req_skills[i]] = i;
        }

        for (int i = 0; i < m; i++) {
            for (const string& skill : people[i]) {
                if (skill_mp.count(skill)) {
                    int bit_index = skill_mp[skill];
                    people_masks[i] |= (1 << bit_index); 
                }
            }
        }
        
        solve(0);

        return ans;
    }
};