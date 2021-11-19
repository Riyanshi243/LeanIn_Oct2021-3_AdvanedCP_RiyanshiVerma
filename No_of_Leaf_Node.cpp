//4. Write a program to count the number of leaf nodes in a generic tree using recursion.

#include <bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode<T>*> children;
		
	TreeNode(T data)
	{
		this->data=data;
	}
	~TreeNode()
	{
		for(int i=0;i<children.size();i++)
		{
			delete children[i];
		}
	}
};
int countLeaves(TreeNode<int>* root)
{
    int leaves = 0;
    if(root->children.size()==0)
    	return 1;
    for(int i = 0; i < root->children.size(); i++) 
            leaves += countLeaves(root->children[i]);
        return leaves;
}
TreeNode<int>* takeInputLevelWise()
{
	int rootData;
	cout<<"Enter root data"<<endl;
	cin>>rootData;
	TreeNode<int>*root= new TreeNode<int>(rootData);
	queue<TreeNode<int>*>pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		TreeNode<int>* front= pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter num of children of"<<front->data<<endl;
		int numChild;
		cin>>numChild;
		
		for(int i=0;i<numChild;i++)
		{
			int childData;
			cout<<"enter "<<i<<"th child of "<<front->data<<endl;
			cin>>childData;
			TreeNode<int>* child=new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}
int main()
{
	TreeNode<int>* root= takeInputLevelWise();
	cout<<"Number of leaf nodes : "<<countLeaves(root)<<endl;  
}

