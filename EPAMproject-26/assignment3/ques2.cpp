#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumLearningPoints(vector<int>& topics) {
    int n = topics.size();

    if (n == 1) {
        return topics[0];
    }

    vector<int> dp(n);

    dp[0] = topics[0];
    dp[1] = max(topics[0], topics[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + topics[i]);
    }

    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;

    vector<int> topics(n);

    for (int i = 0; i < n; i++) {
        cin >> topics[i];
    }

    cout << maximumLearningPoints(topics);

    return 0;
}