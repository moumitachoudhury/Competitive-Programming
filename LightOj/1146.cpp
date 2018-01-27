#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9

int ternary_serach(double l, double r)
{
    //double l = ..., r = ..., EPS = ...;
    while (r - l > EPS) {
    double m1 = l + (r - l) / 3,
      m2 = r - (r - l) / 3;
    if (f (m1) < f (m2))
      l = m1;
    else
      r = m2;
}
}
