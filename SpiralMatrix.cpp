
#include <iostream>
#include <vector>
#include <iterator>
#include <cassert>
using namespace std;

/*
  Spiral Matrix
  Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

  For example,
  Given the following matrix:

  [
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
  ]
  You should return [1,2,3,6,9,8,7,4,5].
 */

vector<int> spiralOrder(vector<vector<int> > &matrix)
{
    if(matrix.empty())
        return vector<int>();

    int m2 = matrix.size();
    int n2 = matrix[0].size();
    int m1 = 0;
    int n1 = 0;
    int total = m2*n2;
    vector<int> ret(total, 0);
    int idx = 0;

    if(m2 == 1)
        return matrix[0];

    if(n2 == 1)
    {
        for(; idx < matrix.size(); ++idx)
        {
            ret[idx] = matrix[idx][0];
        }
    }
    
    int cur_row = 0;
    int cur_col = 0;
    
    while(idx < total -1)
    {
        for(; cur_col < n2 - 1; ++cur_col)
        {
            ret[idx++] = matrix[cur_row][cur_col];
        }
        ++m1;
        
        for(; cur_row < m2 - 1; ++cur_row)
        {
            ret[idx++] = matrix[cur_row][cur_col];
        }
        --n2;
        
        for(; cur_col > n1; --cur_col)
        {
            ret[idx++] = matrix[cur_row][cur_col];
        }
        --m2;
        
        for(; cur_row > m1; --cur_row)
        {
            ret[idx++] = matrix[cur_row][cur_col];
        }
        ++n1;
    }
    
    if(idx < total)
    {
        ret[idx] = matrix[cur_row][cur_col];
    }
    
    return ret;
}

void print_matrix(const vector<vector<int> >& matrix)
{
    cout<<"["<<endl;
    for(int i = 0 ; i < matrix.size(); ++i)
    {
        cout<<" [ ";
        std::copy(matrix[i].begin(), matrix[i].end(), ostream_iterator<int>(cout, ","));
        cout<<" ]"<<endl;
    }
    cout<<"]"<<endl;
}


int main()
{
    vector<vector<int> > matrix;

    int count = 7;
    for(int i = 0; i < 3; ++i)
    {
        vector<int> vec;
        vec.push_back(count++);
        //vec.push_back(count++);
        //vec.push_back(3);
        matrix.push_back(vec);
    }

    print_matrix(matrix);
    
    vector<int> ret = spiralOrder(matrix);
    
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ","));
    cout<<endl;
}

