#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    vector<int> wt = {1, 2, 3, 12, 22, 30};
    vector<int> val = {40, 30, 60, 80, 90, 99};
    int W = 20;
    int n = wt.size();

    cout << "Maximum value that can be obtained: " << knapSack(W, wt, val, n) << endl;

    return 0;
}
