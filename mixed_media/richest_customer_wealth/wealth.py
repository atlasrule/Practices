from random import randint

M, N = 3, 3
min_balance, max_balance = -10000, 100000

def create_accounts():
  accounts = [[randint(min_balance, max_balance) for _ in range(N)]
              for _ in range(M)]
  return accounts


def max_wealth(accounts):
  max_balance = -1
  for i in range(M):
    balance = 0
    for j in range(N):
      balance += accounts[i][j]
    if balance > max_balance:
      max_balance = balance
  return max_balance


def max_wealth_2(accounts):
  return sum(max(accounts, key=sum))


accounts = create_accounts()
print(accounts)
print(max_wealth(accounts))
print(max_wealth_2(accounts))
