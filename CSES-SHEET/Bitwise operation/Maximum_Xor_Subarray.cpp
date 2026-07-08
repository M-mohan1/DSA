/*
If someone has achieved it before, it means it's possible.
Every accepted solution was once a wrong answer.
The expert in anything was once a beginner.
*/
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define rev(v) reverse(all(v))

#define ll long long
#define no cout<< "NO"<<endl;
#define yes cout<<"YES"<<endl;
#define pans cout<<ans<<endl;
#define pcnt cout<<cnt<<endl;

#define iv(v,n) vector<int>v(n); f(i,0,n) cin>>v[i]
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod=1e9+7 ;
                
int ans ;

class TrieNode {
public:
TrieNode* child[2];
};

TrieNode* getnode(){

        TrieNode* newnode=new TrieNode();
        
        newnode->child[0]=NULL;
        newnode->child[1]=NULL;

        return newnode;
}

void insert(TrieNode* root,int x){
    TrieNode* temp=root;
    
    for(int i=31;i>=0;i--){
        int bit=x>>i & 1;

        if(temp->child[bit]==NULL){
            temp->child[bit]=getnode();
        }

        temp=temp->child[bit];
    }
}

void search(TrieNode* root, int x){
    TrieNode* temp=root;

    int curr=0;
    for(int i=31;i>=0;i--){
        int bit=x>>i & 1;
        
        if(temp->child[1-bit]){
            curr|=1<<i;
            temp=temp->child[1-bit];
        }
        else temp=temp->child[bit];
    }
    ans=max(ans,curr);
}

void Testcases()
{
    int n;
    cin>>n;
    iv(arr,n);

    TrieNode* root = getnode();
    insert(root, 0);

    int pref = 0;

    for(int x : arr){
        pref ^= x;
        search(root, pref);
        insert(root, pref);
    }

    cout<<ans<<"\n";

}
int main()
{
    fast_io;
    int tt=1;
    while(tt--)
    {
        Testcases();
    }
}