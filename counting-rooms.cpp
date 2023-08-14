#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e3+7;
int n, m;

//string graph
vector<string>g;

//visited array
int visited[N][N];

//direction vector
vector<pii>direct={{0,1},{0,-1},{1,0},{-1,0}};

//valid
bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}
void dfs(int i, int j){
    if(!isValid(i,j)) return;
    if(visited[i][j]) return;
    if(g[i][j]=='#')  return;
    visited[i][j]=true;
    // dfs(i, j-1);
    // dfs(i, j+1);
    // dfs(i-1, j);
    // dfs(i+1, j);
    for(auto d: direct){
        dfs(i+d.first, j+d.second);
    }
}
int main(){
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        g.push_back(x);

    }
    int ct=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]) continue;
            if(g[i][j]=='#') continue;
            dfs(i,j);
            ct++;

        }
    }
    cout<<ct<<endl;    
    return 0;
}