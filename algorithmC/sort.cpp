#include<stdio.h>
#include<stdlib.h>
//快速排序要定义全局变量
const int n = 5;
int a[n];


// 桶排序算法
void bucketSort(){
	// 分数0-10，输入5个数字，然后使用桶排序，按顺序从小到大打印数字
	const int arrayNum = 11;
	int a[arrayNum];
	//初始化
	for(int i=0;i<arrayNum-1;i++){
		a[i] = 0;
	}
	//输入数据
	int num = 5;
	for(int i=0;i<num;i++){
		int t;
		printf("请输入第%d个数字:",i+1);
		scanf_s("%d",&t);
		a[t] ++;
	}
	//输出数据
	printf("排序后的顺序是:");
	/*for(int i=arrayNum;i>-1;i--){*/
	for (int i = 0; i < arrayNum; i++){
		for(int j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
}
//冒泡排序
void bubbleSort()
{
	//还是输入五个数字进行冒泡排序,从大到小
	const int arrayNum = 5;
	int a[arrayNum];
	for(int i=0;i<arrayNum;i++){
		printf("请输入第%d个数字:",i+1);
		scanf_s("%d",a+i);
	}
	//开始排序
	for(int i=0;i<arrayNum-1;i++){
		//arrayNum个数需要arrayNum-1次才能排序完
		for(int j=0;j<arrayNum-i-1;j++){
			if(a[j]<a[j+1]){
				//交换
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	//输出
	for(int i=0;i<arrayNum;i++){
		printf("%d\n",a[i]);	
	}
}
//快速排序(需要复习)
void quickSort(int left, int right){
	//开始快速排序
	//初始化哨兵
	if(left>right)
		return;//表示只有一个数值了
	int i=left;
	int j=right;
	//初始化基准数字
	int tempt = a[left];
	while (i!=j)
	{
		//先让右边的先跑,如果左边先跑的话就会在一个比基准数更大的地方相遇，导致后面基准数与该数字换位置的时候出错
		while(a[j]>=tempt&&i<j){
			j--;
		}
		while(a[i]<=tempt&&i<j){
			i++;
		}
		//交换位置
		if(i<j){
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//当i与j相遇的时候将基准数归位
	a[left] = a[i];
	a[i] = tempt;
	quickSort(left,i-1);//处理左边
	quickSort(i+1,right);//处理右边
}


int main(){
	//bucketSort();
	//bubbleSort();
	//快速排序
	for(int i=0;i<n;i++){
		printf("请输入第%d个数:",i+1);
		scanf_s("%d",a+i);
	}
	quickSort(0,n-1);
	//输出
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);	
	}
	system("pause");
}