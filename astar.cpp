#include<iostream>
#include<bits/stdc++.h>
#define N 3

using namespace std;

class Node{
    public:
    int a[N][N];
    int x;
    int y;
    int level=0;
    int cost=0;
    
};

Node * newnode(int b[N][N],int x,int y,int newx,int newy,int level){
    Node *tem= new Node;
    tem->level=level;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tem->a[i][j]=b[i][j];
        }
    }
    swap(tem->a[x][y],tem->a[newx][newy]);
    tem->x=newx;
    tem->y=newy;
    return tem;

}

void printmax(int a[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
} 

int cost(int a[N][N],int b[N][N]){
    int co=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(a[i][j]!=b[i][j] && a[i][j]!=0){
                co++;
            }
        }
    }
    return co;
}
bool issafe(int x,int y){
    if(x>=0&&x<3&&y>=0&&y<3)return true;
    return false;
}

struct comp{
    bool operator()(const Node *p,const Node *o){
        return (p->level+p->cost)>(o->level+o->cost);
    }
};

int amin[4]={0,0,-1,1};
int bmin[4]={-1,1,0,0};
void Astarmain(int initial[N][N],int x,int y,int goal[N][N]){
    priority_queue<Node *,vector<Node *>,comp>q1;
    Node * tem=newnode(initial,x,y,x,y,0);
     q1.push(tem);
     while(true){
         Node * cur=q1.top();
         q1.pop();
         cout<<endl;
           printmax(cur->a);
         if(cost(cur->a,goal)==0){
             return;
         }
         
         for(int i=0;i<4;i++){
             if(issafe(cur->x+amin[i],cur->y+bmin[i])){
                    Node *cur2=newnode(cur->a,cur->x,cur->y,cur->x+amin[i],cur->y+bmin[i],cur->level+1);
                    cur2->cost=cost(cur2->a,goal);
                    q1.push(cur2);
             }
         }

     }

}


int main(){
    int a[N][N];
    cout<<"Enter the initial state of array\n";
    int x=0,y=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
            if(a[i][j]==0){
                x=i;
                y=j;
            }

        }
    }
    cout<<"Enter the final state of array\n";
    int goal[N][N];
     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>goal[i][j];
            
        }
    }
    Astarmain(a,x,y,goal);


}