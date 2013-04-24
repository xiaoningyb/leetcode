/*
  
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        map<int, int> num_map;        
        for(int i =0; i < numbers.size(); ++i)
        {
            num_map[numbers[i]] = i;
        }
        
        vector<int> ret;        
        for(int j = 0; j < numbers.size(); ++j)
        {
            int find = target - numbers[j];
            map<int, int>::iterator it = num_map.find(find);
            if(it != num_map.end() && it->second != j)
            {
                int index = it->second;
                if(index < j)
                {
                    ret.push_back(index+1);
                    ret.push_back(j+1);            
                }
                else
                {
                    ret.push_back(j+1);
                    ret.push_back(index+1);
                }
                return ret;
            }            
        }
        
        return ret;        
    }
};
