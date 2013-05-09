
/*
  Container With Most Water
  Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
  n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
  Find two lines, which together with x-axis forms a container, such that the container contains the most water.

  Note: You may not slant the container.
 */

/*
  O(n^2))
int maxArea(vector<int> &height)
{
// Start typing your C/C++ solution below
// DO NOT write int main() function
    int n = height.size();
        
    int max = 0;
    for(int i =0; i < n; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            max = std::max(max, std::min(height[i], height[j]) * (j -i) );
        }
    }
        
    return max;
}

 */

int maxArea(vector<int> &height)
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int i = 0;
    int j = height.size() - 1;
         
    int max = 0;
    while(i < j)
    {
        max = std::max(ret, (j - i) * min(height[i], height[j]));
             
        if (height[i] <= height[j])
            i++;
        else
            j--;
    }
         
    return max;
}
