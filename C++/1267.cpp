#include <bits/stdc++.h>
using namespace std;
int record[10000], iN;

int M(){
    int iRes = 0;
    for (int i=0;i<iN;++i){
        int iMok = record[i]/120;
        int iMod = (record[i]-120*iMok)/60+1;
        iRes += iMok*30 + iMod*15;
    }
    return iRes;
}

int Y(){
    int iRes = 0;
    for (int i=0;i<iN;++i){
        int iMok = record[i]/60;
        int iMod = (record[i]-60*iMok)/30+1;
        iRes += iMok*20 + iMod*10;
    }
    return iRes;
}
int main(){
    cin>>iN;
    for (int i=0;i<iN;++i){
        cin >> record[i];
    }
    int yRes = Y();
    int mRes = M();

    if (yRes < mRes){
        cout<<"Y "<<yRes;
    }else if (yRes>mRes){
        cout<<"M "<<mRes;
    }else {
        cout <<"Y M "<<yRes;
    }
}

/*이렇게 복잡하게 할 필요 없었네.......
문제를 잘못 이해해서 꼬아 풀었따... */