#include <iostream>
#include <string>
#include <algorithm>
#define DB 1005
#define DA 2*DB
using namespace std;


//9.1
void merge_a_b(int na,int nb,int a[],int b[]) {
	int pa=na-1,pb=nb-1,pf=na+nb;
	while(pa>=0 || pb>=0) {
		if(pb<0 || a[pa]>b[pb]) a[--pf]=a[pa--];
		else a[--pf]=b[pb--];
	}
	for(int i=0; i<na+nb; ++i) cout<<a[i]<<' ';
}
//9.2
bool cmp(string a,string b) {
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	return a<b;
}
//9.3
int find(int x,int n,int a[]) {
	int ls=0,ld=n-1,m;
	while(ls<=ld) {
		m=(ls+ld)/2;
		if(a[m]==x) return m;
		if(a[ls]<=a[m]){
			if(x>a[m]) ls=m+1;
			else if(x>=a[ls]) ld=m-1;
			else ls=m+1;
		}else if(x<a[m]) ld=m-1;
		else if(x<=a[ld]) ls=m+1;
		else ld=m-1;
	}
	return -1;
}

//9.4
/**
 * Quicksort because it doesn't use aditional memory
 * Depending on aditional memory we can use we split the file in k chunks and sort each in nlogn
 * after that we merge them one by one like in 9.1
 */

 //9.5
 int find(string x,int n,string v[]) {
 	int ls=0,ld=n-1,m;
 	while(ls<=ld) {
 		m=(ls+ld)/2;
 		if(v[m]=="") {
 			int cm=m;
 			for(;m>=ls && v[m]=="";--m);
 			if(m<ls) m=cm+1;
 			for(;m<=ld && v[m]=="";++m);
 			if(m>ld) return -1;
 		}
 		if(x==v[m]) return m;
 		if(x<v[m]) ld=m-1;
 		else ls=m+1;

 	}
 	return -1;
 }

 //9.6
 bool find_in_matrix(int x,int n,int m,int mt[555][555]) {
 	//we can do it better by finding two elements in the first row such that a[i]<x<a[i+1]
 	//and then binary search on column i and i+1
 	int i=0,j=m-1;
	while (i<n && j>=0) {
		if (mt[i][j]==x) return true;
		if (mt[i][j]>x) --j;
		else ++i;
	}
	return false;
 }

 //9.7
 //sort by one dimension and then compute maximum increasing sequence

int main() {
	// int v1[555]={1,3,5,7,9},v2[55]={2,4,6,8,999};
	// merge_a_b(5,5,v1,v2);
	// int n=9,v[]={10,11,12,1,2,3,4,5,6};
	// cout<<find(v[8],n,v);
}