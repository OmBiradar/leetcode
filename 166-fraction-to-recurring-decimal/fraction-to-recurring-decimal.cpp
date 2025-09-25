#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string fractionToDecimal(int N, int D) {
    // decimal part
    long long numerator = N, denominator = D;
    if (numerator == 0) return "0";
    string ans;
    if ((numerator < 0) ^ (denominator < 0)) {
      ans += '-';
    }
    numerator = abs(numerator), denominator = abs(denominator);
    if (numerator >= denominator) { 
      ans += to_string(numerator / denominator);
    } else {
      ans += "0";
    }
    numerator = numerator % denominator;
    if (numerator == 0) {
      return ans;
    } else
      ans += '.';
    map<pair<int, int>, int> vis;
    bool recuring = false;
    string fraction;
    while (numerator) {
      int gcd = __gcd(numerator, denominator);
      numerator /= gcd, denominator /= gcd;
      if (vis[{numerator, denominator}]) {
        fraction.insert(vis[{numerator, denominator}], "(");
        fraction += ')';
        recuring = true;
        break;
      } else
        vis[{numerator, denominator}] = fraction.size();
      numerator *= 10;
      while (numerator < denominator)
        numerator *= 10, fraction += '0';
      char digit = (char)(numerator / denominator + '0');
      fraction += digit;
      numerator = numerator % denominator;
    }
    ans += fraction;
    return ans;
  }
};
