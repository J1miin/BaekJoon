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
        int gap = min(bottles[fromId[i]],available);
        bottles[fromId[i]]-=gap;
        bottles[toId[i]]+=gap;
        
        // if (available>=bottles[fromId[i]]) {
        //     bottles[toId[i]]+= bottles[fromId[i]];
        //     bottles[fromId[i]]=0;
        // }else{
        //     bottles[toId[i]]=capacities[toId[i]];
        //     bottles[fromId[i]] = bottles[fromId[i]]-available;
        // }
        
    }

}
int main(){
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