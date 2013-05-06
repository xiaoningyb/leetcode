
#include <iostream>
#include <climits>
using namespace std;

int ch2i(char ch)
{
    if(ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }

    return -1;
}



int atoi(const char *str)
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    while(*str == ' ')
    {
        str++;
    }
    
    int plus = 1;
    if(str[0] == '-')
    {
        plus = -1;
        str++;
    }
    else if (str[0] == '+')
    {
        str++;
    }

    int i = 0;
    int ret = 0;
    
    while( (i = ch2i(*str))  != -1)
    {
        if( (INT_MAX - i) / 10 < ret )
        {
            return (plus == 1 ? INT_MAX : INT_MIN);
        }
        
       ret  = ret * 10 + i;
       cout<< ret <<endl;
       str++;
    }

    return plus * ret;    
}


int main()
{
    cout<<atoi("-10441643317j")<<endl;
}

