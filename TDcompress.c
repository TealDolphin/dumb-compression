#include <stdio.h>
#include <stdlib.h>

// single line comment
/*
  multi line comment
*/

// checks if two character pointer locations up to the null (strings) are equal, does not care about safety so it just goes as quick as possible.
bool strEqu(char *one, char *two){
    // while they're both not null pointers
    while(*one != 0 && *two != 0){
        // if they aren't equal, return false for speed
        if(*(one++) != *(two++)){
            return false;
        }
    }
    // if one or the other is null, check that they both are.
    if(*one == *two){
        return true; // if they are then the strings are equal
    }
    return false;// otherwise they aren't.
}

// join all members of a char array together with a set of characters between each entry
char* join(char *arr[], char *between){
    int aLen = sizeOf(arr); // array size
    int bLen = 0; // number of characters to put between each arr entry
    int cLen = 0; // number of characters in whole entry (used to allocate memory)
    
    // count how many characters the between set is
    char *p = between;
    while(*(p++) != 0){
        bLen++;
    }
    
    // go through each entry in the array and count up how many characters are going to be in the final array.
    int cur = 0;
    while(cur < aLen){
        p = arr[cur];
        
    }
}

int main(int argc, char *argv[]){
    // default bits per letter value is 8 and only will be modified if the user manually changes it
    int bpl = 8;
    char *filename = 0;
    
    // -h, --help are help commands, -bpl means bits per letter and sets how many bits equals a letter in the Huffman encoding sense. (default is 8)
    char commands[] = {"-h", "--help", "-bpl"};
    
    // no arguments means no input file, return a simple statement
    if(argc < 2){
        printf("Run with -h or --help for more help.");
        return 0;
    }
    
    // if they are querrying for help, output the help screen.
    if(strEqu(argv[1], *commands[0]) || strEqu(argv[1], *commands[0])){
        printHelp();
        return 0;
    }
    
    // if they have run the program with -bpl then check that the requirements are fulfilled for -bpl, if not print a helpful message.
    
    
    
    // if they haven't run any special commands then assign the first argument to the filename to try to run the program
    
    
    
    // now run the program with the arguments given.
    // ---------------------------------------------
    
    // check that the file exists by troying to check its length.
    int byteLen = system(join({"for %I in (", filename, ") do @echo %~zI"}, ""));
    
    // if the query returns "ECHO is on." then the file does not exist so return a helpful message.

    // otherwise the file exists and we can try to compress it.
    
   //printf("%s\n",func(3));
   return 0;
}