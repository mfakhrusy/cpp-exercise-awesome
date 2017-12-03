/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/
void preOrder(node *root) {

    if (root != NULL) {
        preOrder(root->left);
        std::cout << root->data << " ";
        preOrder(root->right);
    }
}
