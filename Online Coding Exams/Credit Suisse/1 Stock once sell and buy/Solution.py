import sys
# You may change this function parameters
def findMaxProfit(numOfPredictedDay, predictedSharePrices):
    # Participants code will be here
    if(numOfPredictedDay < 2):
        return -1

    s_ptr = 0
    f_ptr = 1
    max_profit = 0
    sell = 0
    while(f_ptr < len(predictedSharePrices)):
        profit = predictedSharePrices[f_ptr] - predictedSharePrices[s_ptr]

        if(profit < 0):
            s_ptr = f_ptr
            max_profit = 0
        elif(profit > max_profit):
            max_profit = profit

        f_ptr += 1
    
    return max_profit


def main():
    line = input().split()
    numOfPredictedDay = int(line[0])
    predictedSharePrices = list(map(int, line[1:]))

    answer = findMaxProfit(numOfPredictedDay, predictedSharePrices)

    # Please do not remove the below line.
    print(answer)
    # Do not print anything after this line

if __name__ == '__main__':
    main()
