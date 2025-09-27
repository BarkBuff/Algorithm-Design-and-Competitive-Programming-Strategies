#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

void solve(int N, int CC, int C) {
    int minCost = N - 1;
    int maxCost = (N * (N + 1)) / 2 - 1;

    if (CC < minCost || CC > maxCost) {
        cout << "Case #" << C << ": IMPOSSIBLE\n";
        return;
    }

    // Start with the sorted array
    vector<int> arr(N);
    iota(arr.begin(), arr.end(), 1);

    int remainingCost = CC;

    for (int i = 0; i < N - 1; i++) {
        // Remaining positions left
        int remaining = N - i;
        // Max cost we could spend at this step
        int maxHere = remaining - 1;
        // Min cost we need to reserve for the rest
        int minNeeded = (N - 1 - i);
        // Spend as much as possible but leave enough
        int spend = min(maxHere, remainingCost - minNeeded);
        remainingCost -= spend;

        // Reverse the right subarray
        reverse(arr.begin() + i, arr.begin() + i + spend + 1);
    }

    cout << "Case #" << C << ":";
    for (int x : arr) cout << " " << x;
    cout << "\n";
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int C = 1; C <= T; C++) {
        int N, CC;
        cin >> N >> CC;
        solve(N, CC, C);
    }
}