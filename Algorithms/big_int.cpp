#include "algos.h"
#include <vector>
#include <string>
#include <iostream>

void big_int::carry() {
    int pos = 0;
    while (pos < vec.size()) {
        if (vec[pos] >= mod) {
            if (pos + 1 >= vec.size())
                vec.push_back(0);
            vec[pos + 1] += vec[pos] / mod;
            vec[pos] %= mod;
        }
        pos++;
    }
}

void big_int::add(int64_t v) {
    vec[0] += v;
    carry();
}

big_int big_int::pow(big_int b, int p) {
    if (p == 1) {
        return b;
    } else if (p == 0) {
        return big_int(1);
    }

    big_int tmp = b;
    tmp *= b;
    if (p % 2 == 0) {
        return pow(tmp, p / 2);
    } else {
        big_int bb = pow(tmp, p / 2);
        bb *= b;
        return bb;
    }
}

big_int::big_int() {
    vec.resize(1);
}

big_int::big_int(int64_t v) {
    vec.resize(1);
    add(v);
}

big_int::big_int(std::string s) {
    int pos = 0;
    int64_t mn = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        while (pos >= vec.size())
            vec.push_back(0);
        vec[pos] += mn * (s[i] - '0');
        mn *= 10;
        if (mn >= mod) {
            mn = 1;
            pos++;
        }
    }
}

big_int& big_int::operator++() {
    add(1);
    return *this;
}

big_int big_int::operator++(int) {
    add(1);
    return *this;
}

big_int& big_int::operator+=(const big_int& b) {
    int s = std::max(vec.size(), b.vec.size());
    while (vec.size() < s)
        vec.push_back(0);
    for (int i = 0; i < s; i++)
        vec[i] += (i < b.vec.size() ? b.vec[i] : 0);
    carry();

    return *this;
}

big_int& big_int::operator*=(const int64_t& b) {
    for (auto& it : vec)
        it *= b;
    carry();

    return *this;
}

big_int& big_int::operator*=(const big_int& b) {
    int aa = vec.size(), bb = b.vec.size();
    int res = std::max(aa, bb) * 2;

    std::vector<int64_t> tmp = vec;
    while (vec.size() < res)
        vec.push_back(0);

    std::fill(vec.begin(), vec.end(), 0);
    for (int i = 0; i < aa; i++) {
        for (int z = 0; z < bb; z++) {
            vec[i + z] += tmp[i] * b.vec[z];
        }
    }
    while (vec.back() == 0)
        vec.pop_back();
    if (vec.empty())
        vec.push_back(0);

    carry();

    return *this;
}

int64_t big_int::operator%(const int64_t& b) {
    int64_t res = 0, mn = 1;
    for (auto it : vec) {
        res += mn * it;
        res %= b;
        mn *= mod;
        mn %= b;
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, const big_int& b) {
    for (int i = b.vec.size() - 1; i >= 0; i--) {
        if (i == b.vec.size() - 1)
            os << b.vec[i];
        else {
            int64_t tmp = b.vec[i];
            if (tmp == 0) tmp = 1;
            while (tmp * 10 < b.mod) {
                os << 0;
                tmp *= 10;
            }
            os << b.vec[i];
        }
    }
    return os;
}

bool operator<(const big_int& l, const big_int& r) {
    return l.cmp(r) < 0;
}

bool operator>(const big_int& l, const big_int& r) {
    return l.cmp(r) > 0;
}

bool operator<=(const big_int& l, const big_int& r) {
    return l.cmp(r) <= 0;
}

bool operator>=(const big_int& l, const big_int& r) {
    return l.cmp(r) >= 0;
}

bool operator==(const big_int& l, const big_int& r) {
    return l.cmp(r) == 0;
}

bool operator!=(const big_int& l, const big_int& r) {
    return l.cmp(r) != 0;
}

int64_t big_int::weak() {
    if (vec.size() > 1)
        return -1;
    return vec[0];
}

void big_int::print_cerr() {
    std::cerr << vec.size() << ": ";
    for (auto it : vec)
        std::cerr << it << " ";
    std::cerr << std::endl;
}

int big_int::cmp(const big_int& b) const {
    if (vec.size() > b.vec.size())
        return 1;
    else if (vec.size() < b.vec.size())
        return -1;
    else {
        for (int i = vec.size() - 1; i >= 0; i--) {
            if (vec[i] < b.vec[i])
                return -1;
            else if (vec[i] > b.vec[i])
                return 1;
        }
        return 0;
    }
}

big_int big_int::pow(int p) {
    return pow(*this, p);
}

#ifdef ALGOS_STANDALONE
int main() {
    int n;
    std::cin >> n;
    big_int b(1);
    for (int i = 2; i <= n; i++)
        b *= i;
    std::cout << b << std::endl;
}
#endif
