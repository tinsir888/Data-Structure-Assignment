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

void show(){
	cout<<"ʹ�ö���ıȽϴ�����"<<cnt_cmp<<endl;
	cout<<"ʹ�ö�����Ľ���������"<<cnt_swap<<endl;
	cout<<"���������ս����"<<endl; 
	for(int i=0;i<10000;i++){
		cout<<a[i]<<' ';
	}
}
void shift(int i,int len){
	int j=i<<1|1;
	while(j<len){
		if(j+1<len&&a[j]<a[j+1]){
			j++;
			cnt_cmp++;
		}
		if(a[i]>a[j]){
			break;
		}
		int tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
		cnt_swap++; 
		i=j;
		j=i<<1|1;
	}
}
void make_heap(int n){
	int i;
	for(i=n>>1-1;i>=0;i--)
		shift(i,n);
}
void heap_sort(int len){
	int i;
	make_heap(len);
	for(i=len-1;i>=0;i--){
		int tmp=a[i];
		a[i]=a[0];
		a[0]=tmp;
		cnt_swap++;
		shift(0,i);
	}
}
int main(){
	freopen("inputfile.txt","r",stdin);
	freopen("heap_sort_res.txt","w",stdout);
	for(int i=0;i<10000;i++){
		a[i]=read();
	}
	//ʹ�ÿ������� 
	heap_sort(10000);
	show();
	return 0;
}
