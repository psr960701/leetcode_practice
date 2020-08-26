#include <iostream>
using namespace std;
void Grial(int a[],int x,int y)
{
	if(x>=y)return ;
	int i=x;
	int j=y;
	int temp;
	int key=a[(i+j)/2];
	while(i<j)
	{
		while(a[i]<key)i++;//找到第一个比key大的数
		while(a[j]>key)j--;//找到第一个比key小的数
		if(i<=j)
		{	
			temp=a[i];a[i]=a[j];a[j]=temp;
			i++;
			j--;
		}
	}
//当i<j时，把比key小的与比key大的交换，直到i>j时，确定了中值，小于等于j的数组划分为左边较小的组，大于等于i的划分为右边较大的组,
//将数组分成了2部分，再分别递归比较.最后当x<y时跳出递归.
	Grial(a,x,j);
	Grial(a,i,y);
}
int main()
{
	int a[]={7,8,9,5,1,2,3};
	Grial(a,0,6);
	for(int i=0;i<7;i++)
	{
		cout<<a[i]<<"  ";
	}
	cout<<endl;
    getchar();
	return 0;
}
