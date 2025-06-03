#include <stdio.h>
#include <cs50.h>

int soma(int a,int b);

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    printf("%i\n",soma(x,y));

}

int soma(int a, int b)
{
    return a+b;
}
    