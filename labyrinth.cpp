#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
typedef pair<int,int>pii;
int n, m;

//string graph
vector<string>g;

//visited array
int visited[N][N];

//level
int level[N][N];

//pair parent
pii parent[N][N];

//direction pair vector
vector<pii>direct={{0,-1},{0,1},{-1,0},{1,0}};

//valid
bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}
void bfs(int si,int sj){
    queue<pii>q;
    q.push({si,sj});
    visited[si][si]=true;
    level[si][sj]=0;
    while(!q.empty()){
        pair upair=q.front();
        int i=upair.first;
        int j=upair.second;
        q.pop();
        for(auto d:direct){
            int ni=i+d.first;
            int nj=i+d.second;
            if(isValid(ni, nj)&& !visited[ni][nj]&& g[i][j]!='#'){
                q.push({ni,nj});
                visited[ni][nj]=true;
                level[ni][nj]=level[i][j]+1;
                parent[ni][nj]={i,j};
                
            }
        }
    }

}
int main(){
    int si,sj, di, dj;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        for(int j=0; j<m;j++){
            if(x[j]=='A'){
                si=i, sj=j;
            }
            if(x[j]=='B'){
                di=i, dj=j;
            }
        }
        g.push_back(x);

    }
    bfs(si,sj) ;
    
    //level print
    if(level[di][dj]!=0){
        cout<<"YES"<<endl;
        cout<<level[di][dj]<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    vector<pii>path;
    pii curr={di,dj};
    while(!(curr.first==si && curr.second==sj)){
        path.push_back(curr);
        curr=parent[curr.first][curr.second];
    }

    path.push_back({si,sj});

    //reverse
    reverse(path.begin(), path.end());
    //path print
    for(auto p:path){
        cout<<p.first<<" "<<p.second<<endl;
    }

    //direction print
    for(int i=1; i<path.size(); i++){
        //path [i-1] and path[i]
        if(path[i-1].first==path[i].first){
            if(path[i-1].second==path[i].second-1){
                cout<<"R";
            }
            else{
                cout<<"L";
            }
        }
        else{
            if(path[i-1].first==path[i].first-1){
                cout<<"D";
            }
            else{
                cout<<"U";
            }

        }
    }
    cout<<level[di][dj]<<" ";
    return 0;
}