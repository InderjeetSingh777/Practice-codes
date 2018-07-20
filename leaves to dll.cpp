//Problem Statement:Given a Binary Tree, extract all leaves of it in a Doubly Linked List (DLL).
//Note that the DLL need to be created in-place. Assume that the node structure of DLL and Binary Tree is same,
//only the meaning of left and right pointers are different. In DLL, left means previous pointer and right means next pointer.
//Head of DLL should point to the left most leaf and than in inorder traversal and so on.

//Input:
//The task is to complete the method which takes two arguments, root of Binary Tree and reference to head of DLL.
//The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
//There are multiple test cases. For each test case, this method will be called individually.

//Output:
//In the function make changes in Head.

//Constraints:
//1<=T<=100
//1<=N<=10000
void create_dll(Node*root,Node**head_ref,Node**prev)
{
    if(!root)//base case
    return;
    if(!root->left&&!root->right)//if we reached a leaf
    {
        if(*prev)//if previously we have encountered a leaf already
        (*prev)->right=root;//make current leaf as next node of previous leaf
        if(!(*head_ref))//if head is null,set it
        *head_ref=root;
        root->left=*prev;//make previous leaf (if exists) as previous node of current leaf
        *prev=root;//update previous
        return;

    }
    create_dll(root->left,head_ref,prev);//recursive calls for left and right child
    create_dll(root->right,head_ref,prev);
}
Node *convertToDLL(Node *root,Node **head_ref)//cover function
{
    Node*prev=NULL;
   create_dll(root,head_ref,&prev);//call to working function
}

