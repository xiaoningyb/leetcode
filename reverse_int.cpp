#include <iostream>
#include <cmath>


using namespace std;

int reverse(int x)
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

    if (x < 0)
        return reverse(-x) * -1;  

    int ret = 0;
    
    while(x != 0)
    {
        ret = ret * 10 + x % 10;

        x = x / 10;
    }
    
    return ret;
}


int main()
{
    cout<<reverse(-123)<<endl;
    cout<<reverse(0)<<endl;
    cout<<reverse(10)<<endl;    
}
