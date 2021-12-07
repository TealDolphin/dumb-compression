#include <stdio.h>
#include <stdlib.h>

// single line comment
/*
  multi line comment
*/
char * func(int var){
    const char * str = "Hello World!";
    return str;
}

int main(int argc, char *argv[]){
    printf("%f\n",743.2315135464544);
    printf("%2f\n",743.2315135464544);
    printf("%.2f\n",743.2315135464544);
    return 0;
}