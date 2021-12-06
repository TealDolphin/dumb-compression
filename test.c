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
   printf("%s\n",func(3));
   return 0;
}