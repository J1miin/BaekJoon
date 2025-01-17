#include <iostream>
#include <vector>
using namespace std;

void backTracking(vector <int> & vAns, vector<bool> & vTrackingUsed,int iM, int iN){
    if (vAns.size()==iM){
        for (int i=0;i<iM;++i){
            cout<<vAns[i]<<" ";
        }
        cout<<'\n'; //와우.. 이거 endl으로 해서 시간 초과가 나는구나... 
        return;
    }
    for (int i=0;i<iN;++i){
        cout<<"for문에서 i:"<<i<<endl;
        if(vTrackingUsed[i]==true){ continue; }
        vAns.push_back(i+1);
        vTrackingUsed[i]=true;
        backTracking(vAns,vTrackingUsed,iM, iN);

        vAns.pop_back();
        vTrackingUsed[i]=false;
    }

}

int main(){
    int iN , iM;
    cin >> iN >> iM;
    vector<int> vAns ;
    vector<bool> vTrackingUsed(iN,false);
    backTracking(vAns,vTrackingUsed,iM,iN);
    return 0;
}