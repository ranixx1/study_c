#include <stdio.h>
#include <stdlib.h>

void display(int var, int *ptr);
void update(int *p);

int main(){
    int var = 15;
    int *ptr;

    ptr = &var;

    display(var,ptr);
    
    update(&var);

    display(var,ptr);


    return 0;
}

void display(int var, int *ptr){

    printf("\n\n");
    printf("Conteudo de var = %d\n",var);
    printf("endereço de var = %p\n", &var);
    printf("Conteudo apontado por ptr = %d\n", *ptr);
    printf("endereço apontado por ptr = %p\n", ptr);
    printf("endereço do ptr = %p\n", &ptr);
}

void update(int *p){
    *p = *p+1;
}

// *ptr = o apontado por, conteúdo do endereço da variavel que ptr aponta
// ptr = o endereço da variavel
// &ptr = endereço do ponteiro