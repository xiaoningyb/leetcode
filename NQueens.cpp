#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iterator>
using namespace std;

/*
  N-Queens

  The n-queens puzzle is the problem of placing n queens on an n*n chessboard such that no two queens attack each other.

  Given an integer n, return all distinct solutions to the n-queens puzzle.

  Each solution contains a distinct board configuration of the n-queens' placement,
  where 'Q' and '.' both indicate a queen and an empty space respectively.

  For example,
  There exist two distinct solutions to the 4-queens puzzle:

  [
    [".Q..",  // Solution 1
    "...Q",
    "Q...",
    "..Q."],

    ["..Q.",  // Solution 2
    "Q...",
    "...Q",
    ".Q.."]
  ]
*/

void print(const vector<string>& chess)
{
    cout<<"["<<endl;
    for(int i =0; i < chess.size(); ++i)
    {
        cout<<" "<< chess[i]<<endl;   
    }
    cout<<"]"<<endl;
}

/*

bool check_chess(vector<string>& chess, int m, int n, int size)
{
    for(int i = 0; i < size; ++i)
    {
        if(chess[m][i] == 'Q' || chess[i][n] == 'Q')
            return false;
    }

    int min = std::min(m, n);
    int m1 = m - min;
    int n1 = n - min;

    for(;m1 < size && n1 < size; m1++, n1++)
    {
         if(chess[m1][n1] == 'Q')
             return false;
    }

    for(m1 = m, n1 = n; (size > m1 ) && (n1 >= 0); m1++, n1--)
    {
        if(chess[m1][n1] == 'Q')
            return false;
    }
    
    for(m1 = m, n1 = n; m1 >=0 && n1 < size; m1--, n1++)        
    {
        if(chess[m1][n1] == 'Q')
            return false;
    }
    
    return true;
}

void resolve_chess(vector<string>& chess, int count, int n, set< vector<string> >& ret, set< vector<string> >& solved)
{
    if(solved.find(chess) != solved.end())
    {
        return;
    }
    
    if(count == n)
    {
        ret.insert(chess);
        return;
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(check_chess(chess, i , j, n))
            {
                count++;
                chess[i][j] = 'Q';
                
                resolve_chess(chess, count, n, ret, solved);
                solved.insert(chess);
                
                chess[i][j] = '.';
                count--;
            }            
        }
    }
}

vector< vector<string> > solveNQueens(int n)
{
    set< vector<string> > ret;
    set< vector<string> > solved;

    string row(n, '.');
    vector<string> chess(n, row);
    int count = 0;

    resolve_chess(chess, count, n, ret, solved);
    
    return vector< vector<string> >(ret.begin(), ret.end()) ;
}

*/

bool check_chess(vector<int>& queens, int row, int col, int n)
{
    for(int i = 0; i < row; ++i)
    {
        /*
        if(queens[i] == col)
        {
            return false;
        }
        else if ((queens[i] + i) == (row + col))
        {
            return false;
        }
        else if ((queens[i] - i) == (col - row))
        {
            return false;
        }
        */
        int diff = abs(queens[i] - col);
        if (diff == 0 || diff == row - i)
        {
            return false;  
        }  
    }
     
    return true;
}

void resolve_chess(vector<int>& queens, int row, int n, vector< vector<int> >& ret)
{
    if(row == n)
    {
        ret.push_back(queens);
        return;
    }
    
    for(int col = 0; col < n; ++col)
    {
        if(check_chess(queens, row, col, n))
        {
            queens[row] = col;
            resolve_chess(queens, row+1, n, ret);
        }
    }
}


vector< vector<string> > solveNQueens(int n)
{
    vector< vector<int> > ret;
    vector< vector<string> > ret_chess;
    vector<int> queens(n, -1000);
    int row = 0;
    
    resolve_chess(queens, row, n, ret);

    for(vector< vector<int> >::iterator it = ret.begin(); it != ret.end(); ++it)
    {
        string row(n, '.');
        vector<string> chess(n, row);
        for(int i = 0; i < it->size(); ++i)
        {
            chess[i][(*it)[i]] = 'Q';
        }
        ret_chess.push_back(chess);
    }
    
    return ret_chess;
}


void resolve_total_chess(vector<int>& queens, int row, int n, int& count)
{
    if(row == n)
    {
        ++count;
        return;
    }
    
    for(int col = 0; col < n; ++col)
    {
        if(check_chess(queens, row, col, n))
        {
            queens[row] = col;
            resolve_total_chess(queens, row+1, n, count);
        }
    }
}

int totalNQueens(int n)
{
    int count = 0;
    
    vector<int> queens(n);
    int row = 0;
    
    resolve_total_chess(queens, row, n, count);

    return count;
}

int main()
{
    cout <<"totol solution = "<< totalNQueens(16) <<endl;
    
    return 0;
}

