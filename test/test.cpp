#include "bits/stdc++.h"
using namespace std;
int main()
{
    system("g++ F:/Code/C++/test/bf.cpp -o F:/Code/C++/test/bf.exe");
    system("g++ F:/Code/C++/test/sol.cpp -o F:/Code/C++/test/sol.exe");
    int t=1000;
    while (t--)
    {
        system("F:/Code/C++/test/random.exe");
        system("F:/Code/C++/test/bf.exe");
        int st=clock();
        system("F:/Code/C++/test/sol.exe");
        int en=clock();
        if (en-st>1000)
        {
            cout<<"TLE\n";
            system("pause");
        }
        if (system("fc F:/Code/C++/test/data.out F:/Code/C++/test/data.ans"))
        {
            cout<<"Wrong Answer,time:"<<st-en<<"\n";
            system("pause");
            return 0;
        }else
        {
            cout<<"Accept\n";
        }
    }
    return 0;
}