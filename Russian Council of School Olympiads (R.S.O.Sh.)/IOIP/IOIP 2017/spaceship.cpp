#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main() {
    #ifndef HOME
    freopen("spaceship.in", "r", stdin);
    freopen("spaceship.out", "w", stdout);
    #endif

    int n;
    ll sum = 0;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        sum += vec[i];
    }

    int index = 0;
    while (sum - vec[index] != vec[index])
        index++;

    for (int i = 0; i < n; i++) {
        if (i == index)
            continue;
        cout << vec[i] << " ";
    }
    cout << vec[index] << endl;
}
