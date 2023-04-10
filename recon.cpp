#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <queue>

#define eps 1e-4

using namespace std;
vector<int> dist;
vector<int> vel;
int min_val = -2147483647;
int max_val = 2147483647;


double f(double x){
    double minx = max_val;
    double maxx = min_val;
    for(int i = 0; i < dist.size(); i ++){
        double d = (double)dist[i] + x*(double)vel[i];
        minx = min(d, minx);
        maxx = max(d, maxx);
    }
    return maxx - minx;
}

int main(){
    int N;
    cin >>N;
    int idx = 0;
    while(N--){
        int d, v;
        cin >> d >> v;
        dist.push_back(d);
        vel.push_back(v);
        idx ++;
    }
    double l = 0, r = 100000;
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);
        if (f1 < f2) {
            r = m2;
        }
        else {
            l = m1;
        }
    }
    cout << f(l) << endl;
}