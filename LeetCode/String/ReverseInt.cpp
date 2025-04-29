#include <iostream>
#include <vector>
#include <queue>
#include<cstdlib> 
using namespace std;
int main(){
    int x = -123;
    
    cout<<endl<<endl;
    int ans = 0;
    queue<int> q;
    bool bFlag = false;
    while(true){
        if (x<10 && x>=0){
            q.push(x);
            break;
        }
        if (x<0){
            x=abs(x);
            bFlag=true;
        }
        q.push(x%10);
        cout<<x%10<<endl;
        x/=10;
        cout<<"x/=10 한 후 x ="<<x<<endl;
    }
    
    if (q.size()>=10) return 0;
    cout<<q.size()<<endl;
    int iSize = q.size()-1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for (int i=iSize;i>0;--i){
            tmp *=10;
        }
        iSize --;
        ans += tmp;
    }
    
    cout<<ans<<endl;
}