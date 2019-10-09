/*
In this Problem we make a segment tree and then query using that constructed segment tree.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

struct SegmentTreeNode {

    int prefixSum, suffixSum, totalSum, maxSum;
    void assignLeaf(int value) {
        prefixSum = suffixSum = totalSum = maxSum = value;
    }
    void merge (SegmentTreeNode& left, SegmentTreeNode& right) {
        totalSum = left.totalSum + right.totalSum;
        prefixSum = max(left.prefixSum, left.totalSum + right.prefixSum);
        suffixSum = max(right.suffixSum, right.totalSum + left.suffixSum);
        maxSum=max(prefixSum, max(suffixSum, max(left.maxSum, max(right.maxSum,left.suffixSum+right.prefixSum))));
    }
    int getValue() {
        return maxSum;
    }
};

class SegmentTree {
    SegmentTreeNode* node;
    int N;

    public:
        SegmentTree(int arr[], int N){
            this->N = N;
            node = new SegmentTreeNode[getSegmentTreeSize(N)];
            buildTree(arr, 1, 0, N-1);
        }

        ~SegmentTree(){
            delete[] node;
        }

        int getValue(int low, int high){
            SegmentTreeNode result = getValue(1, 0, N-1, low, high);
            return result.getValue();
        }
    private:
        void buildTree(int arr[], int stIndex, int low, int high) {
            if(low == high){
                node[stIndex].assignLeaf(arr[low]);
                return;
            }
            int mid = (low + high)/2;
            buildTree(arr, 2*stIndex, low, mid); // Calling Build Tree Recursively on Left Sub Tree
            buildTree(arr, 2*stIndex+1, mid+1, high);
            node[stIndex].merge(node[2*stIndex], node[2*stIndex+1]);
        }

        int getSegmentTreeSize(int N){
            int size = 1;
            for(; size < N; size <<= 1);
            return size << 1;
        }

        SegmentTreeNode getValue(int stIndex, int left, int right, int low, int high) {
            if(left == low && right == high) {
                return node[stIndex];
            }

            int mid = (left + right) / 2;
            if(low > mid)
                return getValue(2*stIndex+1, mid+1, right, low, high);
            if (high <= mid)
                return getValue(2*stIndex, left, mid, low, high);
            SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, low, high);
            SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, low, high);
            SegmentTreeNode result;
            result.merge(leftResult, rightResult);
            return result; 
        }
};

int main(){
    int N, i, A[50000], M, x, y;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    SegmentTree st(A, N);
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", st.getValue(x-1, y-1));
    }
    return 0;
}