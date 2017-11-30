//渣渣快排
#include<iostream>
using namespace std;
void qs(int a[],int start,int end)
{
	//cout << sizeof(a)<< endl;
	int first = start;
	int last = end;
	while (start != end)
	{
		while (a[end] >= a[first] && start != end) end--;
		while (a[start] <= a[first] && start != end) start++;
		int temp = a[start];
		a[start] = a[end];
		a[end] = temp;
	}
	int temp = a[first];
	a[first] = a[end];
	a[end] = temp;
	if(first<end-1) qs(a,first,end-1);
	if(last>end+1) qs(a,end+1,last);
}
int main()
{
	int a[] = { 2,5,10,4,6,3,9,1,7,8 };
	int len = sizeof(a) / sizeof(int);
	qs(a,0,len-1);
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
