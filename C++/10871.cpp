#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int iN, iX, iTmp;
    cin>>iN>>iX;
    for (int i=0;i<iN;++i){
        cin>>iTmp;
        if (iTmp < iX){
            cout<<iTmp<<" ";
        }
    }
}