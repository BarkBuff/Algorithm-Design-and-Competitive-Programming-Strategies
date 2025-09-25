#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

int solve(vi &L) {

    int cost = 0;

    for(int i = 0; i < L.size()-1; i++) {

        int min = *min_element(L.begin() + i, L.end());

        auto x = find(L.begin(), L.end(), min);

        reverse(L.begin()+i, x+1);

        cost += distance(L.begin(), x) - i + 1;
        
    }

    return cost;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int C = 1; C <= T; C++) {

        int N;
        cin >> N;

        vi L;

        for(int i = 0; i < N; i++) {
            int num;
            cin >> num;
            L.push_back(num);
        }

        cout << "Case #" << C << ": " << solve(L) << endl;

    }
}