#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

// #define USE_TXT

void cppReady() {
#if defined(USE_TXT)
    // ios_base::sync_with_stdio(false); cin.tie(NULL); freopen("TestCases.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); freopen("TestCases.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
}

int hCost[1001][3];
int hCalc[1001][3];

int main(void) {
    cppReady();
    int hCnt;
    cin >> hCnt;

    for (int i = 1; i <= hCnt; i++) {
        cin >> hCost[i][0];
        cin >> hCost[i][1];
        cin >> hCost[i][2];
        // cout << hCost[i][0] << ' ' << hCost[i][1] << ' ' << hCost[i][2] << '\n';
    }

    for (int i = 1; i <= hCnt; i++) {
        hCalc[i][0] = min(hCalc[i-1][1], hCalc[i-1][2]) + hCost[i][0];
        hCalc[i][1] = min(hCalc[i-1][0], hCalc[i-1][2]) + hCost[i][1];
        hCalc[i][2] = min(hCalc[i-1][0], hCalc[i-1][1]) + hCost[i][2];
    }

    int result = min(hCalc[hCnt][0], hCalc[hCnt][1]);
    result = min(result, hCalc[hCnt][2]);
    cout << result;

    return 0;
}
