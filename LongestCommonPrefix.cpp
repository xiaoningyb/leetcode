#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

/*
  Longest Common Prefix

  Write a function to find the longest common prefix string amongst an array of strings.
*/

string longestCommonPrefix(vector<string> &strs)
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(strs.empty())
    {
        return string();
    }
    
    size_t idx = 0;
    while(idx < strs[0].size())
    {
        for(int i = 1; i < strs.size(); ++i)
        {
            if(idx > strs[i].size() || strs[i][idx] != strs[0][idx])
            {
                return strs[0].substr(0, idx);
            }            
        }
        ++idx;
    }

    return strs[0];
}


int main()
{
    vector<string> strs;
    strs.push_back("ba");
    strs.push_back("b");
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
    
}
