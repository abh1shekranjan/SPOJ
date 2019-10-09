#include <cstdio>
#include <algorithm>
using namespace std;

struct SegmentTreeNode {
	int prefixMaxSum, suffixMaxSum, maxSum, sum;
	
	void assignLeaf(int value) {
		prefixMaxSum = suffixMaxSum = maxSum = sum = value;
	}
	
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		sum = left.sum + right.sum;
		prefixMaxSum = max(left.prefixMaxSum, left.sum + right.prefixMaxSum);
		suffixMaxSum = max(right.suffixMaxSum, right.sum + left.suffixMaxSum);
		maxSum = max(prefixMaxSum, max(suffixMaxSum, max(left.maxSum, max(right.maxSum, left.suffixMaxSum + right.prefixMaxSum))));
	}
	
	int getValue() {
		return maxSum;
	}
};


class SegmentTree {
	SegmentTreeNode* nodes;
	int N;
	
public:
	SegmentTree(int arr[], int N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}
	
	~SegmentTree() {
		delete[] nodes;
	}
	
	int getValue(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
	
	
private:	
	void buildTree(int arr[], int stIndex, int lo, int hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
	
	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
		if (left == lo && right == hi)
			return nodes[stIndex];
			
		int mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);
			
		SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;
	}
	
	int getSegmentTreeSize(int N) {
		int size = 1;
		for (; size < N; size <<= 1);
		return size << 1;
	}
	

};

int main() {
	int N, i, A[50000], M, x, y;
	
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	SegmentTree st(A, N);
	
	scanf("%d", &M);
	for (i = 0; i < M; ++i) {
		scanf("%d %d", &x, &y);
		printf("%d\n", st.getValue(x-1, y-1));
	}	
	
	return 0;
}