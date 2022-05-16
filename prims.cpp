#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define N 5
int minindex(int key[],bool mstset[]){
    int min_inde;
    int min_val=INT_MAX;
    for(int i=0;i<N;i++){
        if(mstset[i]==false && min_val>key[i]){
            min_inde=i;
            min_val=key[i];
        }
    }
    return min_inde;

}

void printmax(int parent[],int graph[N][N]){
    for(int i=1;i<N;i++){
        cout<<parent[i]<<" -> "<<i<<"  cost:"<<graph[parent[i]][i]<<endl;
    }

}

void MStmain( int graph[N][N]){
    int parent[N];
    int key[N];
    bool mstset[N];
    for(int i=0;i<N;i++)key[i]=INT_MAX;
    for(int i=0;i<N;i++)mstset[i]=false;
  key[0]=0;
  parent[0]=-1;
    for(int i1=0;i1<N-1;i1++){

        int mindex_val=minindex(key,mstset);
        cout<<mindex_val<<endl;
        mstset[mindex_val]=true;
        for(int i=0;i<N;i++){
            if(graph[mindex_val][i]&&mstset[i]==false&&key[i]>graph[mindex_val][i]){
                key[i]=graph[mindex_val][i];
                parent[i]=mindex_val;
            }
        }

    }
    printmax(parent,graph);
}

int main(){
    int graph[N][N] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    MStmain(graph);
}