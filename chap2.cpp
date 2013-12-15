#include <iostream>
using namespace std;

struct node {
	int key;
	node *next;
	node(int k,node *n) {
		key=k;
		next=n;
	}
} *beg;

void insert(int key) {
	node *p;
	for(p=beg;p->next; p=p->next);
	node *q=new node(key,NULL);
	p->next=q;
}

void print_list(node *head) {
	for(;head;head=head->next) cout<<head->key<<' ';
	cout<<'\n';
}

// 2.1
void delete_duplicates(node *head) {
	for(node *prev=head;prev->next!=NULL;) {
		int ok=1;
		for(node *i=head; i!=prev->next; i=i->next) if(i->key==prev->next->key) {
			ok=0;
			prev->next=prev->next->next;
			break;
		}
		if(ok) prev=prev->next;
	}
}

//2.2
node *nth_to_last(node *head,int n) {
	node *p1=head,*p2=head;
	for(int i=1; i<n; ++i) {
		p2=p2->next;
		if(p2==NULL) return p2;
	}
	for(;p2->next!=NULL;p1=p1->next,p2=p2->next);
	return p1;
}

//2.3
void delete_node(node *p) {
	if(p->next!=NULL) {
		node *q=p;
		p->key=p->next->key;
		p->next=p->next->next;
		delete q;
	}else delete p;
}

//2.4
node *add_lists(node *a,node *b) {
	node *head=NULL,*tail=NULL;
	int t=0;
	node *p;
	for(;a!=NULL || b!=NULL || t;) {
		p=new node(t,NULL);
		if(a!=NULL) {
			p->key+=a->key;
			a=a->next;
		}
		if(b!=NULL) {
			p->key+=b->key;
			b=b->next;
		}
		t=p->key/10;
		p->key%=10;
		if(head==NULL) head=p;
		if(tail!=NULL) tail->next=p;
		tail=p;
	}
	return head;
}

void test_add_lists() {
	node *p=new node(7,NULL);
	node *q=new node(5,p);
	node *r=new node(6,q);
	node *a=new node(6,NULL);
	node *b=new node(5,a);
	node *c=new node(4,b);
	print_list(add_lists(r,c));
}

//2.5
node* start_loop(node *head) {
	node *p=head,*q=head;
	do{
		p=p->next;
		q=q->next->next;
	}while(p!=q);
	p=head;
	for(;p!=q;p=p->next,q=q->next);
	return p;
}


int main() {
	beg=new node(4,NULL);
	insert(3);
	insert(4);
	insert(9);
	insert(9);
	insert(5);
	insert(9);
	// delete_duplicates(beg);
	// cout<<nth_to_last(beg,5)->key;
	// delete_node(beg);
	//test_add_lists();
	// print_list(beg);
}