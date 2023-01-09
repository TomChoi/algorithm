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

char** split_string(char* str) {
    char** splits = NULL;
    char delimiters[] = {" "};
    char* token = strtok(str, delimiters);

    size_t spaces = 0;

    while(token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        splits[spaces - 1] = token;
        token = strtok(NULL, delimiters);
    }

    return splits;
}

int solution(int n) {
    int ans=0;

    for(int i=1; i<=n; ++i) {
        if(n%i == 0) 
            ans += i;
    }

    return ans;
}

int main() {
    char** n_str = split_string(readline());
    int n = atoi(n_str[0]);

    int ans = solution(n);
    printf("%d\n", ans);
    
    return 0;
}
