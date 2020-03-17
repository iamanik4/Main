'''Problem:
Given a list of stock prices on each day d, and number of allowed transactions k, find the maximum profit which can be obtained.

One transaction means buying a stock on day n and selling on m where 0<=n<m<=d also the user can have only one stock at a time'''

# O(nk) time | O(nk) space
def maxProfitWithKTransactions(prices, k):
    if not prices:
        return 0
    
    profits = [[0 for d in prices]for t in range(k+1)]
    for t in range(1,k+1):
        maxThusFar = float('-inf')
        for d in range(1,len(prices)):
            maxThusFar = max(maxThusFar, profits[t-1][d-1]-prices[d-1])
            profits[t][d] = max(prices[d] + maxThusFar, profits[t][d-1])
    return profits[-1][-1]



# O(nk) time | O(n) space
def maxProfitWithKTransactions2(prices, k):
    if not prices:
        return 0
    
    oddProfits = [0 for d in prices]
    evenProfits = [0 for d in prices]

    for t in range(1,k+1):  
        maxThusFar = float('-inf')
        if t%2 == 1:
            currentProfits = oddProfits
            previousProfits = evenProfits
        else:
            currentProfits = evenProfits
            previousProfits = oddProfits
        
        for d in range(1,len(prices)):
            maxThusFar = max(maxThusFar,previousProfits[d-1]-prices[d-1])
            currentProfits[d] = max(prices[d]+maxThusFar, currentProfits[d-1])
    return evenProfits[-1] if k%2==0 else oddProfits[-1]

print(maxProfitWithKTransactions2([5,11,3,50,60,90],2))
print(maxProfitWithKTransactions([5,11,3,50,60,90],2))