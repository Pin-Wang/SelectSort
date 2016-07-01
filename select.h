#ifndef Insert_h
#define Insert_h
#include<iostream>

typedef int EleType;
using namespace std;

class Select{
private:
public:
	//直接选择排序，不稳定的，时间复杂度均为O(n*n)
	void select_direct(EleType a[],int n);
	//堆排序，不是稳定的，时间复杂度是O(nlog2(n))
	void heap_sort(EleType a[],int n);
	//调整堆
	void heap_adjust(EleType a[],int size,int parent);
	//建立初始堆
	void heap_initial(EleType a[],int size);
	//交换数组元素
	void swap(EleType a[],int l1,int l2);
	//打印元素
	void print(EleType a[],int n );
};

//直接插入排序
void Select::select_direct(EleType a[],int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		//cout<<min<<endl;
		//将最小元素置换到相应位置上
		if(min!=i){
			EleType temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
}

//调整堆,大顶堆
void Select::heap_adjust(EleType a[],int size,int parent){
	//只调整非叶结点
	if(parent<=size/2){
		int max=parent;
		int lc=parent*2;
		int rc=parent*2+1;
		if(lc<=size&&a[lc]>a[max]){
			max=lc;
		}
		if(rc<=size&&a[rc]>a[max]){
			max=rc;
		}
		EleType temp=a[max];
		a[max]=a[parent];
		a[parent]=temp;
		heap_adjust(a,size,lc);
		heap_adjust(a,size,rc);
	}
}

//建立初始大顶堆
void Select::heap_initial(EleType a[],int size){
	for(int i=size/2;i>=1;i--){
		heap_adjust(a,size,i);
	}
}

//堆排序
void Select::heap_sort(EleType a[],int n){
	heap_initial(a,n);
	for(int i=n;i>0;i--){
		swap(a,1,i);
		heap_adjust(a,i-1,1);
	}
}

//交换数组元素位置
void Select::swap(EleType a[],int l1,int l2){
	EleType temp=a[l1];
	a[l1]=a[l2];
	a[l2]=temp;
}

//输出数组元素
void Select::print(EleType a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

#endif
