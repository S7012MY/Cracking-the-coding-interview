#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

//ex 1.1
bool allUnique(string s) {
  int fr=0;
  for(int i=0; i<s.size(); ++i) {
    if(fr&(1<<(s[i]-'a'))) return false;
    fr|=(1<<(s[i]-'a'));
  }
  return true;
}

//ex 1.2
void reverse(char s[]) {
  int lg=strlen(s);
  for(int i=0,j=lg-1; i<j; ++i,--j) swap(s[i],s[j]);
  cout<<s;
}

//ex 1.3
void removeDuplicates(char s[]) {
  int lg=strlen(s),sz=0,fr=0;
  for(int i=0; i<lg; ++i) {
    if((fr&(1<<(s[i]-'a')))==0) {
      s[sz++]=s[i];
    }
    fr|=(1<<(s[i]-'a'));
  }
  s[sz]=0;
  cout<<s;
}

//1.4
bool isAnagram(string s,string d) {
  int fr[26];
  memset(fr,0,sizeof(fr));
  for(int i=0; i<s.size(); ++i) ++fr[s[i]-'a'];
  for(int i=0; i<d.size(); ++i) --fr[d[i]-'a'];
  for(char c='a'; c<='z'; ++c) if(fr[c-'a']) return false;
  return true;
}
//1.5
void repl(char s[100]) {
  //replaces all spaces with '%20'
  int lg=strlen(s),nspaces=0;
  for(int i=0; i<lg; ++i) if(s[i]==' ') ++nspaces;
  int finlg=lg+2*nspaces;
  s[finlg]=0;
  for(int i=lg-1; i>=0; --i)
    if(s[i]==' ') {
      s[--finlg]='0';
      s[--finlg]='2';
      s[--finlg]='%';
    }else s[--finlg]=s[i];
  cout<<s;
}

//1.6
void rotate() {
  int n=3,mt[10][10];
  for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) mt[i][j]=(i-1)*n+j;
  for(int row=1; row<=n/2; ++row) {
    for(int j=row; j<n-row+1; ++j) {
      int next=mt[row][j];
      for(int x=row,y=j,i=1; i<=4; ++i) {
        int nx=y,ny=n-x+1;
        swap(next,mt[nx][ny]);
        x=nx; y=ny;
      }
    }
  }
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) printf("%2d ",mt[i][j]);
    printf("\n");
  }
}

//1.7
void  setZero(int n,int m,int mt[105][105]) {
  int l[105],c[105];
  memset(l,0,sizeof(l)); memset(c,0,sizeof(c));
  for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(!mt[i][j]) l[i]=c[j]=1;
  for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(l[i] || c[j]) mt[i][j]=0;
}

//1.8
bool isRotation(string a,string b){
  a.append(a);
  if(a.find(b)!=string::npos) return true;
  return false;
}

int main() {
  //cout<<allUnique("abcdefz");
  //cout<<allUnique("abcdefghizz");
  //char c[]="abcd";
  //reverse(c+1);
  //reverse(c);
  //char t1[]="abc";
//  char t2[]="aaaabc";
//  char t3[]="abab";
//  char t4[]="";
//  removeDuplicates(t4);
  //cout<<isAnagram("abc","bbc");
  //char t1[]="anaaremere ";
  //repl(t1);
  //rotate();
}
