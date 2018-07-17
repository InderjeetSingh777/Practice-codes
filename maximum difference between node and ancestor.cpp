//Problem Statement:
//Given a Binary Tree you need to  find maximum value which you  can get by subtracting value of node B from value of node A,
//where A and B are two nodes of the binary tree and A is an ancestor of B . You are required to complete the function maxDiff .
// You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

//Input:
//The task is to complete the function maxDiff which takes 1 argument, root of the Tree .
//The struct node has a data part which stores the data, pointer to left child and pointer to right child.
//There are multiple test cases. For each test case, this method will be called individually.

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
void get_max_diff(Node*root,vector<Node*>&ances,int * max_diff)
{
    if(!root)//base case
        return;
    if(ances.size()>0)//means we have ancestors of current node,then calculate difference,..ansd update max_diff if possible
    {
        int size=ances.size();
        for(int i=0;i<size;i++)
        {
            *max_diff=max(*max_diff,(ances[i]->data)-(root->data));
        }
    }
        ances.push_back(root);//current node is ancestor for its left and right child
        //recursive call for leftg and right children
        get_max_diff(root->left,ances,max_diff);
        get_max_diff(root->right,ances,max_diff);
        //after call for the children is over,remove current node fro ancestors
        ances.pop_back();




}
/* Your are required to
complete this method*/
int maxDiff(Node* root)
{
    vector<Node*>ances;//to store ancestors of current node;
    int max_diff=INT_MIN;
    get_max_diff(root,ances,&max_diff);
    return max_diff;
}
