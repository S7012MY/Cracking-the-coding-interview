#include <iostream>
#include <cstring>
using namespace std;

struct node{
  int key;
  node *next;
  node(int k,node *n) {
    key=k; next=n;
  }
};

struct stack {
  node *top;
  stack() {
    top=NULL;
  }

  bool is_empty() {
    return top==NULL;
  }

  void push(int k) {
    top=new node(k,top);
  }
  int pop() {
    node *q=top;
    int r=q->key;
    top=top->next;
    delete q;
    return r;
  }
  int get_top() {
    return top->key;
  }
};

struct queue {
  node *head,*tail;
  queue() {
    head=tail=NULL;
  }
  void push(int k) {
    node *q=new node(k,NULL);
    if(tail==NULL) tail=head=q;
    else {
      tail->next=q;
      tail=q;
    }
  }
  int pop() {
    node *p=head;
    int r=p->key;
    //cout<<r<<'\n';
    head=head->next;
    delete p;
    return r;
  }
};

//3.1
struct three_stacks {
  int arr[3001],ta,tb,tc,size_mid;
  three_stacks() {
    ta=0,tb=3000,tc=1500,size_mid=1;
  }
  void push(int idx,int vl) {
    if(idx==0) arr[ta++]=vl;
    else if(idx==1) arr[tb--]=vl;
    else {
      arr[tc]=vl;
      if(size_mid%2) tc+=size_mid;
      else tc-=size_mid;
      ++size_mid;
    }
  }
  int pop(int idx) {
    if(idx==0) return arr[--ta];
    if(idx==1) return arr[++tb];
    else {
      --size_mid;
      if(size_mid%2) tc-=size_mid;
      else tc+=size_mid;
      return arr[tc];
    }
  }
};

//3.2
struct stack_min {
  stack *s,*ms;
  stack_min(){
    s=new stack; ms=new stack;
  }
  void push(int k) {
    if(s->top==NULL) {
      s->push(k);
      ms->push(k);
    }
    else {
      s->push(k);
      ms->push(min(ms->get_top(),k));
    }
  }
  void pop() {
    s->pop();
    ms->pop();
  }
};

//3.3
struct stack_stacks {
  int size_limit;
  int arr[555][555],sz[555],ssz;
  stack_stacks(int limit) {
    size_limit=limit;
    ssz=0;
    memset(sz,0,sizeof(sz));
  }
  void push(int k) {
    if(sz[ssz]==size_limit) ++ssz;
    arr[ssz][sz[ssz]++]=k;
  }
  int pop() {
    --sz[ssz];
    if(!sz[ssz]) --ssz;
    return arr[ssz][sz[ssz]-1];
  }
  int get_top() {
    return arr[ssz][sz[ssz]-1];
  }
  int pop_at(int ind) {
    return arr[ind][--sz[ind]];
  }
};

//3.4
//Hanoi
//http://www.proofwiki.org/wiki/Tower_of_Hanoi
stack *s[3];

void move(int n,int source,int dest,int aux) {
  if(n==0) return;
  move(n-1,source,aux,dest);
  s[dest]->push(s[source]->get_top());
  s[source]->pop();
  cout<<n<<' '<<source<<' '<<dest<<'\n';
  move(n-1,aux,dest,source);
}

void hanoi(int n) {
  for(int i=0; i<3; ++i) s[i]=new stack;
  for(int i=n; i; --i) s[0]->push(i);
  move(n,0,2,1);
}

//3.5
struct my_queue {
  stack *s1,*s2;
  my_queue() {
    s1=new stack;
    s2=new stack;
  }

  void push(int k) {
    s1->push(k);
  }

  int pop() {
    if(s2->is_empty()) {
      for(;!s1->is_empty();s2->push(s1->get_top()),s1->pop());
    }
    int r=s2->get_top();
    s2->pop();
    return r;
  }
};

//3.6
void sort_stack() {
  stack *s,*aux;
  s=new stack; aux=new stack;
  s->push(2);
  s->push(1);
  s->push(4);
  s->push(5);
  s->push(3);
  while(!s->is_empty()) {
    int q=s->pop();
    for(;!aux->is_empty() && aux->get_top()>q; s->push(aux->pop()));
    aux->push(q);
  }
  while(!aux->is_empty()) cout<<aux->pop()<<' ';
}

int main() {
  stack *s=new stack();
  queue *q=new queue();
  //test the stack
//  s->push(3);
//  s->pop();
//  s->push(4);
//  cout<<s->get_top();
// test the queue
//  q->push(3);
//  q->push(5);
//  q->push(4);
//  //cout<<q->head->key<<'\n';
//  cout<<q->pop()<<' '<<q->pop();
//  three_stacks *ts=new three_stacks;
//  ts->push(2,3); ts->push(2,4); ts->push(2,5);
//  cout<<ts->tc<<'\n';
//  cout<<ts->pop(2)<<' ';
//  cout<<ts->pop(2)<<' ';
//  cout<<ts->pop(2)<<' ';
//  hanoi(4);
//  my_queue *mq=new my_queue();
//  for(int i=1; i<5; ++i) mq->push(i);
//  cout<<mq->pop()<<' ';
//  cout<<mq->pop()<<' ';
//  cout<<mq->pop()<<' ';
//  sort_stack();
}
