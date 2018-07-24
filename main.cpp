
#include "paixu.h"
#include <iostream>


using namespace std;


int main()
{
    cout << "Hello World!" << endl;
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    xuanZe(a, 10);
    for(int i=0; i<10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n========================" << std::endl;

    int b[10] = {9,8,7,6,5,4,3,2,1,0};
//    int b[10] = {0,1,2,3,4,5,6,7,8,9};
    maoPao(b, 10);
    for(int i=0; i<10; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << "\n========================" << std::endl;

//    int c[10] = {0,1,2,3,4,5,6,7,8,9};
//    int c[10] = {9,8,7,6,5,4,3,2,1,0};
    int c[10] = {0,1,12,31,4,15,61,17,18,9};
    chaRu(c, 10);
    for(int i=0; i<10; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n========================" << std::endl;

    int d[10] = {0,1,12,31,4,15,61,17,18,9};
    xiEr1(d, 10);
    for(int i=0; i<10; i++) {
        std::cout << d[i] << " ";
    }
    std::cout << "\n========================" << std::endl;

    int e[10] = {0,1,12,31,4,15,61,17,18,9};
    xiEr2(e, 10);
    for(int i=0; i<10; i++) {
        std::cout << e[i] << " ";
    }
    std::cout << "\n========================" << std::endl;


    return 0;
}
