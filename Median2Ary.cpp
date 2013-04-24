

/*

Median of Two Sorted Arrays
  
There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

*/
  
#include <iostream>

using namespace std;


/*

  O(n)
  
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    int mid = (m+n)/2;
    int idx = 0;
    int i = 0;
    int j = 0;
    int sum = 0;
    int ret = 0;
    
    while(i < m && j < n && idx <= mid)
    {
        if(A[i] < B[j])
        {
            sum = ret + A[i];
            ret = A[i++];                
        }
        else
        {                
            sum = ret + B[j];
            ret = B[j++];
        }
        idx++;
    }
        
    if(i == m && idx <= mid)
    {
        while(j < n && idx <= mid)
        {
            sum = ret + B[j];
            ret = B[j++];
            idx++;
        }
    }
        
    if(j == n && idx <= mid)
    {
        while(i < m && idx <= mid)
        {
            sum = ret + A[i];
            ret = A[i++];
            idx++;
        }
    }
        
    if( (m+n)%2 == 0)
    {
        return (double)sum/(double)2;
    }
    else
    {
        return ret;
    }        
}

*/


 /*

   O(lgn))
int findMedianSortedArrays(int A[], int beg_a, int end_a, int B[], int beg_b, int end_b, int k)
{

    cout << "beg_a="<<beg_a << ", end_a= " << end_a << ", beg_b=" << beg_b << ", end_b=" << end_b << ", k=" << k << endl;
    
    if(beg_a > end_a)
        return B[beg_b + k -1];

    if(beg_b > end_b)
        return A[beg_a + k -1];   
    
    int mid_a = (beg_a + end_a) >> 1;
    int mid_b = (beg_b + end_b) >> 1;
    
    int len = mid_a - beg_a + mid_b - beg_b + 2;

    if(len > k)
    {
        if(A[mid_a] > B[mid_b] )
        {
            return findMedianSortedArrays(A, beg_a, mid_a -1, B, beg_b, end_b, k);
        }
        else
        {
            return findMedianSortedArrays(A, beg_a, end_a, B, beg_b, mid_b -1, k);
        }   
    }
    else
    {
        if(A[mid_a] > B[mid_b])
        {
            return findMedianSortedArrays(A, beg_a, end_a, B, mid_b+1, end_b, k - (mid_b - beg_b+1));
        }
        else
        {
            return findMedianSortedArrays(A, mid_a+1, end_a, B, beg_b, end_b, k-(mid_a - beg_a+1));
        }
    }
}
 */

int FindKth(int A[], int m, int B[], int n, int k)
{
    //Keep the A is the shorter array.
    if (m > n) return FindKth(B, n, A, m, k);

    if (m == 0) return B[k - 1];
    if (k == 1) return std::min(A[0], B[0]);
    
    //set pa and pb pointer
    int pa = min(k/2, m);
    int pb = k - pa;
 
    if (A[pa - 1] < B[pb - 1])
        return FindKth(A + pa, m - pa, B, n, k - pa);
    
    return FindKth(A, m, B + pb, n - pb, k - pb);
}
  
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    if((m+n)%2 == 0)
    {
        //       return (double)(findMedianSortedArrays(A, 0, m - 1, B, 0, n -1, (n+m)/2+1)
        //                + findMedianSortedArrays(A, 0, m - 1, B, 0, n -1, (n+m)/2))/2;
        return (double)(FindKth(A, m, B, n, (n+m)/2+1) + FindKth(A, m, B, n, (n+m)/2))/2;
    }
    else
        //return findMedianSortedArrays(A, 0, m - 1, B, 0, n -1, (n+m)/2+1);
        return FindKth(A, m, B, n, (n+m)/2+1);    
}


int main()
{
    int A[] = {3, 4, 5, 6, 7, 8};

    int B[] = {};

    cout<<"Median = "<<findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int))<<endl;    
    
}

