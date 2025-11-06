#include <stdio.h>
 
int main() {
    int quantidadeN;
    scanf("%d",&quantidadeN);
    for(int i=0; i<quantidadeN;i++){
        int n;
        scanf("%d",&n);
        int divisores = 0;
        for(int j=1;j<=n;j++){
            if(n%j==0){
                divisores+=1;
            }
        }
        if(divisores == 2){
            printf("%d eh primo\n",n);
        }else{
            printf("%d nao eh primo\n",n);
            
        }
    }
    return 0;
}