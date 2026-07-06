

    // trans = DP for the current position.
    // pref = prefix sum of previous DP.
    //ans[j] = number of valid arrays formed so far whose last element is exactly j.

    // TC=O(n*5000);
    // SC=O(3*5000);
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    const int mod=1e9+7;
    int countArrays(vector<int>& digitSum) {
        int n=digitSum.size();
        
// Precompute digit sum for every number from 0 to 5000.
        vector<int>dSum(5001,0);
        for(int i=0;i<=5000;i++){
            int x=i;
            while(x>0){
                dSum[i]+=(x%10)%mod;
                x=x/10;
            }
        }

        vector<int>ans(5001,0);ans[0]=1;
        
        for(int i=0;i<n;i++){

            vector<int>trans(5001,0);
            int pref=0;

            for(int j=0;j<=5000;j++){
                pref=(pref+ans[j])%mod;

                if(dSum[j]!=digitSum[i]) continue;

                trans[j]=pref;
            }

            ans=trans;
        }

        int result=0;

        for(int i=0;i<=5000;i++){
            result=(result+ans[i])%mod;
        }

        return result;
        
    }
};