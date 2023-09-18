#include <stdio.h>
int find_gcd(int iFirst, int iSecond);

int main(){
    int inputNum; //입력받을 개수
    int iFirst, iSecond, iRemain;
    int lcm, lcd ;

    scanf("%d",&inputNum);

    for (int i=0;i<inputNum;++i){
        scanf("%d %d", &iFirst,&iSecond);
        lcd = find_gcd(iFirst,iSecond);
        lcm = iFirst * iSecond / lcd;    
        printf("%d \n",lcm);   
    }

    return 0;
}

int find_gcd(int iFirst, int iSecond){
    int lcd, iRemain;
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