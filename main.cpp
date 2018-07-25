
#include "paixu.h"
#include "chazhao.h"
#include <iostream>


using namespace std;

void fun(char str[100]) {

    std::cout << sizeof(int *) << std::endl;
    std::cout << sizeof(char *) << std::endl;
    std::cout << sizeof(str) << std::endl;

    char s[100];
    std::cout << sizeof(s) << std::endl;

}


int main()
{
    cout << "Hello World!" << endl;

    fun("fffff");

    lh::paiXu();

    lh::chaZhao();

    return 0;
}
