#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> capacities;
vector<int> bottles;
vector<int> fromId;
vector<int> toId;

void isAvailiable(){
    int available = 0;
    for(int i=0;i<fromId.size();++i){
        available = capacities[toId[i]] - bottles[toId[i]];    
        //cout<<"i "<<i <<": availalbe "<<available<<endl;
        if (available>=bottles[fromId[i]]) {
            bottles[toId[i]]+= bottles[fromId[i]];
            bottles[fromId[i]]=0;
            //cout<<"if "<<i <<": bottles[fromId[i]] "<<bottles[fromId[i]]<<endl;
        }else{
            bottles[toId[i]]=capacities[toId[i]];
            bottles[fromId[i]] = bottles[fromId[i]]-available;
            //cout<<"else "<<i <<": bottles[fromId[i]] "<<bottles[fromId[i]]<<endl;
        }

        // for(auto a:bottles){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
    }

}
int main(){
    // capacities = {14,35,86,58,25,62};
    // bottles = {6,34,27,38,9,60};
    // fromId={1,2,4,5,3,3,1,0};
    // toId={0,1,2,4,2,5,3,1};

    capacities = {700000,800000,900000,1000000};
    bottles = {478478, 478478, 478478, 478478};
    fromId={2,3,2,0,1};
    toId={0,1,1,3,2};

    for(auto a:bottles){
        cout<<a<<" ";
    }
    cout<<endl;
    isAvailiable();
    for(auto a:bottles){
        cout<<a<<" ";
    }
}