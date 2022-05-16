#include<bits/stdc++.h>
using namespace std;

class Assign1{
    private:
    map<int,set<int>>v1;

    public:
    void creategraph(int n){
        v1.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<"Is there any edge between "<<i<<"   "<<j<<endl;
                int x;cin>>x;
                if(x==1){
                    v1[i].insert(j);
                     v1[j].insert(i);
                     cout<<"Edge has been inserted successfully\n";

                }
            }
        }
    }

    void showGraph(){
        for(auto x:v1){
            cout<<x.first<<" ";
            for(auto y:x.second ){
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(vector<int>&vis,queue<int>&q1){
        if(q1.size()==0)return;
       
         cout<<q1.front()<<" ";
      
    
            int tem=q1.front();
             vis[q1.front()]=1;
                 q1.pop();
            for(auto x:v1[tem]){
                if(vis[x]==0){
                    q1.push(x);
                    vis[x]=1;
                }
            }
            bfs(vis,q1);
            return;
    
    }
    void dfs(int x,map<int,int>&v11){
        if(v11[x]==0){
            cout<<x<<" ";
            v11[x]=1;
            for(auto x1:v1[x]){
                if(v11[x1]==0){
                    dfs(x1,v11);
                }
            }
        }
    }

};

int main(){
    Assign1 q1;
   
   
     while(true){
        cout<<"1. Enter the graph\n2. Bfs on the graph\n3. Dfs on the graph\n4. Exit the whole function\n ";
        int x;cin>>x;
        if(x==1){
            cout<<"Enter no of edges\n";
            int tem;cin>>tem;
            q1.creategraph(tem);

        }
        else if(x==2){
            queue<int>q12;
            q12.push(0);
            vector<int>vis(7,0);
            vis[0]=1;
            q1.bfs(vis,q12);

        }
        else if(x==3){
               map<int,int>v11;
                  q1.dfs(0,v11);

        }
        else{
            break;
        }
    }

}