#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int l;
    cin >> l;
    vector<double> a(l);

    for (size_t it = 0; it < l; ++it) {
        cin >> a[it];
    }

    map<double, double> m;
    for (size_t it = 0; it < l; ++it) {
        if (m.find(a[it]) == m.end()) {
            pair<double, double> foo = make_pair(a[it], 1);
            m.insert(foo);
        }
        else {
            m[a[it]] += 1;
        }
    }

    double sum = 0;
    for (map<double, double>::const_iterator it = m.begin(); it != m.end(); ++it) {
        sum += (*it).second;
    }

    map<double, double> prob;
    for (map<double, double>::const_iterator it = m.begin(); it != m.end(); ++it) {
        pair<double, double> foo = make_pair((*it).first, (*it).second / sum);
        prob.insert(foo);
    }

    // 1. momentum
    double fm = 0;
    for (map<double, double>::const_iterator it = prob.begin(); it != prob.end(); ++it) {
        fm += ((*it).first * (*it).second);
    }

    // 2. momentum
    double sm = 0;
    for (map<double, double>::const_iterator it = prob.begin(); it != prob.end(); ++it) {
        sm += (pow((*it).first, 2) * (*it).second);
    }

    // deviation
    double dev = sqrt(sm - pow(fm, 2));

    cout << fixed << setprecision(1) << dev << endl;

    return 0;
}
