// The solution of the problem was written by Izaron
// Date: 23:39:37   12 May 2016
// Execution time: 0.078

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <stdio.h>

const int N = 120000;
const int SIZE = 10;
int kucha[N];
int heapColor[N / SIZE + 2];
int heapCnt[N / SIZE + 2];
int pointer = 0;

struct cooler {
    int maxNum = -1;
    int color = -1;
    int currHeap = -1;

    void reallocate() {
        if (currHeap == -1) {
            currHeap = pointer;
            maxNum = currHeap;
            heapColor[currHeap] = color;
            pointer++;
        } else if (heapCnt[currHeap] >= 9) {
            if (currHeap < maxNum) {
                currHeap++;
                while (heapColor[currHeap] != color)
                    currHeap++;
            } else {
                currHeap = pointer;
                maxNum = currHeap;
                heapColor[currHeap] = color;
                pointer++;
            }
        }
    }

    int getPointer() {
        return SIZE * currHeap + heapCnt[currHeap];
    }

    void push(int b) {
        reallocate();
        heapCnt[currHeap]++;
        kucha[getPointer()] = b;
    }

    int pop() {
        int ans = kucha[getPointer()];
        heapCnt[currHeap]--;
        if (heapCnt[currHeap] < 0) {
            currHeap--;
            while (heapColor[currHeap] != color) {
                currHeap--;
                if (currHeap < 0)
                    break;
            }
        }
        return ans;
    }
};

cooler cool[1001];

int n, a, b, p;
char ch[12];

int main() {
    for (int i = 0; i < N / SIZE + 2; i++) {
        heapCnt[i] = -1;
    }

    for (int i = 0; i < 1001; i++) {
        cool[i].color = i;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &ch);
        p = 0;
        a = 0;
        b = 0;

        if (ch[1] == 'U') {
            scanf("%s", &ch);
            while (ch[p] >= '0' && ch[p] <= '9') {
                a *= 10;
                a += ch[p] - '0';
                p++;
            }

            p = 0;
            scanf("%s", &ch);
            while (ch[p] >= '0' && ch[p] <= '9') {
                b *= 10;
                b += ch[p] - '0';
                p++;
            }

            a--;

            cool[a].push(b);
        } else {
            scanf("%s", &ch);
            while (ch[p] >= '0' && ch[p] <= '9') {
                a *= 10;
                a += ch[p] - '0';
                p++;
            }

            a--;

            printf("%d\n", cool[a].pop());
        }
    }
}