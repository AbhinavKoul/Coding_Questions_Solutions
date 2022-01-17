//https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/

//Explanation --> https://www.youtube.com/watch?v=JbRsM2X2_pg

// Similar to min Palindrome Cuts --> https://www.youtube.com/watch?v=qmTtAbOTqcg

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define v vector

int findWaysParenthesis(string str1, string str2)
{
  int n = str1.length();
  v<v<int>> dpt(n, v<int>(n, 0));   //track of getting true as result b/w (i..j)
  v<v<int>> dpf(n, v<int>(n, 0));   //track of keeping false as result b/w (i..j)

  for (int g = 0; g < n; g++)
  {
    for (int i = 0, j = g; j < n; i++, j++)
    {
      if (g == 0)
      {
        if (str1[i] == 'T')
        {
          dpt[i][j] = 1;  //since getting true way is 1
          dpf[i][j] = 0;
        }
        else
        {
          dpt[i][j] = 0;
          dpf[i][j] = 1;
        }
      }
      else
      {
        /*
        here we need to one by one take operator inside paranthesis

        eg. T&F|T
            T &(F|T) + (T&F) | T

            T & F | T
        k =   0   1

            (0:0)*(0:2) + (0:1)*(1:2)
        k =      0              1       here j = 2 ==> k<j
        */

        //iterate operators one by one
        for (int k = i; k < j; k++)
        {
          char op = str2[k];

          //take variables outside
          int ltc = dpt[i][k];  //leftTrueCase
          int rtc = dpt[k + 1][j]; //right true case
          int lfc = dpf[i][k];  //left false case
          int rfc = dpf[k + 1][j]; //right false case

        //Permutaions --> do on notebbok, will get to know
          if (op == '&')
          {
            dpt[i][j] += ltc * rtc;
            dpf[i][j] += lfc * rtc + ltc * rfc + lfc * rfc;
          }
          else if (op == '|')
          {
            dpt[i][j] += ltc * rfc + lfc * rtc + ltc * rtc;
            dpf[i][j] += lfc * rfc;
          }
          else    //xor(^)
          {
            dpt[i][j] += ltc * rfc + lfc * rtc;
            dpf[i][j] += ltc * rtc + lfc * rfc;
          }
        }


      }
    }
  }

  return dpt[0][n - 1];
}
int main()
{
  string str1, str2;
  cin >> str1;
  cin >> str2;

  cout << findWaysParenthesis(str1, str2);
  return 0;
}




