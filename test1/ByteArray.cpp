//
//  ByteArray.cpp
//  test1
//
//  Created by lizhong on 15/12/29.
//  Copyright © 2015年 cdlizhong. All rights reserved.
//

#include "ByteArray.hpp"
#include <iostream>

//下标从0开始

int newByteArray(int len) // len 数组的长度
{
    int ret = (len -1)/CHAR_BIT + 1;
    return ret;
}

void initByteArray(char a[],int len)
{
    for (int i = 0; i<len; i++) {
        a[i] = 0x00;
    }
}

void setByteAtIndex(char a[],int index)
{
    int num = index%CHAR_BIT;
    int charIndex = index/CHAR_BIT;
    a[charIndex] |= 0x80>>num;
}

void clearByteAtIndex(char a[],int index)
{
    int num = index%CHAR_BIT;
    int charIndex = index/CHAR_BIT;
    
    a[charIndex] &= 0x7F>>num;
}

int getByteByIndex(char a[],int index)
{
    int num = index%CHAR_BIT;
    int charIndex = index/CHAR_BIT;
    char e = a[charIndex];
    int ret = e & 0x80>>num;
    return ret == 0 ?0:1;
}

