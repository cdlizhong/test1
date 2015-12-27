//
//  shift.cpp
//  test1
//
//  Created by cdlizhong on 15/12/23.
//  Copyright © 2015年 cdlizhong. All rights reserved.
//

#include "shift.hpp"

void reverse(char s[],int sLen,int begin,int end)
{
    if (begin >= 0 && end <= sLen-1 && begin <= end)
    {
        while (begin < end)
        {
            char temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;
            begin++;
            end--;
        }
    }
}

void shift(char s[],int sLen,int shift) // shift > 0 move right shift < 0 move left
{
    if (shift%(sLen-1) == 0)
    {
        return;
    }else
    {
        shift = shift%(sLen-1);
    }
    if (shift > 0)
    {
        int charLen = sLen-1;
        reverse(s, sLen, 0, charLen-shift-1);
        reverse(s, sLen, charLen-shift, sLen-2);
        reverse(s, sLen, 0, sLen-2);
    }else
    {
        reverse(s, sLen, 0, -shift-1);
        reverse(s, sLen, -shift, sLen-2);
        reverse(s, sLen, 0, sLen-2);
    }
}


void test()
{
    char s[7] = "abcdef";
    printf("1:%s\n",s);
    
    shift(s, 7, -15);
    printf("2:%s\n",s);
}