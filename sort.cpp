几种排序方法
#include<iostream>
using namespace std;
//堆排序开始
void siftdown(vector<int>& nums,int i,int n)
{
    while((i*2+1<n &&nums[i]<nums[i*2+1] )||(i*2+2<n && nums[i]<nums[i*2+2]))
    {
        if(i*2+2<n && nums[i*2+2]>nums[i*2+1])
        {
            swap(nums[i],nums[i*2+2]);
            i = i*2+2;
        }
        else
        {
            swap(nums[i],nums[i*2+1]);
            i= i*2+1;
        }
    }
}
void heapsort(vector<int>& nums)
{
    int n = nums.size();
    for(int i = n/2-1;i>=0;i--)
    {
        siftdown(nums,i,n);
    }
    for(int i = n-1;i>=0;i--)
    {
        swap(nums[0],nums[i]);
        siftdown(nums,0,i);
    }
}
//堆排序结束
//快速排序开始
void quicksort(vector<int>& a,int start,int end)
{
	//cout << sizeof(a)<< endl;
	int first = start;
	int last = end;
	while (start != end)
	{
		while (a[end] >= a[first] && start != end) end--;
		while (a[start] <= a[first] && start != end) start++;
		swap(a[start],a[end]);
	}
	swap(a[first],a[end]);
	if(first<end-1) qs(a,first,end-1);
	if(last>end+1) qs(a,end+1,last);
}
//快速排序结束
//基数排序开始
void radixsort(vector<int>& nums)
{
    int n = nums.size();
    int maxvalue = *max_element(nums.begin(),nums.end());
    int base = 10;
    for(int radix =1;radix<=maxvalue;radix*=base)
    {
        vector<int> temp(n,0);
        vector<int> count(base+1,0);
        for(int i = 0;i<n;i++)
        {
            count[(nums[i]/radix)%base+1]++;
        }
        for(int i =1;i<=base;i++)
        {
            count[i]+=count[i-1];
        }
        for(int i = 0;i<n;i++)
        {
            temp[count[(nums[i]/radix)%base]++] = nums[i];
        }
        nums = temp;
    }
}
//基数排序结束

int main()
{
	int a[] = { 2,5,10,4,6,3,9,1,7,8 };
	int len = sizeof(a) / sizeof(int);
	quicksort(a,0,len-1);
	//heapsort(a);
	//radixsort(a);
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
