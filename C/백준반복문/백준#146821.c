#include <stdio.h>
int main () {
    int Ihour, Imin, IcookingTime;
    int IminR;
    scanf("%d %d",&Ihour,&Imin);
    scanf("%d",&IcookingTime);

    Imin=Imin + IcookingTime;
    IminR = Imin/60;
    if (IminR!=0){
        Ihour =Ihour + IminR ;
        Imin=Imin-60*IminR;
        if (Ihour >=24){
            Ihour = Ihour-24;
        }
        printf("%d %d \n", Ihour, Imin);
    }else { 
        if (Ihour >=24){
            Ihour = Ihour-24*IminR;
        }
        printf("%d %d \n", Ihour, Imin);
    }

    return 0;
}