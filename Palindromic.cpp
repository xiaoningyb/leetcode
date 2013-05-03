
#include <string>
#include <iostream>

using namespace std;

/*
bool is_palindromic(string str, int low, int high)
{
    if(high < low)
        return false;    
    
    while(low<high)
    {
        if(str[low] != str[high])
            return false;
        low++;
        high--;        
    }

    return true;    
}

string longestPalindrome(string s)
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int max = 0;
    string ret;    

    for(int i = 0; i < s.size(); ++i)
    {
        for(int j = i + max; j < s.size(); ++j)
        {
            if(is_palindromic(s, i, j))
            {
                if((j - i + 1) > max)
                {
                    ret = s.substr(i, j-i+1);
                    max = j - i + 1;
                }                
            }            
        }        
    }

    return ret;        
}

*/


string findPal(string &s, int left, int right)
{
    if (left < 0)
        return s.substr(left+1, 1);
    
    if (right >= s.size())
        return s.substr(right-1, 1);
    
    while(0 <= left && right < s.size())
    {
        if (s[left] != s[right])
            break;
        left--;
        right++;
    }
    
    left++;
    right--;
    
    return s.substr(left, right - left + 1);        
}
     
string longestPalindrome(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (s.size() == 0)
        return "";
    
    string ret;
    
    for(int i = 0; i < s.size(); i++)
    {
        string str = findPal(s, i - 1, i + 1);
        if (str.size() > ret.size())
            ret = str;
        
        str = findPal(s, i, i + 1);
        if (str.size() > ret.size())
            ret = str;
    }
    
    return ret;
}

int main()
{
    string str = "aabcaa";

    cout<<"In string("<<str<<"), Longest Palindrome is("<< longestPalindrome(str)<<")"<<endl;

    return 0;
}

