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
    int aLen = sizeof(arr); // array size
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
        p = arr[cur++];
        while(*(p++) != 0){
            cLen++;
        }
        cLen += bLen;// working in len+bLen amount of memory
    }
    if(bLen == 0){
        cLen++;//if bLen is null, need a space for the null pointer;
    }
    
    // try to allocate memory
    char* mem = malloc(cLen*sizeof(char));.
    
    // if you can't, let the user know and exit the program.
    if(mem == 0){
        printf("Out of memory, exiting;");
        exit(1);
    }
    
    // write the entries of the array to the new memory with 'between' between them
    int cur = 0;
    while(cur < aLen){
        p = arr[cur++];
        while(*p != 0){
            *(mem++) = *(p++);
        }
        p = between;
        while(*p != 0){
            *(mem++) = *(p++);
        }
    }
    // now go back and get rid of the last between entry by writing a null after the last arr entry.
    p = p - bLen;
    *p = 0;
    
    return mem;
}

int fLen(char *f){
    char *byteLen = system(join({"for %I in (", f, ") do @echo %~zI"}, ""));
    int fileLen = 0;
    
    // if the query returns "ECHO is on." then the file does not exist so return a helpful message.
    char *echo = "ECHO is on.";
    if(strEqu(byteLen, echo)){
        printHelp(2); // file does not exist
        exit(1);
    }else{
        // otherwise get the length of the file (in bytes);
        char *p = byteLen;
        while(*p != 0){
            fileLen *= 10;
            fileLen += (*(p++) - 48);
        }
    }
    return fileLen;
}

void printHelp(int option){
    switch(option):
        case 0:
            printf("\n\nThis program takes a file and trys to compress it using Huffman encoding on the binary directly, regardless of what file it is.\nUsed from the command line like: TDcompress <options> <filename>\n\n-bpl\t\tbpl stands for bytes per letter, which tells the computer how many bytes to take at a time when trying to count a collection of bytes as a 'letter': default is 1\n-h,-help\tBrings up this screen for additional help.\n-p\t\tProbes the file with various byte lengths to check how good the compression would be at that byte length. For more help run TDcompress -p\n\n");
            break;
        case 1:
            printf("\nWhen trying to use this program with -bpl ensure it has this format:\n\tTDcompress -bpl <int> <filename>\n\n");
            break;
        case 2:
            printf("File does not exist, check that the file is in the same folder as this program.");
            break;
        case 3:
            printf("\nWhen trying to probe this file for the best number of bytes to use, ensure it has this format:\n\tTDcompress -p <filename>\n or, for more granularity use:\n\tTDcompress -p <bytes to jump between checks> <number of checks to run> <filename>\nDefaults to TDcompress 1 3 <filename>\n");
            break;
        case 4:
            
        case 5:
            
        case 6:
            
        else:
            printf("Run with -h or --help for more help.");
}



int main(int argc, char *argv[]){
    // default bytes per letter value is 1 and only will be modified if the user manually changes it
    int bpl = 1;
    char *filename = 0;
    
    // -h, --help are help commands, -bpl means bytes per letter and sets how many bytes equals a letter in the Huffman encoding sense. (default is 1)
    char commands[] = {"-h", "-help", "-bpl", "-p"};
    
    // no arguments means no input file, return a simple statement
    if(argc < 2){
        printf("Run with -h or --help for more help.");
        return 0;
    }
    
    // command modifications
    if(*argv[1] == "-"){
        // if they are querrying for help, output the help screen.
        if(strEqu(argv[1], *commands[0]) || strEqu(argv[1], *commands[1])){
            printHelp(0);
            return 0;
        }
        
        // if they have run the program with -bpl then check that the requirements are fulfilled for -bpl, if not print a helpful message.
        if(strEqu(argv[1], *commands[2])){
            if(argc == 4){
                bpl = int(argv[2]);
                filename = *argv[3];
            }else{
                printHelp(1);
                return 0;
            }
        }
        
        if(strEqu(argv[1], *commands[3])){
            int skip = 1;
            int times = 3;
            if(argc == 3){
                int len = fileLen(argv[2]);
            }else if(argc == 5){
                int len = fileLen(argv[4]);
                skip = int(argv[2]);
                times = int(argv[3]);
            }else{
                printHelp(3);
                return 0;
            }
            if(skip < 0){
                printHelp(3);
                return 0;
            }
            int on = 1;
            for(int i = 0; i++; i<times){
                int data[] = buildArr(on);// call the funtion that takes the bytes and bins them in sets of <argument>
                int d = sizeof(data);
                
                int *p = &data;
                int *end = &data[d-1];
                int max = 0, min = inf, maxCount = 0, minCount = 0;
                float ave, below;
                
                while(p<=end){
                    if(*p > max){
                        max = *p;
                        maxCount = 1;
                    }else if(*p == max){
                        maxCount++;
                    }
                    
                    if(*p < min){
                        min = *p;
                        minCount = 1;
                    }else if(*p == min){
                        minCount++;
                    }
                    ave += *(p++);
                }
                ave = ave/d;
                
                int b = 0;
                
                p = &data;
                while(p<=end){
                    if(*(p++) < ave){
                        b++;
                    }
                }
                below = b/d;
                
                printf("\nUsing %i byte(s), the max number of times a bin was hit is %i, the minimum is %i, the average number of times a bin was hit is %i, %.2f\% of the bins are below the average, %i(%.2f\%) of the bins are at the maximum number of hits, and %i(%.2f\%) of the bins are at the minimum number of hits.\n", on, max, min, ave, below, maxCount, maxCount/d, minCount, minCount/d);
                on = on + skip + 1;
            }
            return 0;
        }
    }else{
        // if they haven't run any special commands then assign the first argument to the filename
        filename = argv[1];
    }
    
    
    
    
    // now run the program with the arguments given.
    // ---------------------------------------------
    
    // check that the file exists by trying to check its length.
    int fileLen = fLen(filename);

    // otherwise the file exists and we can try to compress it.
    int data[] = buildArr(bpl);
    
    metadata(bitlist); // write [int](num of bytes used in encoding) and SHA256(file) to the front of the output file
    
    tree t = buildTree(bitlist, &data); // build the tree to be used for encoding/decoding
    //while file *f < f+fileLen
    //  read through byte by byte, writing the coded 'letters' to the bitlist
    cap(bitlist, last); // cap the encoding with at least a bpl of 1's as all 1's are reserved for marking the end of the encoding by being invalid.
   //printf("%s\n",func(3));
   return 0;
}