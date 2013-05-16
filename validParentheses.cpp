// 15:14

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <sys/time.h>
using namespace std;

/*
  Valid Parentheses
  
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
  determine if the input string is valid.
  
  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

bool need_push(char ch)
{
    if(ch == '(' || ch == '[' || ch == '{')
        return true;
    return false;
}

bool need_pop(char ch)
{
    if(ch == ')' || ch == ']' || ch == '}')
        return true;
    return false;
}

bool check(char ch1, char ch2)
{
    switch(ch1)
    {
    case '(' :
        if(ch2 == ')')
            return true;
        break;
    case '[' :
        if(ch2 == ']')
            return true;
        break;
    case '{' :
        if(ch2 == '}')
            return true;
        break;
    }

    return false;
}

bool check_bracket(string& str)
{
    stack<char> st;
    for(string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if(need_push(*it))
        {
            st.push(*it);
        }
        else if(need_pop(*it))
        {
            if(st.empty() || !check(st.top(), *it))
                return false;
            st.pop();
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}

int find_max_bracket(string str)
{
    stack<char> st;
    int * flag = new int[str.size()];
    memset(flag, 0, str.size()*sizeof(int));
    
    for(int i =0; i< str.size(); ++i)
    {
        if(need_push(str[i]))
        {
            st.push(i);
        }
        else if(need_pop(str[i]))
        {
            if(st.empty() || !check(str[st.top()], str[i]))
            {
                flag[i] = 0;
            }
            else
            {
                flag[st.top()] = 1;
                flag[i] = 1;
                st.pop();
            }            
        }
    }

    int max = 0;
    int sum = 0 ;
    for(int i = 0; i < str.size(); ++i)
    {
        cout<<"flag["<<i<<"]"<<flag[i]<<endl;
        if(flag[i] == 1)
        {
            sum++;
        }
        else
        {
            max = std::max(max, sum);
            sum = 0;
        }
    }
    return std::max(max, sum);
}

int main()
{
    string str;
    while(cin>>str)
    {
        if(check_bracket(str))
        {
            cout<<"valid!"<<endl;
        }
        else
        {
            cout<<"invalid!"<<endl;
        }

        cout<<"find max bracket size = "<<find_max_bracket(str)<<endl;
        
    }

    return 0;    
}
