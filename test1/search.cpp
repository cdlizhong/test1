//
//  search.cpp
//  test1
//
//  Created by cdlizhong on 16/1/5.
//  Copyright © 2016年 cdlizhong. All rights reserved.
//

#include "search.hpp"

int binarySearch(int a[],int len,int e)
{
    int l = 0;
    int r = len-1;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if(a[mid] == e)
        {
            return mid;
        }else if (a[mid] < e)
        {
            l = mid + 1;
        }else if (a[mid] > e)
        {
            r = mid -1;
        }
    }
    return -1;
}

int maxContinousSub_1(int a[],int len)
{
    int maxsofa = 0;
    for(int i=0;i<len;i++)
    {
        int sum = 0;
        for(int j = i;j<len;j++)
        {
            sum = sum + a[j];
            if( maxsofa < sum)
            {
                maxsofa = sum;
            }
        }
    }
    return maxsofa;
}

inline int max(int a,int b)
{
    return a > b?a:b;
}

int maxContinousSub_2(int a[],int len)
{
    int maxEnd = 0;
    int maxSofa = 0;
    for(int i=0;i<len;i++)
    {
        maxEnd = max(maxEnd+a[i],0);
        maxSofa = max(maxEnd,maxSofa);
    }
    return maxSofa;
}