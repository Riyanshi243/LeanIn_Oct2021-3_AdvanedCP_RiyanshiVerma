//5. Write a program to print a generic tree in Post order.

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

void traversal(TreeNode<int>* root,vector<int> &post)
{
    if(root==NULL)  
	return;
    for(int i = 0; i < root->children.size(); i++)
            traversal(root->children[i],post);
    post.push_back(root->data);
}
vector<int> PostOrder(TreeNode<int>* root) 
{
    vector<int> post;
    traversal(root,post);
    return post;
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
	vector<int> v;
	cout<<"Post Order Traversal: ";
	v=PostOrder(root);
	 cout << "\nThe vector elements are: ";
    for (int i=0; i < v.size(); i++)
        cout << v[i] << " ";  
}

