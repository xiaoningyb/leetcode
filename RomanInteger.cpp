#include <string>
#include <iostream>

using namespace std;

const string roman_str[] = {"I", "V", "X",  "L",  "C",   "D",   "M"};
const char roman_char[] = {'I', 'V', 'X',  'L',  'C',   'D',   'M'};
const int roman_int[]      = { 1,   5,   10,   50,   100,   500,   1000};

    

/*
  Roman to Integer

  Given a roman numeral, convert it to an integer.
  Input is guaranteed to be within the range from 1 to 3999.
*/

int getRomanValue(char c)
{
    switch(c)
    {  
    case 'I': return 1;   
    case 'V': return 5;  
    case 'X': return 10;  
    case 'L': return 50;  
    case 'C': return 100;  
    case 'D': return 500;  
    case 'M': return 1000;  
    default: return 0;  
    }  
}  

int romanToInt(string s)
{
    int ret = 0;
    int idx = 0;
    
    while(idx != s.size())
    {
        int i = 0;
        int j = 0;
        for(;i < 7; ++i)
        {
            if(s[idx] == roman_char[i])
                break;
        }

        if(idx + 1 != s.size())
        {   
            for(;j < 7; ++j)
            {
                if(s[idx+1] == roman_char[j])
                    break;
            }
        }
        
        if( i < j)
        {
            ret += roman_int[j] - roman_int[i];
            idx++;
        }
        else
        {
            ret += roman_int[i];
        }
        idx++;
    }
    
    return ret;
}

/*
  Integer to Roman

  Given an integer, convert it to a roman numeral.

  Input is guaranteed to be within the range from 1 to 3999.
 */

string intToRoman(int num)
{
    string ret ;
    int i = 0;
    
    while(num)
    {
        int sub = num % 10;
        if(sub <= 3 && sub > 0)
        {
            for(int j = 0; j < sub; ++j)
            {
                ret = roman_str[i] + ret;
            }
        }
        else if(sub >5  && sub <= 8)
        {
            for(int j = 5; j < sub; ++j)
            {
                ret = roman_str[i] + ret;
            }
            ret = roman_str[i+1] + ret;
        }
        else if (sub == 4)
        {
            ret = roman_str[i] + roman_str[i+1] + ret;
        }
        else if (sub == 5)
        {
            ret = roman_str[i+1] + ret;
        }
        else if (sub == 9)
        {
             ret = roman_str[i] + roman_str[i+2] + ret;
        }
        
        i += 2;
        num = num /10;
    }

    return ret;
}


 string intToRoman2(int number)
 {  
     int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };  
     string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };  
     string result;
     for (int i = 0; i < sizeof(values)/sizeof(int); i++)
     {  
         while (number >= values[i]) {  
             number -= values[i];  
             result.append(numerals[i]);  
         }  
     }  
     return result;  
 }  

int main()
{
    cout<<intToRoman(1)<<endl;
    cout<<intToRoman(2)<<endl;
    cout<<intToRoman(3)<<endl;
    cout<<intToRoman(4)<<endl;
    cout<<intToRoman(5)<<endl;
    cout<<intToRoman(6)<<endl;
    cout<<intToRoman(7)<<endl;
    cout<<intToRoman(8)<<endl;
    cout<<intToRoman(9)<<endl;
    cout<<intToRoman2(10)<<endl;

    cout<<intToRoman2(3999)<<endl;


    cout<<romanToInt("I")<<endl;
    cout<<romanToInt("II")<<endl;
    cout<<romanToInt("III")<<endl;
    cout<<romanToInt("IV")<<endl;
    cout<<romanToInt("V")<<endl;
    cout<<romanToInt("VI")<<endl;
    cout<<romanToInt("VII")<<endl;
    cout<<romanToInt("VIII")<<endl;
    cout<<romanToInt("IX")<<endl;
    cout<<romanToInt("X")<<endl;
    cout<<romanToInt("XI")<<endl;

    cout<<romanToInt("MMMCMXCIX")<<endl;
    
    return 0;
}
