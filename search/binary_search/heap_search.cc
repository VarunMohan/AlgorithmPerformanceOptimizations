#include <algorithm>
#include <iostream>

struct BinaryTree{
    int value;
    BinaryTree *left, *right;
};

using namespace std;

BinaryTree *create_binary_tree(int val) {
    BinaryTree *new_node = (BinaryTree *)malloc(sizeof(BinaryTree));
    new_node->value = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void convert_array(int* in, BinaryTree *root, int index) {
    if (root == NULL) return;
    in[index] = root->value;
    if (root -> left != NULL) {
	convert_array(in, root -> left, index * 2 + 1);
    }
    if (root -> right != NULL) {
	convert_array(in, root->right, index * 2 + 2);
    }
    return ;
}

BinaryTree* sortedArrayToBST(int arr[], int start, int end) {
  if (start > end) return NULL;
  // same as (start+end)/2, avoids overflow.
  int mid = (start + (end - start) + 1) / 2;
  BinaryTree *node = create_binary_tree(arr[mid]);
  node->left = sortedArrayToBST(arr, start, mid-1);
  node->right = sortedArrayToBST(arr, mid+1, end);
  return node;
}

BinaryTree* sortedArrayToBST(int arr[], int n) {
  return sortedArrayToBST(arr, 0, n-1);
}

void heapify(int *arr, int n) {
    std::sort(arr, arr+n);
    BinaryTree* root = sortedArrayToBST(arr, n);
    convert_array(arr, root, 0);
}

int main(void) {
    int n = 7;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = i;
    heapify(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
