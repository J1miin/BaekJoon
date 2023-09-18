#include <stdio.h>
long long int find_gcd(long long int iFirst,long long int iSecond);

int main(){
    int inputNum; //입력받을 개수
    long long int iFirst, iSecond, iRemain;
    long long int lcm, lcd ;

    scanf("%lld %lld", &iFirst,&iSecond);
    lcd = find_gcd(iFirst,iSecond);
    lcm = iFirst * iSecond / lcd;    
    printf("%lld \n",lcm);   

    return 0;
}

long long int find_gcd(long long int iFirst, long long int iSecond){
    long long int lcd, iRemain;
    if (iSecond>iFirst){
        while(1){
            iRemain=iSecond%iFirst;
            iSecond=iFirst;
            iFirst=iRemain;
            if (iFirst==0){
                lcd=iSecond;
                break;
            }
        } 
    }else {
        while(1){
            iRemain=iFirst%iSecond;
            iFirst=iSecond;
            iSecond=iRemain;
            if (iSecond==0){
                lcd=iFirst;
                break;
            }
        } 
    }
    return  lcd;
}