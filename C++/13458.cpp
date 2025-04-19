#include <iostream>
#include <vector>
using namespace std;

int main() {
    int iN, iLeader, iMember;
    int iTemp;
    long long iRes = 0;
    vector <int> vCustomer;
    
    cin >> iN;
    for (int i=0;i<iN;++i){
        cin>>iTemp;
        vCustomer.push_back(iTemp);
    }
    cin>>iLeader>>iMember;
    
    for (auto a : vCustomer){
        if (a <= iLeader){
            //리더 한 명이면 충분 
            iRes++;
        }else {
            a-=iLeader;
            iRes++;
            if (a%iMember==0){
                iRes=iRes+(a/iMember);
            }else{
                iRes=iRes+(a/iMember)+1;
            }
        }
    }

    cout << iRes;
    return 0;
}