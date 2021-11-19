//3.Write a program to return the node with maximum data in a generic tree using recursion.

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
int MaximumNode(TreeNode<int>* root)
{
    int max = root->data;
    int maxNext;
    int n = root->children.size();
    for (int i = 0; i < n; ++i) 
	{
		maxNext= MaximumNode(root->children[i]);
		if(maxNext>max)
		max=maxNext;
    }
    return max;
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
	cout<<"Maximum of all the nodes : "<<MaximumNode(root)<<endl;  
}

