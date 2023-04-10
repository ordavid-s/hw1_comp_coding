#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include <numeric>


using namespace std;


int main() {
    int K;
    cin >> K;
    for(int l = 0; l < K; l++){
        if(l){
            cout << endl;
        }
        vector<int> A;
        vector<int> U;
        int i = 0;
        string empty;
        getline(cin, empty);
        int N, M;
        cin >> M >> N;
        for(int j = 0; j < M; j++){
            int x;
            cin >> x;
            A.push_back(x);
        }
        int counter = 0;
        for(int j = 0; j < N; j++){
            int x;
            cin >> x;
            for(int k = counter; k < x ; k++){
                U.insert(upper_bound(U.begin(), U.end(), A[k]), A[k]);
            }
            cout << U[i] << endl;
            i++;
            counter = x;
        }
    }
}