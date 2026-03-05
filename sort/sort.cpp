#include<bits/stdc++.h>
using namespace std;

//bubble sort function 冒泡排序
void bubbleSort(int arr[], int size) 
{
    bool swapped=false;
    for(int i=0;i<size-1;i++)
    {
        swapped=false;
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
                //swapping elements if they are in wrong order
                //swapped flag to true
            }
            if(!swapped)
            {
                break; 
                //if no two elements were swapped in inner loop, array is sorted 
            }
        }
    }
}


//insertion sort function插入排序
void insertionsort(int arr[],int size)
{
    //外层循环，遍历无序元素
    for(int i=1;i<size;i++)
    {
        //拿出无序序列的第一个元素
        int temp=arr[i];
        //设置内层循环起始值=有序序列的最后一个元素
        int j=i-1;
        
        //内层循环，遍历有序元素
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j]; //有序元素后移
            j--;
        }
        arr[j+1]=temp; //将无序元素插入到正确位置
    }
}
//趋于有序时，插入排序优于冒泡排序，因为插入排序减少了不必要的比较和交换操作.


//selection sort function 选择排序
//选择的是位置，而不是数据
void selectionsort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int minpos=i;//当前趟数最小值初始位置
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[minpos])
            {
                minpos=j;
            }
        }
        if(minpos!=i)
        {
            swap(arr[minpos],arr[i]);
        }
    }
}

//merge sort function归并排序
void mergesort(int arr[],int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int mid=left+((right-left)>>1);
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
void merge(int arr[],int left,int mid,int right)
{
    int* help=new int[right-left+1];
    int i=0;
    int p1=left;
    int p2=mid+1;
    while(p1<=mid && p2<=right)
    {
        help[i++]=arr[p1]<=arr[p2]?arr[p1++]:arr[p2++];
    }
    while(p1<=mid)
    {
        help[i++]=arr[p1++];
    }
    while(p2<=right)
    {
        help[i++]=arr[p2++];        
    }
    for(int i=0;i<right-left+1;i++)
    {
        arr[left++]=help[i];
    }

}

//quick sort function快速排序
void quicksort(int arr[],int left,int right)    
{
    if(left<right)
    {
        swap(arr[left+rand()%(right-left+1)],arr[right]);//随机选取基准值
        pair<int,int> p=partition(arr,left,right);
        quicksort(arr,left,p.first);//排序小于区域
        quicksort(arr,p.second+1,right);//排序大于区域
    }
}
pair<int,int> partition (int arr[],int left,int right)
{
    int less=left-1;//小于区域右边界，这个边界是开区间
    int more=right;//大于区域左边界，这个边界是闭区间
    int pivot=arr[right];//基准值
    while(left<more)//left表示当前数字的位置
    {
        if(arr[left]<pivot)
        swap(arr[++less],arr[left++]);
        //一开始++less和left++可能相等（小于的数刚好在小于区域的右边），这时候就是自己和自己交换
        //到后面出现了大于或者等于的时候left++会跳过这个位置
        
        else if(arr[left]>pivot)
        swap(arr[--more],arr[left]);
        //这里没有left++，因为交换过来的数还没有被比较
        
        else
        left++;
    }
    swap(arr[more],arr[right]);
    //把基准值放到等于区域内，即最后一个值和大于区域第一个数交换
    //此时less和more都是小于和大于区域的开区间边界
    return make_pair(less,more);
}
//荷兰国旗问题




//堆排序
//1.插入大根堆的，往上过程叫做heapinsert
//某个数处于index的位置，往上继续移动
void heapInsert(int arr[],int index)
{
    while(arr[index]>arr[(index-1)/2])
    {
        swap(arr[index],(arr[(index-1)/2]));
        index=(index-1)/2;
    }
}
//2.某个数处于index的位置，是否需要往下移动，从一个位置往下的过程叫做heapify
void heapify(int arr[],int index,int heapsize)
{
    //heapsize是当前数组的长度
    int left=index*2+1;//左孩子下表
    while(left<heapsize)//下方还有孩子的时候
    {
        //两个孩子谁的值大，把下标给largest
        int largest=left+1 < heapsize && arr[left+1]>arr[left] ? left+1 : left;
        //父和孩子谁的值大，把下标给largest
        largest=arr[largest]>arr[index]?largest:index;
        if(largest==index)
        {
            break;
        }
        swap(arr[largest],arr[index]);
        index=largest;
        left=index*2+1;
    }
}

//3.删除大根堆头部父节点
//最后一个数和父节点交换，heapsize-1，此时最后一位已经无效，对现在的父节点完成heapify操作

//4.堆替换
//某个位置数与外来数字做替换，二者先比较，视情况然后做heapify或者heapinsert过程


//堆排序时间复杂度O(NlogN) 空间复杂度O（1）
void heapSort(int arr[],int size)//size是数组的长度
{
    if(arr==NULL)
    {
        return;
    }
    for(int i=0;i<size;i++)//O(N),生成了一个大根堆
    {
        heapInsert(arr,i);//O(logN)
    }
    int heapsize=size;
    swap(arr[0],--heapsize);//将最大值放在最后面，接下来就是对数组的真正排序
    while(heapsize>0)//O(N)
    {
        heapify(arr,0,heapsize);//O(logN)
        swap(arr[0],--heapsize);//O(1)
    }
}
