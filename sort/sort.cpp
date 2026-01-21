#include<iostream>
using namespace std;

//bubble sort function
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


//insertion sort function
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


//selection sort function 
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

//merge sort function
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
    int help=new int[right-left+1];
    int i=0;
    int p1=left;
    int p2=mid+1;
    while(p1<=mid && p2<=right)
    {
        help[i++]=arr[p1]<=arr[p2]?arrr[p1++]:arr[p2++];
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

//quick sort function
void quicksort(int arr[],int left,int right)    
{
    if(left<right)
    {
        swap(arr[left+rand()%(right-left+1)],arr[right]);//随机选取基准值
        int[] p=partition(arr,left,right);
        quicksort(arr,left,p[0]);//排序小于区域
        quicksort(arr,p[1]+1,right);//排序大于区域
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