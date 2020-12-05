#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x;
}
int a[maxn],cnt_cmp=0,cnt_swap=0;
void quick_sort(int l,int r){
	if(l<r){
		int i=l,j=r,x=a[l];
		while(i<j){
			while(i<j&&a[j]>=x){
				j--;
				cnt_cmp++;
			}
			if(i<j){
				a[i++]=a[j];
				cnt_swap++;
			}
			while(i<j&&a[i]<x){
				i++;
				cnt_cmp++;
			}
			if(i<j){
				a[j--]=a[i];
				cnt_swap++;
			}
		}
		a[i]=x;
		quick_sort(l,i-1);
		quick_sort(i+1,r);
	}
}
void show(){
	cout<<"ʹ�ÿ�������ıȽϴ�����"<<cnt_cmp<<endl;
	cout<<"ʹ�ÿ�������Ľ���������"<<cnt_swap<<endl;
	cout<<"�����������ս����"<<endl; 
	for(int i=1;i<=10000;i++){
		cout<<a[i]<<' ';
	}
}
int main(){
	freopen("inputfile.txt","r",stdin);
	freopen("quick_sort_res.txt","w",stdout);
	for(int i=1;i<=10000;i++){
		a[i]=read();
	}
	//ʹ�ÿ������� 
	quick_sort(1,10000);
	show();
	return 0;
}
