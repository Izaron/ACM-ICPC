#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
using namespace std;

map<int, bool>  exist;
map<int, bool>  odd;
map<int, int>  previous;

bool add(int a, int b,  bool c){//b>=a;
    if (!exist[b]){
        exist[b] = true;
        odd[b] = c;
        previous[b] = a;
        return true;
    };
    int  i = previous[b];
    if(i==a) return (odd[b]==c);
    if(i<a) return add(i,a-1, (c!=odd[b]));
    return add(a,i-1, (c!=odd[b]));
};

int main(int argc, char * argv[]) {
    while (1) {
        exist.clear();
        odd.clear();
        previous.clear();
        int numbers = 0;
        cin >> numbers;
        if (numbers==-1) break;
        int questions = 0;
        cin >> questions;
        bool flag = false;
        int kek = 0;
        for (int i = 0; i<questions; i++) {
            int a = 0;
            cin >> a;
            int b = 0;
            cin >> b;
            string tmp;
            cin >> tmp;
            bool parity = true;
            if (tmp=="even") {
                parity = false;
            }
            if ((add(a,b,parity)==false)&&(flag==false)) {
                kek = i;
                flag=true;
            }
        }
        if (flag==false) {
            cout << questions << endl;
        } else {
            cout << kek << endl;
        }
    }
    return 0;
}