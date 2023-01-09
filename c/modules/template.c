#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while(true) {
        char* cursor = data + data_length;
        char* line = fgets(data, alloc_length - data_length, stdin);

        if(line == NULL) break;

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

char** split_string(char* str, int* length) {
    char** splits = NULL;
    char delimiters[4]="[], ";
    char* token = strtok(str, delimiters);

    int spaces = 0;

    while(token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        splits[spaces - 1] = token;

        token = strtok(NULL, delimiters);
    }

    *length=spaces;

    return splits;
}

int solution(int a[], size_t a_len, int b[], size_t b_len) {
    int ans=0;

    for(int i=0; i<a_len; ++i) {
        ans += a[i] * b[i];
    }

    return ans;
}

int main() {
    char* a_str=readline();
    char* b_str=readline();

    int a_len, b_len;
    char** a_values=split_string(a_str, &a_len);
    char** b_values=split_string(b_str, &b_len);

    int* a = malloc(sizeof(int) * a_len);
    int* b = malloc(sizeof(int) * b_len);

    for(int i=0; i<a_len; ++i) {
        a[i] = atoi(a_values[i]);
        b[i] = atoi(b_values[i]);
    }

    int ans = solution(a, a_len, b, b_len);
    printf("%d\n", ans);
    return 0;
}
