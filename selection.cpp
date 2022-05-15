#include<iostream>
#include<map>
using namespace std;

class selectionsort{
    private:
    int a[100];
    int size;
    public:

    selectionsort(){
        for(int i=0;i<100;i++){
            a[i]=0;
        }
        size=0;
    }
   void  takeinput(int n){
        size=n;
        for(int i=0;i<n;i++){
            cout<<"Enter the "<<i<<"th value of array\n";
            int x;cin>>x;
            a[i]=x;
        }
        cout<<"Elements have been inserted successfully\n";
    }

    void sortselection(){
        int b[100];
        for(int i=0;i<size;i++)b[i]=a[i];

        for(int i=0;i<size-1;i++){
            int mindex=i;
            for(int j=i+1;j<size;j++){
                if(b[mindex]>b[j]){
                    mindex=j;
                }
            }
            int tem=b[i];
            b[i]=b[mindex];
            b[mindex]=tem;
        }

        cout<<"The sorted array using selection sort is \n";
        for(int i=0;i<size;i++)cout<<b[i]<<" ";
        cout<<endl;
    }

};

int main(){
    selectionsort s1;
    s1.takeinput(5);
    s1.sortselection();
}