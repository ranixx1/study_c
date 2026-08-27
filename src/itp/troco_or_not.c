#include <stdio.h>

int main(){
    int combo, money;

    scanf("%d %d", &combo, &money);

    switch (combo)
    {
    case 1:
        if(money == 12){
            printf("Deu certim!");
        } else if( money < 12){
            printf("Saldo insuficiente! Falta %d reais\n", 12-money);
        } else{
            printf("Troco = %d reais\n", money-12);
        }
        break;
    case 2:
        if(money == 23){
            printf("Deu certim!");
        } else if( money < 23){
            printf("Saldo insuficiente! Falta %d reais\n", 23-money);
        } else{
            printf("Troco = %d reais\n", money-23);
        }
        break;
    case 3:
        if(money == 31){
            printf("Deu certim!");
        } else if( money < 31){
            printf("Saldo insuficiente! Falta %d reais\n", 31-money);
        } else{
            printf("Troco = %d reais\n", money-31);
        }
        break;  
    case 4:
        if(money == 28){
            printf("Deu certim!");
        } else if( money < 28){
            printf("Saldo insuficiente! Falta %d reais\n", 28-money);
        } else{
            printf("Troco = %d reais\n", money-28);
        }
        break;
    case 5:
        if(money == 15){
            printf("Deu certim!");
        } else if( money < 15){
            printf("Saldo insuficiente! Falta %d reais\n", 15-money);
        } else{
            printf("Troco = %d reais\n", money-15);
        }
        break;
    default:
        break;
    }
}