#include <iostream>
#include <set>
#include <iterator>

using namespace std;


/*
  Longest Substring Without Repeating Characters
  
  Given a string, find the length of the longest substring without repeating characters.
  For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
  For "bbbbb" the longest substring is "b", with the length of 1.
 */

int lengthOfLongestSubstring(string s)
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
        
    int idx = 0;
    int max = 0;
    int count = 0;    
    char chars[256] = {};
    
    for(int i =0; i < s.size(); ++i)
    {
        if(chars[s[i]] == 1)
        {
            while(idx<i)
            {
                if(s[i] != s[idx])
                {
                    chars[s[idx++]] = 0;
                    count--;                    
                }
                else
                {
                    idx++;
                    break;
                }
            }                
        }
        else
        {
            chars[s[i]] = 1;
            count++;            
            max = std::max(max, count);
        }
    }
        
    return max;        
}

int main()
{
    cout<<"Longest sub str = "<<lengthOfLongestSubstring("abcdcefcg")<<endl;    
}
