
#include <stdio.h>
int main(void)
{
    char answer[100];
    printf("Qual é seu nome? ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = '\0';
    printf("hello, %s\n", answer);
}