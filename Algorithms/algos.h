#ifndef __ALGOS_H_
#define __ALGOS_H_

/*
 * Algorithms header
 * */

// Common includes
#include <cstdint>
#include <string>
#include <vector>

// BigInteger
class big_int {
  private:
    const int64_t mod = 1e7;
    std::vector<int64_t> vec;

    void carry();
    void add(int64_t v);
    big_int pow(big_int b, int p);
  public:
    big_int();
    big_int(int64_t v);
    big_int(std::string s);

    big_int& operator++();
    big_int operator++(int);
    big_int& operator+=(const big_int& b);
    big_int& operator*=(const int64_t& b);
    big_int& operator*=(const big_int& b);
    int64_t operator%(const int64_t& b);
    friend std::ostream& operator<<(std::ostream& os, const big_int& b);

    friend bool operator<(const big_int& l, const big_int& r);
    friend bool operator>(const big_int& l, const big_int& r);
    friend bool operator<=(const big_int& l, const big_int& r);
    friend bool operator>=(const big_int& l, const big_int& r);

    friend bool operator==(const big_int& l, const big_int& r);
    friend bool operator!=(const big_int& l, const big_int& r);

    int64_t weak(); // is smaller than MOD
    void print_cerr();
    int cmp(const big_int& b) const;    // compare -1, 0, 1
    big_int pow(int p);     // returns (*this)^p
};

#endif
