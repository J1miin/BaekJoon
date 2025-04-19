#include <iostream>
#include <string>
using namespace std;

int main(){
    int k=45;
    string s = "DNFjxo?b5h*5<LWbgs6?V5{3M].1hG)pv1VWq4(!][DZ3G)riSJ.CmUj9]7Gzl?VyeJ2dIPEW4GYW*scT8(vhu9wCr]q!7eyaoy."; 
    string sAns="";
    
    for (int i=0;i<s.size();++i){
        int asciiNum = s[i]+k;
        if((s[i]>=65 && s[i]<=90)){
            if (asciiNum >90){
                while(asciiNum>90){
                    asciiNum= asciiNum-26;
                }
            }
        }else if ((s[i]>=97 && s[i]<=122)){
            if (asciiNum>122){
                while(asciiNum>122){
                    asciiNum= asciiNum-26;
                }
            }
        }else{
            asciiNum=s[i];
        }
        sAns+=asciiNum;
    }
    cout<<sAns<<endl;
    return 0;
}
