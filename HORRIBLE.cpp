#include<iostream>
#include<algorithm>
int n;
int tree[4000001]={0};
int lazy[4000001]={0};
void build(int node,int start,int end){
    if (start == end)
    {
        tree[node]=arr[start];
    }
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

int sum(int node, int start, int end, int l, int right){
    if (l>r)
        return 0;
    if (l == start && r == end)
        return tree[node];
    int mid = ( start + end ) / 2;
    return sum(2*node, start, mid, l, min(r,mid)) + sum(2*node + 1, mid + 1, end, max(l,mid+1), r);
}


int updateRangeLazy(int node, int start, int end, int l, int r, int val){
    if (lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
         
    }
    
    if(start > end || start > r || end < l)
        return 0;
    if(start >=  l && end <= r){
        tree[node] += (end - start + 1) * val;
        if(start !=  end){
            lazy[node*2] += val;
            lazy[node*2+1] += val; 
        }
        return tree[node];
    }
    int mid = (start + end) / 2;
    updateRangeLazy(node*2, start, mid, l, r, val);
    updateRangeLazy(node*2+1, mid+1, end, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}