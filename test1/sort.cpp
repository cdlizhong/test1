//
//  sort.cpp
//  test1
//
//  Created by cdlizhong on 15/12/26.
//  Copyright © 2015年 cdlizhong. All rights reserved.
//

#include "sort.hpp"
#include "ByteArray.hpp"
using namespace std;


int random(int min,int max)
{
    int ret = min + rand()%(max-min+1);
    return ret;
}

void initRandom()
{
    srand((unsigned)time(NULL));
}

void createArrayRandom(int arr[],int len,int min,int max)
{
    for (int i = 0; i<len; i++) {
        int a = random(min, max);
        arr[i] = a;
    }
}

// 生成[min max)之间count个不同的随机顺序的随机整数
void randomCreateArray_1(int result[],int min,int max,int count)
{
    initRandom();
    const int n = max-min;
    const int k = count;
    int len = newByteArray(n);
    char a[len];
    initByteArray(a, len);
    int i = 0;
    while(i!=k)
    {
        int num = random(0, max-min-1);
        if(getByteByIndex(a, num) == 0)
        {
            setByteAtIndex(a, num);
            result[i] = num +  min;
            i++;
        }
    }
    for (int i=0; i<k; i++)
    {
        cout<<result[i]<<" ";
    }
}

void randomCreateArray(int result[],int min,int max,int count)
{
    initRandom();
    const int n = max-min;
    const int k = count;
    int a[n];
    for(int i = 0;i<n;i++)
    {
        a[i] = i;
    }
    for(int i=0;i<k;i++)
    {
        int index = random(i,n-1);
        int temp = a[index];
        a[index] = a[i];
        a[i] = temp;
        result[i] = temp;
    }
    
    for (int i=0; i<k; i++)
    {
        cout<<result[i]<<" ";
    }
}

void insertSort(int arr[],int arrLen)
{
    cout<<"INSERT-SORT"<<endl;
    for(int j = 1;j<arrLen;j++)
    {
        int ej = arr[j];
        for(int i = j-1;i>=0;i--)
        {
            if( arr[i] > ej )
            {
                arr[i+1] = arr[i];
                arr[i] = ej;
            }
        }
    }
}

void selectSort(int arr[],int arrLen)
{
    cout<<"SELECT-SORT"<<endl;
    for(int i = 0;i<arrLen;i++)
    {
        for (int j = i+1; j<arrLen; j++)
        {
            if(arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void merge(int arr[],int p,int q,int r)
{
    printf("merge p=%d q=%d r=%d \n",p,q,r);
    
    // p..q  q+1..r
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];
    int R[n2+1];
    for (int i = 0; i<n1; i++)
    {
        L[i] = arr[i+p];
    }
    for(int i = 0;i<n2;i++)
    {
        R[i] = arr[i+q+1];
    }
    
    L[n1] = 1000; //哨兵
    R[n2] = 1000; //哨兵
    int Li = 0;
    int Ri = 0;
    for(int i = p;i<=r;i++)
    {
        if(L[Li] < R[Ri])
        {
            arr[i] = L[Li];
            Li++;
        }else
        {
            arr[i] = R[Ri];
            Ri++;
        }
    }
    for (int i = 0; i<10; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

void mergeSort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        printf("mergeSort p=%d q=%d r=%d \n",p,q,r);
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr,p,q,r);
    }
}

int partition(int arr[],int p,int r)
{
    printf("partition p=%d r=%d \n",p,r);
    int x = arr[r];
    int i = p -1 ;
    for(int j = p;j<r;j++)
    {
        if(arr[j] < x)
        {
            int temp = arr[i+1];
            arr[i+1] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = x;
    arr[r] = temp;
    for (int i = p; i<=r; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<" i="<<i+1;
    cout<<endl;
    return i+1;
}


void quickSort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q = partition(arr,p,r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

// HEAP SORT
int PARENT(int i)
{
    return (i-1)/2;
}

int LEFT(int i)
{
    return 2*i+1;
}

int RIGHT(int i)
{
    return 2*i + 2;
}


void maxHeapify(int arr[],int i,int arrLen,int heapSize)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = -1;
    if( l <= heapSize && arr[i] < arr[l] )
    {
        largest = l;
    }else
    {
        largest = i;
    }
    if( r <= heapSize && arr[largest] < arr[r])
    {
        largest = r;
    }
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, largest, arrLen,heapSize);
    }
    
    
}


void buildMaxHeap(int arr[],int arrLen)
{
    int heapSize = arrLen;
    for(int i = arrLen/2;i>=0;i--)
    {
        maxHeapify(arr, i, arrLen,heapSize);
    }
}

void heapSort(int arr[],int arrLen)
{
    buildMaxHeap(arr, arrLen);
    for (int i = 0; i<arrLen+1; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int heapSize = arrLen;
    for(int i = arrLen;i>=1;i--)
    {
        heapSize--;
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, 0,  arrLen,heapSize);
    }
}