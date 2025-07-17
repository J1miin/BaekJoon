#include <bits/stdc++.h>
using namespace std;

int main(){
    int num[9], result[7];
    for (int i=0;i<9;++i){
        cin >> num[i];
    }
    for (int i=0;i<8;++i){
        int total = 0;
        for (int j=i+1;j<9;++j){
            total = 0;

            for (int c=0, d=0;c<9;c++){
                if(c!=i && c!=j){
                    result[d++] = num[c];
                }
            }
            for (int k=0;k<7;++k){
                total+= result[k];
            }
            if (total == 100) break;
        }
        if (total==100) break;
    }
    sort(result, result+7);
    for (auto a: result){
        cout<<a<<'\n';
    }
}

