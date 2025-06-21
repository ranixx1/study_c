#include <cs50.h>
#include <stdio.h>

int maior_de4( int a, int b, int c, int d);

int main(void)
{
    int a = get_int("Digite um número\n");
    int b = get_int("Digite um número\n");
    int c = get_int("Digite um número\n");
    int d = get_int("Digite um número\n");
    printf("O maior dos 4 números é:%i\n", maior_de4(a,b,c,d));
}

int maior_de4(int a, int b, int c, int d)
{
    if(a>b && a>c && a>d){
        return a;
    } else if(b>a && b>c && b>d){
        return b;
    } else if(c>a && c>b && c>d){
        return c;
    } else if(d>a && d>b && d>c){
        return d;
    }
}
