#include <string>
#include <iostream>

using namespace std;

string convert(string s, int nRows) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
        
    if(nRows < 2)
        return s;
        
    string ret;
    int step = (nRows - 1) * 2;
    for(int j = 0; j < nRows; ++j)
    {
        int count = 0;
        if((j%step == 0) || ((j+1)%step == 0))
            count = step;
        else
            count = 2*j;
        
        for(int i = j; i < s.size(); i += count  )
        {
            ret += s[i];
            if(count != step)
                count = step - count;
        }
    
    }
    return ret;
}

int main()
{
    string src = "PAYPALISHIRING";

    cout<<"2 :"<<convert(src, 2)<<endl;
    cout<<"3 :"<<convert(src, 3)<<endl;
    cout<<"4 :"<<convert(src, 4)<<endl;
}
