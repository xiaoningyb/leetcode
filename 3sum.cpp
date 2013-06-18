#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
  3Sum

  Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
  Find all unique triplets in the array which gives the sum of zero.

  Note:

  Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
  The solution set must not contain duplicate triplets.
  For example, given array S = {-1 0 1 2 -1 -4},

  A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*/

vector<vector<int> > threeSum(vector<int> &num)
{
    set<vector<int> > ret;

    if(num.size() < 3)
        return vector<vector<int> >(ret.begin(), ret.end());
    vector<int> sub_result(3, 0);
        
    std::sort(num.begin(), num.end());
    
    for(int i = 0; i < num.size() - 2; ++i)
    { 
        int low = i + 1;
        int high = num.size() - 1;
        
        while(low < high)
        {
            int sum = (num[i] + num[low] + num[high]);
            if(sum == 0)
            {
                sub_result[0] = num[i];
                sub_result[1] = num[low];
                sub_result[2] = num[high];
                ret.insert(sub_result);
                ++low;
                --high;
            }
            else if(sum < 0)
            {
                ++low;
            }
            else
            {
                --high;
            }
        }
    }
    
    return vector<vector<int> >(ret.begin(), ret.end());
}

int threeSumClosest(vector<int> &num, int target)
{
    int closest = num[0] + num[1] + num[2] ;
    std::sort(num.begin(), num.end());
    
    for(int i = 0; i < num.size() - 2; ++i)
    { 
        int low = i + 1;
        int high = num.size() - 1;
        
        while(low < high)
        {
            int sum = (num[i] + num[low] + num[high]);
            if(abs(sum - target) < abs(closest - target))
            {
                closest = sum;
            }
            
            if(sum == target)
            {
                return target;
            }
            else if ( sum < target )
            {
                ++low;
            }
            else
            {
                --high;
            }
        }
    }
    
    return closest;    
}
    
void print_result(const vector<vector<int> >& ret)
{
    for(int i = 0; i < ret.size(); ++i)
    {
        std::copy(ret[i].begin(), ret[i].end(), ostream_iterator<int>(cout, ", "));
        cout<<endl;
    }
}   

int main()
{
    int ary[] = {-4, -2, 8, -1, 3, 6, 9};
    vector<int> num(ary, ary+sizeof(ary)/sizeof(int));

    //print_result(threeSum(num));

    int ary2[] = {0, 0, 0, 0};
    vector<int> num2(ary2, ary2+sizeof(ary2)/sizeof(int));

    print_result(threeSum(num2));
    return 0;
}

