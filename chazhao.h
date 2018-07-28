#ifndef CHAZHAO_H
#define CHAZHAO_H

#include <iostream>


namespace lh {
static void erFen() {

}

#if 0
// 方法一
static int BinSearch(SeqList *R，int n,KeyType K)
{
    //在有序表R[0..n-1]中进行二分查找，成功时返回结点的位置，失败时返回-1
    int low=0,high=n-1,mid;     //置当前查找区间上、下界的初值
    while(low<=high)
    {
        if(R[low].key==K)
            return low;
        if(R[high].key==k)
            return high;          //当前查找区间R[low..high]非空
        mid=low+((high-low)/2);
            /*使用(low+high)/2会有整数溢出的问题
            （问题会出现在当low+high的结果大于表达式结果类型所能表示的最大值时，
                这样，产生溢出后再/2是不会产生正确结果的，而low+((high-low)/2)
                不存在这个问题*/
        if(R[mid].key==K)
          return mid;             //查找成功返回
        if(R[mid].key<K)
          low=mid+1;              //继续在R[mid+1..high]中查找
        else
          high=mid-1;             //继续在R[low..mid-1]中查找
    }
    if(low>high) {
        return -1;//当low>high时表示所查找区间内没有结果，查找失败4
    }
}
#endif

// 第二种
static int bsearchWithoutRecursion(int array[],int low,int high,int target)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(array[mid]>target)
            high=mid-1;
        else if(array[mid]<target)
            low=mid+1;
        else
            return mid;
    }
    return-1;
}

// 第三种
static int binSearch(const int *Array,int start,int end,int key)
{
    int left,right;
    int mid;
    left=start;
    right=end;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(key==Array[mid])  return mid;
        else if(key<Array[mid]) right=mid-1;
        else if(key>Array[mid]) left=mid+1;

    }
    return -1;
}

// 递归
static int found(int *arr, int x, int y, int k)
{
    int m=x+(y-x)/2;
    if(x>y)//查找完毕没有找到答案，返回-1
        return -1;
    else
    {
        if(arr[m]==k)
            return m;//找到!返回位置.
        else if(arr[m]>k)
            return found(arr, x, m-1, k);//找左边
         else
            return found(arr, m+1, y, k);//找右边
    }
}

static void chaZhao() {
    int a[10] = {0,1,12,31,4,15,61,17,18,9};
    int k = 0;
    std::cin >> k;
    std::cout << binSearch(a, 0, 9, k) << std::endl;
    std::cout << "========================" << std::endl;

    std::cin >> k;
    std::cout << found(a, 0, 9, k) << std::endl;
    std::cout << "========================" << std::endl;

    std::cin >> k;
    std::cout << bsearchWithoutRecursion(a, 0, 9, k) << std::endl;
    std::cout << "========================" << std::endl;
}

} // end lh



#endif // CHAZHAO_H
