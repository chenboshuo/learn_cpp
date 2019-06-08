#include <limits.h>
#include <iostream>

using namespace std;

int max(int x, int len) {
  int _ = INT_MIN;

  for (int i = 0; i < len; i++) {
    std::cin >> x;

    _ = _ > x ? _ : x;
  }

  return _;
}

float max(float x, int len) {
  float _ = LONG_MIN;

  for (int i = 0; i < len; i++) {
    std::cin >> x;

    _ = _ > x ? _ : x;
  }

  return _;
}

long long max(long long x, int len) {
  long long _ = LONG_MIN;

  for (int i = 0; i < len; i++) {
    std::cin >> x;

    _ = _ > x ? _ : x;
  }

  return _;
}

int main(int argc, char const *argv[]) {
  int a;

  float b;

  long long c;

  std::cout << max(a, 5) << '\n';

  std::cout << max(b, 5) << '\n';

  std::cout << max(c, 5) << '\n';

  return 0;
}
