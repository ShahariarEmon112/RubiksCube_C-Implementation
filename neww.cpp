#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
typedef long double ld;
typedef unsigned ll ul;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector<int>
#define no cout<<"NO"<<endl;
#define yes cout<<"YES"<<endl;
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.rbegin(),a.rend())
#define pb push_back
#define pob pop_back
//char cube[6][4];
char S1[2][2],S1p[2][2],S2[2][2],S2p[2][2],S3[2][2],S3p[2][2];
void start(){
    rep(i,0,2){
        for(int j=0;j<2;j++){
            S1[i][j]='W';;
            S1p[i][j]='G';;
            S2[i][j]='R';
            S2p[i][j]='B';
            S3[i][j]='O';
            S3p[i][j]='Y';
        }
    }
}
void operation(char op){
    char t1,t2;
    if(op=='U'){
        t1=S3[0][0];t2=S3[0][1];
        S3[0][0]=S1[0][0];S3[0][1]=S1[0][1];
        S1[0][0]=t1;S1[0][1]=t2;
    }
    else if(op=='D'){
        t1=S3p[1][0];t2=S3p[1][1];
        S3p[1][0]=S1[1][0];S3p[1][1]=S1[1][1];
        S1[1][0]=t1;S1[1][1]=t2;
    }
    else if(op=='R'){
        t1=S2p[0][1];t2=S2p[1][1];
        S2p[0][1]=S1[1][0];S2p[1][1]=S1[1][1];
        S1[1][0]=t1;S1[1][1]=t2;
    }
    else if(op=='L'){
        t1=S2[0][0];t2=S2[1][0];
        S2[0][0]=S1[1][0];S2[1][0]=S1[1][1];
        S1[1][0]=t1;S1[1][1]=t2;
    }
}
void printt(string name,char f[2][2]){
    cout<<name<<":"<<endl;
    rep(i,0,2){
        rep(j,0,2) cout<<f[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void sequence(){
    for(int i=0;i<16;i++) operation('U');
    for(int i=0;i<16;i++) operation('D');
    for(int i=0;i<16;i++) operation('R');
    for(int i=0;i<16;i++) operation('L');
}
void solve(){
    start();sequence();//16 ta move dibo
    int n;cin>>n;
    rep(i,0,n){
        int a;char op;cin>>a>>op;
        operation(op);
    }
    printt("S1 (Front)",S1);
    printt("S1' (Back)",S1p);
    printt("S2 (Left)",S2);
    printt("S2' (Right)",S2p);
    printt("S3 (Top)",S3);
    printt("S3' (Bottom)",S3p);
}
int main()
{
    FASTIO;int tt=1;//cin>>tt;
    while(tt--){
        solve();
    }
}
