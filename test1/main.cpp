//
//  main.cpp
//  test1
//
//  Created by cdlizhong on 15/12/8.
//  Copyright © 2015年 cdlizhong. All rights reserved.
//

#include <iostream>
#include <time.h>

#include "shift.hpp"
#include "sort.hpp"
#include "ByteArray.hpp"
#include "search.hpp"

using namespace std;

//#include <GLUT/GLUT.h>
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_POLYGON);
//    glVertex2f(-0.5, -0.5);
//    glVertex2f(-0.5, 0.5);
//    glVertex2f(0.5, 0.5);
//    glVertex2f(0.5, -0.5);
//    glEnd();
//    glFlush();
//}
//int main(int argc, char ** argv)
//{
//    glutInit(&argc, argv);
//    glutCreateWindow("Xcode Glut Demo");
//    glutDisplayFunc(display);
//    glutMainLoop();
//}

void assert(bool flag,char *str)
{
    if(flag == false)
        cout<<str<<endl;
}


int main(int argc, const char * argv[]) {
    
    printf("hello hello!\n");
//    
//    int ret[10];
//    randomCreateArray(ret, 0, 10, 10);

//    for (int i=1; i<=14; i++)
//    {
//        int ret = getByteByIndex(a, i);
//        cout<<ret<<" ";
//    }
//    cout<<endl;
//    int ret1 = getByte(a, 2);
//    initRandom();

    
    int len = 1000;
    int arr[len];
//
    createArrayRandom(arr,len, 1, 1000);
//    for (int i = 0; i<len; i++) {
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
//    insertSort(arr, len);
//    quickSort(arr, 0,len-1);
//    buildMaxHeap(arr, len-1);
//    heapSort(arr, len-1);
//    for (int i = 0; i<len; i++) {
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
//    int len = newByteArray(14);
//    char a[len];
//    initByteArray(a, len);
//    setByteAtIndex(a, 1);
//    setByteAtIndex(a, 5);
//    setByteAtIndex(a, 8);
//    setByteAtIndex(a, 9);
//    setByteAtIndex(a, 13);
//    clearByteAtIndex(a, 1);
//    clearByteAtIndex(a, 5);
//    setByteAtIndex(a, 12);
//    for (int i=0; i<14; i++)
//    {
//        int ret = getByteByIndex(a, i);
//        cout<<ret<<" ";
//    }
//    cout<<endl;
//    int a[10] = {31,-41,59,26,-53,58,97,-93,-23,84};
    clock_t start = clock();
//    int index = binarySearch(a, 10, 10);
//    insertSort(arr, len);
//        quickSort(arr, 0,len-1);
//        buildMaxHeap(arr, len-1);
//        heapSort(arr, len-1);
    int max = maxContinousSub_2(arr, 1000);
    clock_t end = clock();
    double duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("time %f \n",duration);
    for (int i = 0; i<len; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"max="<<max<<endl;
//
//
    
    

    return 0;
}




