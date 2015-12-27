//
//  sort.hpp
//  test1
//
//  Created by cdlizhong on 15/12/26.
//  Copyright © 2015年 cdlizhong. All rights reserved.
//

#ifndef sort_hpp
#define sort_hpp

#include <stdio.h>
#include <iostream>
#include <time.h>

int random(int min,int max);
void initRandom();


void createArrayRandom(int arr[],int len,int min,int max);

void insertSort(int arr[],int arrLen);

void selectSort(int arr[],int arrLen);

void merge(int arr[],int p,int q,int r);
void mergeSort(int arr[],int p,int r);

// quicksort
int partition(int arr[],int p,int r);
void quickSort(int arr[],int p,int r);

// heapsort
int PARENT(int i);
int LEFT(int i);
int RIGHT(int i);
void maxHeapify(int arr[],int i,int arrLen,int heapSize);
void buildMaxHeap(int arr[],int arrLen);
void heapSort(int arr[],int arrLen);


#endif /* sort_hpp */
