#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

const int MAX_CITY = 100;
const int MAX_TIME = 1000000000;

int** adj;

int find_shortest_path(int* candidate, int size) {
    int min_dist = INT_MAX;
    int min_row = 0, min_col = 0;

    for(int row=0; row<size; ++row) {
        for(int col=0; col<size; ++col) {
            int dist = *(candidate + row*size + col);
            if(dist != -1) {
                if(min_dist > dist) {
                    min_dist = dist;
                    min_row = row;
                    min_col = col;
                }
            }
        }
    }
    *(candidate + min_row * size + min_col) = -1;
    return min_row;
}

int solution(int start, int number_of_city) {
    int ret = 0;
    int distance[number_of_city];
    bool visit[number_of_city];
    int candidate[number_of_city][number_of_city];
    int num_candidate = 0;
    start--;

    for(int i=0; i<number_of_city; ++i) {
        visit[i] = false;
        distance[i] = INT_MAX;
    }

    for(int row=0; row<number_of_city; ++row) {
        for(int col=0; col<number_of_city; ++col) {
            candidate[row][col] = -1;
        }
    }

    distance[start] = 0; 
    candidate[start][start] = 0;
    num_candidate++;

    while(num_candidate != 0) {
        int start = find_shortest_path((int*)candidate, number_of_city);
        num_candidate--;

        if(visit[start]) continue;
        visit[start] = true;

        for(int next=0; next<number_of_city; ++next) {
            if(adj[start][next] != 'x' && adj[start][next] != 0) {
                int new_dist = distance[start] + adj[start][next];
                if(new_dist < distance[next]) {
                    distance[next] = new_dist;
                }
                candidate[next][start] = adj[start][next];
                num_candidate++;
            }
        }
    }

    for(int i=1; i<number_of_city; ++i) {
        if(ret < distance[i]) {
            ret = distance[i];
        }
    }

    return ret;
}

int main() {
    int number_of_city;
    scanf("%d", &number_of_city);

    assert(number_of_city <= MAX_CITY);

    adj = malloc(sizeof(int*) * number_of_city); 
    for(int i=0; i<number_of_city; ++i) {
        adj[i] = malloc(sizeof(int) * number_of_city);
    }

    for(int i=0; i<number_of_city; ++i) {
        int in_size = 11 * number_of_city;
        char in_str[in_size];
        fgets(in_str, in_size, stdin);

        char** splits = NULL;
        char* token = strtok(in_str, " ");
        int c_idx = 0;

        while(token != NULL) {
            int value = 0;
            if(*token == 'x') {
                value = 'x';
            } else {
                value = strtol(token, NULL, 10);
            }
            adj[i][c_idx] = value;
            adj[c_idx++][i] = value;
            token = strtok(NULL, " ");
        }
    }

    int ans = solution(1, number_of_city);
    printf("%d\n", ans);

    return 0;
}
