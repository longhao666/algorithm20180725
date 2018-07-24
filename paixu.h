#ifndef PAIXU_H
#define PAIXU_H

#include <iostream>

// 交换数组元素
static void swap_m(int *arr, int i, int j) {
    int tp = arr[j];
    arr[j] = arr[i];
    arr[i] = tp;
}

// 选择排序
static void xuanZe(int *arr, int n) {
#if 0 // 错误
    int i,j;
    int index;
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(arr[i] < arr[j]) {
                index = j;
            }
        }
        int tp = arr[index];
        arr[index] = arr[i];
        arr[i] = tp;
    }
#elif 0 // 修改正确
    int i,j;
    int index;
    for(i=0; i<n-1; i++) {
        // 必须加这句话，不然排序不正确
        index = i;
        for(j=i+1; j<n; j++) {
            if(arr[index] < arr[j]) {
                index = j;
            }
        }
        swap_m(arr, i, index);
    }
#endif
    // 从大到小
#if 0 //正确
    int i,j;
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(arr[i] < arr[j]) {
                int tp = arr[j];
                arr[j] = arr[i];
                arr[i] = tp;
            }
        }
    }
#endif
    // 从大到小 优化方法
#if 1 //正确
    int i,j;
    for(i=0; i<n-1; i++) {
        int index = i;
        for(j=i+1; j<n; j++) {
            if(arr[index] < arr[j]) {
                index = j;
            }
        }
        //进行交换，如果index发生变化，则进行交换
        if(index != i) {
            swap_m(arr, i, index);
        }
    }
#endif
}

// 冒泡排序
static void maoPao(int *arr, int n) {
    //从大到小
#if 0 //正确
    int i,j;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            if(arr[j] < arr[j+1]) {
                int tp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tp;
            }
        }
    }
#endif
    //从小到大
#if 0 //正确
    int i,j;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap_m(arr, j, j+1);
            }
        }
    }
#endif

    // 从小到大 优化方法
#if 1 //正确
    int i,j;
    for(i=0; i<n-1; i++) {
        bool flag = true; // 设定一个标记，若为true，则表示此次循环没有进行交换，也就是待排序列已经有序，排序已然完成。
        for(j=0; j<n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap_m(arr, j, j+1);
                flag = false;
            }
        }
        if(flag == true) {
            std::cout << "order by" << std::endl;
            break;
        }
    }
#endif
}


// 插入排序
static void chaRu(int *arr, int n) {
    // 从小到大
#if 1
    int i,j;
    for(i=1; i<n; i++) {
        j = i;
        while(j > 0 && arr[j] < arr[j-1]) {
            swap_m(arr, j, j-1);
            j--;
        }
    }
#endif
}


/*
基本思想：
希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；
随着增量逐渐减少，每组包含的关键词越来越多，当增量减至1时，整个文件恰被分成一组，算法便终止。

简单插入排序很循规蹈矩，不管数组分布是怎么样的，依然一步一步的对元素进行比较，移动，插入，
比如[5,4,3,2,1,0]这种倒序序列，数组末端的0要回到首位置很是费劲，比较和移动元素均需n-1次。
而希尔排序在数组中采用跳跃式分组的策略，通过某个增量将数组元素划分为若干组，然后分组进行插入排序，
随后逐步缩小增量，继续按组进行插入排序操作，直至增量为1。希尔排序通过这种策略使得整个数组在
初始阶段达到从宏观上看基本有序，小的基本在前，大的基本在后。然后缩小增量，到增量为1时，
其实多数情况下只需微调即可，不会涉及过多的数据移动。

我们来看下希尔排序的基本步骤，在此我们选择增量gap=length/2，缩小增量继续以gap = gap/2的方式，
这种增量选择我们可以用一个序列来表示，{n/2,(n/2)/2...1}，称为增量序列。希尔排序的增量序列的选择
与证明是个数学难题，我们选择的这个增量序列是比较常用的，也是希尔建议的增量，称为希尔增量，
但其实这个增量序列不是最优的。此处我们做示例使用希尔增量。

代码实现：
在希尔排序的理解时，我们倾向于对于每一个分组，逐组进行处理，但在代码实现中，我们可以不用这么按部就班地处理完一组再调转回来处理下一组（这样还得加个for循环去处理分组）比如[5,4,3,2,1,0] ，首次增量设gap=length/2=3,则为3组[5,2] [4,1] [3,0]，实现时不用循环按组处理，我们可以从第gap个元素开始，逐个跨组处理。同时，在插入数据时，可以采用元素交换法寻找最终位置，也可以采用数组元素移动法寻觅。希尔排序的代码比较简单，如下：
*/
// 希尔排序
// 希尔排序 针对有序序列在插入时采用交换法
static void xiEr1(int *arr, int n) {
    //增量gap，并逐步缩小增量
    for(int gap=n/2;gap>0;gap/=2){
        //从第gap个元素，逐个对其所在组进行直接插入排序操作
        for(int i=gap;i<n;i++){
            int j = i;
            while(j-gap>=0 && arr[j]<arr[j-gap]){
                //插入排序采用交换法
                swap_m(arr,j,j-gap);
                j-=gap;
            }
        }
    }
}

// 希尔排序 针对有序序列在插入时采用移动法。
static void xiEr2(int *arr, int n) {
    //增量gap，并逐步缩小增量
    for(int gap=n/2;gap>0;gap/=2){
        //从第gap个元素，逐个对其所在组进行直接插入排序操作
        for(int i=gap;i<n;i++){
            int j = i;
            int temp = arr[j];
            if(arr[j]<arr[j-gap]){
                while(j-gap>=0 && temp<arr[j-gap]){
                    //移动法
                    arr[j] = arr[j-gap];
                    j-=gap;
                }
                arr[j] = temp;
            }
        }
    }
}

class paiXu
{
public:
    paiXu();
};

#endif // PAIXU_H
