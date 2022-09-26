// @author Patryk Jansuzewki Januszewskijanuszek

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    if(argc <= 1 || argc > 2){
        printf("Program requires only one argument!\n");
        return 1;
    }
    printf("User input -> %s\n", *(argv + 1));
    int inputNumberInt = atoll(*(argv + 1));
    unsigned int buffer = 1;
    unsigned int iterator = 0;
    char* output = malloc(sizeof(char));
    while(inputNumberInt/buffer > 0){
        realloc(output, sizeof(char) * (iterator + 1));
        if(inputNumberInt & 0x01 * buffer)  *(output + iterator) = '1';
        else                                *(output + iterator) = '0';
        iterator++;
        buffer *= 2;
    }
    realloc(output, sizeof(char) * iterator + 1);
    *(output + iterator) = '\0';
    printf("Output is -> %s", strrev(output));
    free(output);
    return 0;
}