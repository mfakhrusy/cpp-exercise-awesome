#include <iostream>
#include <cstddef>

class Node {

	public:
		int data;
		Node *left;
		Node *right;
		Node(int d) {
			data = d;
			left = NULL;
			right = NULL;
		}
};

class Solution {

	public:
		Node *insert(Node *root, int data) {
		
			if (root == NULL) {
			
				return new Node(data);

			} else {
				Node *currentNode;
				if (data <= root->data) {

					currentNode = insert(root->left, data);
					root->left = currentNode;
				
				} else {
					currentNode = insert(root->right, data);
					root->right = currentNode;
				}

				return root;
			}
		}


/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
	int height(Node* root) {
    	// Write your code here.

		return root->data;
	}
  
};

int main() {

	Solution myTree;
	Node *root = NULL;
	int t;
	int data;

	std::cin >> t;

	while(t-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	int height = myTree.height(root);
	std::cout << height;

	return 0;
}
