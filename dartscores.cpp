#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <queue>

using namespace std;


vector<int> v;
int target;
vector<int> nums;
unordered_map<int, string> mapping;

int rec(int idx, int num, int sum){
    if(num == 3 || sum >= target || idx == v.size()){
        if(sum == target){
            for(auto x: nums){
                cout <<  mapping[x] << endl;
            }
            exit(0);
        } else {
            return 0;
        }
    }
    nums.push_back(v[idx]);
    rec(idx + 1, num + 1, sum + v[idx]);
    nums.pop_back();
    rec(idx + 1, num, sum );
    return 1;
}

int main() {
    for(int i = 1; i <= 20; i++){
        for(int j =0; j < 3; j++){
            v.push_back(i);
            v.push_back(2*i);
            v.push_back(3*i);
        }
        mapping[i] = "single " + to_string(i);
        mapping[2*i] = "double " + to_string(i);
        mapping[3*i] = "triple " + to_string(i);
    }
    cin >> target;
    rec(0, 0, 0);
    cout << "impossible" << endl;
}