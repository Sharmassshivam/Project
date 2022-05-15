#include<bits/stdc++.h>
using namespace std;

class Nqueen{
    public:
    int nq[100][100];
    int n;
    void printarr(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<nq[i][j]<<" ";
            }
            cout<<endl;
        }

    }

    bool isSafe(int c,int r){
        for(int i=0;i<c;i++){
            if(nq[r][i]==1)return false;
        }
        for(int i=r, j=c;i>-1&&j>-1;i--,j--){
             if(nq[i][j]==1)return false;
        }
        for(int i=r, j=c;i<n&&j>-1;i++,j--){
             if(nq[i][j]==1)return false;
        }
        return true;


 
    }

    bool backtrac(int c,int tem){
        if(tem==n){
            printarr();
            return true;
        }
        for(int i=0;i<n;i++){
            if(isSafe(c,i)){
                nq[i][c]=1;
                 if(backtrac(c+1,tem+1)){
                     return true;
                 }
                nq[i][c]=0;
            }
        }
        return false;
    }

};

int main(){

    Nqueen q1;
    cout<<"Enter the size of board\n";
    int x;cin>>x;
    q1.n=x;
    q1.backtrac(0,0);
}


