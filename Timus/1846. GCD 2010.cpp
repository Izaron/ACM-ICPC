#include <cstdio>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXQ = 1<<17;

int arr[MAXQ*2];

int tmp;
int gcd(int a, int b) {
    while (b!=0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

unordered_multimap<int, int> pos;

void update(int i, int d) {
    arr[i] = d;

    while(i!=0){
        i /= 2;
        arr[i] = gcd(arr[2*i], arr[2*i+1]);
    }
}

int main() {
    int q;
    scanf("%d", &q);

    char c;
    int n;

    int idx=MAXQ;

    while(q--) {
        scanf(" %c %d", &c, &n);

        if(c=='+') {
            pos.insert(pair<int, int>(n, idx));

            update(idx++, n);

        } else {
            unordered_multimap<int, int>::iterator it = pos.find(n);
            int currPos =it->second;

            pos.erase(it);
            update(currPos, 0);
        }


        printf("%d\n", arr[1]?arr[1]:1);
    }

    return 0;
}
