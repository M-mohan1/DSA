#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        int n=s.size();

        stack<char>st;
        vector<int>cnt(26,0);
        for(auto &c:s){
            cnt[c-'a']++;
        }

        for(int i=0;i<n;i++){
            if(st.empty() || st.top()<=s[i]) st.push(s[i]);
            else{
                while(!st.empty() && st.top()>s[i] && cnt[st.top()-'a']>=2){
                    cnt[st.top()-'a']--;
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        string ans ="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        n =ans.size();
        while( n >= 2 && cnt[ans[n-1]-'a'] > 1){
            cnt[ans[n-1]-'a']--;
            ans.pop_back();
            n--;
        }

        return ans ;
    }
};