/*
  Regular Expression Matching
  
  Implement regular expression matching with support for '.' and '*'.

  '.' Matches any single character.
  '*' Matches zero or more of the preceding element.

  The matching should cover the entire input string (not partial).

  The function prototype should be:
  bool isMatch(const char *s, const char *p)
  
  Some examples:
  isMatch("aa","a") ? false
  isMatch("aa","aa") ? true
  isMatch("aaa","aa") ? false
  isMatch("aa", "a*") ? true
  isMatch("aa", ".*") ? true
  isMatch("ab", ".*") ? true
  isMatch("aab", "c*a*b") ? true  
*/

#include <iostream>
#include <string>
using namespace std;

bool isMatch(const char *s, const char *p)
{
    cout<<"check s = "<<s<<", and p = "<<p<<endl;
    
    if (*p == '\0')
        return *s == '\0';

    if(*(p+1) == '*')
    {
        while((*s == *p) || ((*p == '.') && (*s != '\0')))
        {
            if(isMatch(s++, p+2))
                return true;
        }
 
        if(isMatch(s, p+2))
            return true;
    }
    else if(*s != '\0' && (*s == *p || *p == '.'))
    {
        return isMatch(s+1, p+1);
    }
   
    return false;
}


int main()
{
    cout<<(isMatch("b", "") ? "true" : "false")<<endl;

    return 0;
}

