#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include <numeric>


using namespace std;


int main() {
    float R, n;
    cin >> R >> n;
    vector<float> numCuts(n,0);
    vector<float> weights;
    for(float i = 0; i < n; i++){
        float tmp;
        cin >> tmp;
        weights.push_back(tmp);
    }

    while(true){
        float max_val = 0;
        int max_idx = 0;
        float min_val = 1e6;
        for(int i = 0; i < n; i ++){
            if(weights[i]/(numCuts[i]+1) > max_val){
                max_val = weights[i]/(numCuts[i]+1);
                max_idx = i;
            }
            if(weights[i]/(numCuts[i]+1) < min_val){
                min_val = weights[i]/(numCuts[i]+1);
            }
        }
        if(min_val/max_val > R){
            cout << accumulate(numCuts.begin(), numCuts.end(), 0) << endl;
            break;
        }
        numCuts[max_idx]++;
    }



    return 0;
}
