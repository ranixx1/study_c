#include <stdio.h>
 
int main() {
    int n;
    scanf("%d",&n);
    int limite = n+6;
    for(int i= n;i <=limite;i++){
        if(i%2!=0){
            printf("%d\n",i);
        }
    }
 
    return 0;
}