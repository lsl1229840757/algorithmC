#include<stdio.h>
#include<stdlib.h>
//��������Ҫ����ȫ�ֱ���
const int n = 5;
int a[n];


// Ͱ�����㷨
void bucketSort(){
	// ����0-10������5�����֣�Ȼ��ʹ��Ͱ���򣬰�˳���С�����ӡ����
	const int arrayNum = 11;
	int a[arrayNum];
	//��ʼ��
	for(int i=0;i<arrayNum-1;i++){
		a[i] = 0;
	}
	//��������
	int num = 5;
	for(int i=0;i<num;i++){
		int t;
		printf("�������%d������:",i+1);
		scanf_s("%d",&t);
		a[t] ++;
	}
	//�������
	printf("������˳����:");
	/*for(int i=arrayNum;i>-1;i--){*/
	for (int i = 0; i < arrayNum; i++){
		for(int j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
}
//ð������
void bubbleSort()
{
	//��������������ֽ���ð������,�Ӵ�С
	const int arrayNum = 5;
	int a[arrayNum];
	for(int i=0;i<arrayNum;i++){
		printf("�������%d������:",i+1);
		scanf_s("%d",a+i);
	}
	//��ʼ����
	for(int i=0;i<arrayNum-1;i++){
		//arrayNum������ҪarrayNum-1�β���������
		for(int j=0;j<arrayNum-i-1;j++){
			if(a[j]<a[j+1]){
				//����
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	//���
	for(int i=0;i<arrayNum;i++){
		printf("%d\n",a[i]);	
	}
}
//��������(��Ҫ��ϰ)
void quickSort(int left, int right){
	//��ʼ��������
	//��ʼ���ڱ�
	if(left>right)
		return;//��ʾֻ��һ����ֵ��
	int i=left;
	int j=right;
	//��ʼ����׼����
	int tempt = a[left];
	while (i!=j)
	{
		//�����ұߵ�����,���������ܵĻ��ͻ���һ���Ȼ�׼������ĵط����������º����׼��������ֻ�λ�õ�ʱ�����
		while(a[j]>=tempt&&i<j){
			j--;
		}
		while(a[i]<=tempt&&i<j){
			i++;
		}
		//����λ��
		if(i<j){
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//��i��j������ʱ�򽫻�׼����λ
	a[left] = a[i];
	a[i] = tempt;
	quickSort(left,i-1);//�������
	quickSort(i+1,right);//�����ұ�
}


int main(){
	//bucketSort();
	//bubbleSort();
	//��������
	for(int i=0;i<n;i++){
		printf("�������%d����:",i+1);
		scanf_s("%d",a+i);
	}
	quickSort(0,n-1);
	//���
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);	
	}
	system("pause");
}