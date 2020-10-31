#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int findMaxProfit(int numOfPredictedDays, vector<int> predictedSharePrices) {
    signed int s_ptr = 0, f_ptr = 1, max_profit = 0;

    while (f_ptr < numOfPredictedDays)
    {
        long int profit = predictedSharePrices[f_ptr] - predictedSharePrices[s_ptr];

        if(profit < 0)
        {
            s_ptr = f_ptr;
            max_profit = 0;
        }
        else if(max_profit < profit)
            max_profit = profit;
        
        f_ptr++;
    }
    

    return max_profit;
}

vector<int> splitStringToInt(const string& str, char delim) {
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec) {
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    string firstLine;
    getline(cin, firstLine);

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    int numOfPredictedDays = firstLineVec[0];
    vector<int> predictedSharePrices(firstLineVec.begin()+1, firstLineVec.end());


    int result = findMaxProfit(numOfPredictedDays, predictedSharePrices);

    // Do not remove this line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}