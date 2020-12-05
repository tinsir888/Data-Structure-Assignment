#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x;
}
int a[maxn],tmp[maxn],cnt_cmp=0,cnt_swap=0;
void bubble_sort(int l,int r){
	for(int i=l;i<=r;i++){
		for(int j=l;j<=r-i;j++){
			cnt_cmp++;
			if(a[j]>a[j+1]){
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				cnt_swap++; 
			}
		}
	}
}
void show(){
	cout<<"使用冒泡排序的比较次数："<<cnt_cmp<<endl;
	cout<<"使用冒泡排序的交换次数："<<cnt_swap<<endl;
	cout<<"冒泡排序最终结果："<<endl; 
	for(int i=1;i<=10000;i++){
		cout<<a[i]<<' ';
	}
}
int main(){
	freopen("inputfile.txt","r",stdin);
	freopen("bubble_sort_res.txt","w",stdout);
	for(int i=1;i<=10000;i++){
		a[i]=read();
	}
	//使用快速排序 
	bubble_sort(1,10000);
	show();
	return 0;
}
