/*
  Determine whether an integer is a palindrome. Do this without extra space.

  Some hints:
  Could negative integers be palindromes? (ie, -1)
  
  If you are thinking of converting the integer to string, note the restriction of using extra space.
  
  You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
  you know that the reversed integer might overflow. How would you handle such case?
  
  There is a more generic way of solving this problem.
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPalindrome(int x)
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

    // negative integers is not palindromes
    if(x < 0)
        return false;

    int n = 1;
     
    while( x / n >= 10)
    {
        n *= 10;
    }

    while(x)
    {
        if((x % 10) != (x / n))
            return false;

        x = (x % n) / 10;
        n /= 100;
    }

    return true;
}

int main()
{

    cout<<(isPalindrome(12) ? "true" : "false")<<endl;
    cout<<(isPalindrome(121) ? "true" : "false")<<endl;
    cout<<(isPalindrome(1221) ? "true" : "false")<<endl;
    cout<<(isPalindrome(0) ? "true" : "false")<<endl;
    cout<<(isPalindrome(-121) ? "true" : "false")<<endl;

    cout<<(isPalindrome(-2147483648) ? "true" : "false")<<endl;
}

