//1.Given a generic tree, write a program to print the tree level wise.

#include<iostream>
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
void LevelOrderTraversal(TreeNode<int>* root)
{
 	if (root==NULL)
        return;
    queue<TreeNode<int>*> queue;  
    queue.push(root); 
    while (!queue.empty())
    {
        int n = queue.size();
        while (n > 0)
        {
            TreeNode <int>* p = queue.front();
            queue.pop();
            cout << p->data << " ";
            for (int i=0; i<p->children.size(); i++)
                queue.push(p->children[i]);
            n--;
        }
        cout<<endl; 
    }
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
	LevelOrderTraversal(root);
}

