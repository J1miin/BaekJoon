#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int iN, iL;
    cin >> iN >> iL;
    deque<int> d ;
    for (int i=0;i<iN;++i){
        int tmp;
        cin>>tmp;
        d.push_back(tmp);
    }
    for (int i=1;i<=iN;++i){
        int iS, iE;
        iS = i-iL+1;
        iE = i;
        if (iS <= 0){iS=0;}else {iS-=1, iE-=1;}
        int iAns = 0;
        //cout << endl<< iS << " " << iE<<endl;
        cout << *min_element(d.begin()+iS,d.begin()+iE+1) <<" ";
    }
}
/*
1 5 2 3 6 2 3 7 3 5 2 6
i=1) D1 = A(1-3+1)~A(1) = A(-1)~A(1) 
i=2) D2 = A(2-3+1)~A(2) = A(0)~A(2)
i=3) D1 = A(3-3+1)~A(3) = A(1)~A(3)
*/