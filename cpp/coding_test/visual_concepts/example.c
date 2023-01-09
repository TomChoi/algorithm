#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int solution(int n, int** edges) {
    int ans=0;
    int*** adj;
    int* dist;
    int* queue;
    int q_idx=0;

    visit=malloc(sizeof(bool)*n);
    dist=malloc(sizeof(int)*n);
    queue=malloc(sizeof(int)*n*n);

    for(int i=0; i<n; ++i) {
        visit[i]=false;
    }

    for(int i=0; i<n; ++i) {
        dist[i]=INT_MAX;
    }

    for(int i=0; i<n*n; ++i) {
        queue[i]=0;
    }

    dist[0]=0;
    visit[0]=true;

    int c=0;
    while(c != -1) {
        int count=0;
        if(visit[r]) continue;
        visit[r]=true;
        for(int r=0; r<n; ++r) {
            if(edges[r][c] != 0) {
                
            }
        }
        for(

    }

    
    return ans;
}

int main() {
    int q_size=15;
    char q_str[q_size];
    fgets(q_str, q_size, stdin);
    int q=strtol(q_str, NULL, 10);

    int edges[q][q];
    for(int r=0; r<q; ++r) {
        for(int c=0; c<q; ++c) {
            edges[r][c]=0;
        }
    }

    for(int q_itr=1; q_itr<q; ++q_itr) {
        int n_size=15*q_itr;
        char n_str[n_size];
        fgets(n_str, n_size, stdin);

        char** splits=NULL;
        char* token=strtok(n_str, " ");
        int c_idx=0;
        while(token != NULL) {
            int value=0;
            if(*token == 'x') {
                value='x';
            } else {
                value=strtol(token, NULL, 10);
            }
            edges[q_itr][c_idx++]=value;
            token=strtok(NULL, " ");
        }
    }

    int ans=solution(q, (int**)edges);
    printf("%d\n",ans);

    return 0;
}
