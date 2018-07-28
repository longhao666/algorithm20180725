#ifndef CHAZHAO_H
#define CHAZHAO_H

#include <iostream>


namespace lh {
static void erFen() {

}

#if 0
// ����һ
static int BinSearch(SeqList *R��int n,KeyType K)
{
    //�������R[0..n-1]�н��ж��ֲ��ң��ɹ�ʱ���ؽ���λ�ã�ʧ��ʱ����-1
    int low=0,high=n-1,mid;     //�õ�ǰ���������ϡ��½�ĳ�ֵ
    while(low<=high)
    {
        if(R[low].key==K)
            return low;
        if(R[high].key==k)
            return high;          //��ǰ��������R[low..high]�ǿ�
        mid=low+((high-low)/2);
            /*ʹ��(low+high)/2�����������������
            �����������ڵ�low+high�Ľ�����ڱ��ʽ����������ܱ�ʾ�����ֵʱ��
                �����������������/2�ǲ��������ȷ����ģ���low+((high-low)/2)
                �������������*/
        if(R[mid].key==K)
          return mid;             //���ҳɹ�����
        if(R[mid].key<K)
          low=mid+1;              //������R[mid+1..high]�в���
        else
          high=mid-1;             //������R[low..mid-1]�в���
    }
    if(low>high) {
        return -1;//��low>highʱ��ʾ������������û�н��������ʧ��4
    }
}
#endif

// �ڶ���
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

// ������
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

// �ݹ�
static int found(int *arr, int x, int y, int k)
{
    int m=x+(y-x)/2;
    if(x>y)//�������û���ҵ��𰸣�����-1
        return -1;
    else
    {
        if(arr[m]==k)
            return m;//�ҵ�!����λ��.
        else if(arr[m]>k)
            return found(arr, x, m-1, k);//�����
         else
            return found(arr, m+1, y, k);//���ұ�
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
