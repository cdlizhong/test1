//
//  ByteArray.cpp
//  test1
//
//  Created by lizhong on 15/12/29.
//  Copyright © 2015年 cdlizhong. All rights reserved.
//

#include "ByteArray.hpp"
#include <iostream>

#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)

//下标从0开始

int newByteArray(int len) // len 数组的长度
{
    int ret = (len + CHAR_BIT - 1)/CHAR_BIT;
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
//    a[charIndex] |= 0x80>>num;
    a[charIndex] |= 1<<num;
}

void clearByteAtIndex(char a[],int index)
{
    int num = index%CHAR_BIT;
    int charIndex = index/CHAR_BIT;
    
//    a[charIndex] &= 0x7F>>num;
    a[charIndex] &= ~1<<num;
}

int getByteByIndex(char a[],int index)
{
    int num = index%CHAR_BIT;
    int charIndex = index/CHAR_BIT;
    char e = a[charIndex];
    int ret = e & 1<<num;
    return ret == 0 ?0:1;
}

