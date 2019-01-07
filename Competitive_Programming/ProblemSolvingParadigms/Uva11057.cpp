/*
Cautions
1. Binary search mid
  - if mid is implemented through 'mid = (l + r) / 2', then overflow will happen.
2. Binary search index
  - It is confused which index should be changed.
3. Make sure the search space i: [0, N]!
  - At first, I guess the search space i is [0, N/2].........
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int check(int price, int* costs, int l, int r){
    if(l <= r){
        int mid = l + (r - l) / 2;
        if(costs[mid] == price) return mid;
        if(costs[mid] > price) return check(price, costs, l, mid-1);
        return check(price, costs, mid+1, r);
    }

    return -1;
}

int main(){
    int N;
    while(EOF != scanf("%d", &N)){
        int costs[10000];
        int M;
        for(int i=0; i<N; i++)
            scanf("%d", costs+i);
        scanf("%d", &M);

        sort(costs, costs+N);
        int x=0, y=1000001;
        for(int i=0; i<N; i++){
            int ret = check(M-costs[i], costs, 0, N-1);
            if(ret >= 0 & ret != i){
                if(abs(M-costs[i] - costs[i]) < abs(y - x)){
                    x = min(costs[i], M-costs[i]);
                    y = max(costs[i], M-costs[i]);
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", x, y);
    }
}
