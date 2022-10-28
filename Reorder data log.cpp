/*
Reorder Data in Log Files

You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

Reorder these logs so that:
The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.*/


#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main(){ 
    vector <string> logs{"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    vector<string> digitLogs, letterLogs;
        for (string &s : logs) {
            int i = 0;
            while (s[i] != ' ') ++i;
            if (isalpha(s[i + 1])) {letterLogs.push_back(s.substr(i + 1) + " " + s.substr(0, i));
            cout<<s.substr(0,i)<<endl;}
            else digitLogs.push_back(s);
        }
        sort(letterLogs.begin(), letterLogs.end());
        for (string &s : letterLogs) {
            int i = s.size() - 1;
            while (s[i] != ' ') --i;
            s = s.substr(i + 1) + " " + s.substr(0, i);
        }
        for (string &s : digitLogs) letterLogs.push_back(s);
        for(auto i: letterLogs){
            cout<< i;
        }
    }

