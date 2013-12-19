#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

typedef vector<int>::iterator it;

vector<int> gr[55];
bitset<55> viz;
int maxd=-1,mind=(1<<30);

void dfs(int s,int f,int d) {
	maxd=max(maxd,d);
	mind=min(mind,d);
	for(it i=gr[s].begin();i!=gr[s].end(); ++i) if(*i!=f)
		dfs(*i,s,d+1);
}

void dfs(int s) {
	viz[s]=1;
	for(it i=gr[s].begin();i!=gr[s].end(); ++i) if(!viz[*i])
		dfs(*i);
}

//4.1
bool is_balanced() {
	dfs(1,0,0);
	return maxd-mind<2;
}

//4.2
bool is_path(int a,int b) {
	dfs(a);
	return viz[b]!=0;
}


struct bst
{
	int key;
	bst *l,*r,*f;
};

//4.3
int arr[555];
bst* create_bst(int a,int b) {
	if(a>b) return NULL;
	bst *p=new bst;
	int m=(a+b)>>1;
	p->l=create_bst(a,m-1);
	p->r=create_bst(m+1,b);
	return p;
}

//4.4
void make_dlist(bst *root) {
	vector<vector<bst*> >rez;
	vector<bst*> cur;
	for(;cur.size();) {
		vector<bst*> nxt;
		for(int i=0; i<cur.size(); ++i) {
			if(cur[i]->l!=NULL) nxt.push_back(cur[i]->l);
			if(cur[i]->r!=NULL) nxt.push_back(cur[i]->r);
		}
		rez.push_back(cur);
		cur=nxt;
	}
}
//4.5
bst* nxt(bst *node) {
	bst *p=node->f;
	if(node->r!=NULL) {
		node=node->r;
		while(node->l!=NULL) node=node->l;
		return node;
	}
	while(p!=NULL) {
		if(p->l==node) return p;
		p=p->f;
		node=node->f;
	}
	return p;
}

//4.6
int nrn(bst *root,bst *p,bst *q) {
	int r=0;
	if(root->l!=NULL) r+=nrn(root->l,p,q);
	if(root->r!=NULL) r+=nrn(root->r,p,q);
	if(root==p || root==q) ++r;
	return r;
}

bst* lca(bst *root,bst *p,bst *q) {
	if(root==p || root==q) return root;
	if(root->l!=NULL) {
		int cnt=nrn(root->l,p,q);
		if(cnt==1) return root;
		if(cnt==2) return lca(root->l,p,q);
	}
	return lca(root->r,p,q);
}

//4.7
bool tree_match(bst *t1, bst *t2) {
	if(t1!=t2) return false;
	return tree_match(t1->l,t2->l) && tree_match(t1->r,t2->r);
}

bool is_subtree(bst *t1,bst *t2) {
	if(tree_match(t1,t2)) return true;
	bool ok=false;
	if(t1->l!=NULL) ok|=is_subtree(t1->l,t2);
	if(t1->r!=NULL) ok|=is_subtree(t1->r,t2);
	return ok;
}

//4.8
int target;
vector<int> st;
vector<int> sum_lev[5555];
#define NORM 100
void find_sums(bst *s,int sc) {
	if(sum_lev[0].empty()) sum_lev[0].push_back(0);
	sc+=s->key;
	st.push_back(s->key);
	sum_lev[sc+NORM].push_back(st.size()+1);

	int tfind=target-sc;
	for(it i=sum_lev[tfind+NORM].begin(); i!=sum_lev[tfind+NORM].end(); ++i) {
		for(int j=*i; j<st.size(); ++j) cout<<st[j]<<' ';
		cout<<'\n';
	}

	if(s->l!=NULL) find_sums(s->l,sc);
	if(s->r!=NULL) find_sums(s->r,sc);
	st.pop_back();
}

int main() {

}