#include <stdio.h>

double media_10n(int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9,int n10){
    double media = (n1+n2+n3+n4+n5+n6+n7+n8+n9+n10) / 10.0;
    return media;
}

int main(void){
    printf("%.1f\n", media_10n(54,45,67,57,88,87,76,46,89,95));
}