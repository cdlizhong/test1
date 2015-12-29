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




int main(int argc, const char * argv[]) {
    
    printf("hello hello!\n");
    
    int ret[10];
    randomCreateArray(ret, 0, 10, 10);

//    for (int i=1; i<=14; i++)
//    {
//        int ret = getByteByIndex(a, i);
//        cout<<ret<<" ";
//    }
//    cout<<endl;
//    int ret1 = getByte(a, 2);
//    initRandom();

    
//    int len = 10;
//    int arr[len];
//
//    createArrayRandom(arr,len, 1, 10);
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
    
    
    return 0;
}




