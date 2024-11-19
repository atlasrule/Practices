#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define M 3
#define N 3
#define MIN_BALANCE -10000
#define MAX_BALANCE 100000

// Create accounts
void createAccounts(int accounts[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            accounts[M][N] = (rand() % (MAX_BALANCE - MIN_BALANCE)) + MIN_BALANCE;
        }
    }
}

// Calculate maximum wealth
int maxWealth(int accounts[M][N]) {
    int wealthMax = INT_MIN;
    for (int i = 0; i < M; i++) {
        int wealth = 0;
        for (int j = 0; j < N; j++) {
            wealth += accounts[i][j];
        }
        if (wealth > wealthMax) {
            wealthMax = wealth;
        }
    }
    return wealthMax;
}

int main() {
    srand(time(NULL));

    int accounts[M][N];

    createAccounts(accounts);

    printf("Account balances:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", accounts[i][j]);
        }
        printf("\n");
    }

    // Calculate and print maximum wealth
    int max_wealth = maxWealth(accounts);
    printf("Maximum wealth: %d\n", max_wealth);

    return 0;
}
