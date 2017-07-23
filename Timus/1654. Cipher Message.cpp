// The solution of the problem was written by Izaron
// Date: 21:48:52   12 Mar 2015
// Execution time: 0.156

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include<iostream>
#include<string.h>
#include<deque>
#include<stdio.h>
using namespace std;
int main()
{
    string node;
    cin >> node;
    int one,two;
    one = 0;
    two = 1;
    int pre = 0;
    for(int i = 0;i < node.size();i++)
    {
        if(node[i] == '!')
        continue;
        if(node[i] == node[i+1])
        {
            node[i] = node[i+1] = '!';
            one = pre;
            if(i+2 < node.size())
            two = i+2;
            while(one> 0 && two < node.size())
            {
                while(one > 0 && node[one] == '!')
                one--;
                if(node[one] == node[two] )
                {
                    node[one] = node[two] = '!';
                    one--;two++;
                }
                else
                break;
            }
        }
        else
        pre = i;

    }

   for(int i = 0;i < node.size();i++)
   {
       if(node[i] != '!')
       cout << node[i];
   }

}