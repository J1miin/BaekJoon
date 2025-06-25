//백준 1253번 
#include <iostream>
#include <vector>

using namespace std;
int main(){
    int iN,tmp,iRes=0,i,j;
    cin>>iN;
    vector <int> iV;
    for (int i=0;i<iN;++i){
      cin >> tmp;
        iV.push_back(tmp);
    }
    //정렬
    sort(iV.begin(),iV.end());

    for (int k=0;k<iN;++k){
        i =0;
        j=iN-1;
        while (i<j){
            if (iV[i]+iV[j]==iV[k]){
                if(i==k) i++;
                else if (j==k) j--;
                else {
                    iRes++;
                    break;
                }
            } 
            else if (iV[i]+iV[j] > iV[k]) {j--; continue;}
            else {i++; continue;}
        }
    }
    cout<<iRes;  
}