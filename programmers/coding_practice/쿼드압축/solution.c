#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* readline() {
    size_t alloc_length = 2;
    size_t data_length = 0; 
    char* data = malloc(sizeof(char) * alloc_length);

    while(true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if(line == NULL) {
            break;
        }

        data_length += strlen(cursor);
        
        if(data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;
        data = realloc(data, alloc_length);
    }
        
    if(data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    return data;
}

char** split_string(char* str, char* delimiters) {
    char** splits;

    return splits;
}

int* solution(int** arr, size_t arr_rows, size_t arr_cols) {
    int* ans;

    return ans;
}

int main() {
    char* str = readline();
    printf("%s\n", str);

    char** tokens = split_string(str, "[], ");

    return 0;
}
