#include<iostream>
#include<conio.h>
using namespace std;

struct node{
     int data;
     struct node* left;
   struct  node* right;
};
struct node* newNode(int val)
{
    struct node* root;
    root = new node;
    root->data = val;
    root->right = root->left = NULL;
    return root;
}
struct node* maximum(struct node* root)
{
	while(root->right != NULL)
	{
		root = root->right;
	}
	return root;
}
struct node* minimum(struct node* root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root;
}
struct node* predecessor(struct node* root, int key) {
    struct node* pred = NULL;
    while (root != NULL) {
        if (root->data == key) {
            if (root->left != NULL) {
                pred = maximum(root->left);
            }
            break;
        } else if (root->data > key) {
            root = root->left;
        } else {
            pred = root;
            root = root->right;
        }
    }
    return pred;
}
struct node* successor(struct node* root, int key) {
    struct node* succ = NULL;
    while (root != NULL) {
        if (root->data == key) {
            if (root->right != NULL) {
                succ = minimum(root->right);
            }
            break;
        } else if (root->data < key) {
            root = root->right;
        } else {
            succ = root;
            root = root->left;
        }
    }
    return succ;
}
void inorder(struct node* root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void postorder(struct node* root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}
void preorder(struct node* root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

struct node* insert_node(struct node* root, int data)
{
    if(root == NULL)
    {
        return newNode(data);
    }
    else if(data > root->data)
    {
        root->right= insert_node(root->right,data);
    }
    else if(data < root->data)
    {
        root->left= insert_node(root->left,data);
    }
    return root;
}
int maxsubtree(struct node* root)
{
    if(root->right == NULL)
    {
        return root->data;
    }
    else
    {
       return maxsubtree(root->right);
    }
}
int minsubtree(struct node* root)
{
    if(root->left == NULL)
    {
        return root->data;
    }
    else
    {
       return maxsubtree(root->left);
    }
}
void search(struct node* root, int key)
{
	int ctr;
	bool flag = false;
	while(root != NULL)
	{
		if(key == root->data)
		{
			cout<<root->data<<endl;
			cout<<"Level "<<ctr<<endl;	
		}
		else if(root->data > key)
		{
			root = root->left;
			ctr++;
		}
		else if(root->data < key)
		{
			root = root->right;
			ctr++;
		}
	}
	flag = true;
	if(flag)
	{
		cout<<"Key doesn't exist in the BST. \n";
	}
	
}
struct node* delete_node(struct node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = delete_node(root->left, key);
    else if (key > root->data)
        root->right = delete_node(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            delete root;
            return temp;
        }
        struct node* temp = minimum(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}
int main()
{	
	struct node* Root = NULL;
    int opt;
    int data;
    int opt2;
    while(opt != 8)
    {
    	cout << "\nOptions: \n 1)Insert node \n 2)Traversal \n 3)Max Sub Tree \n 4)Min Sub Tree \n 5)Predecessor & Successor \n 6)Delete Node \n 7)Search \n 8)Exit \n Choose: " << endl;
    	cin>>opt;
		if(opt == 1)
		{
			cout<<"Enter Value You Want To Add In BST: ";
			cin>>data;
			Root = insert_node(Root,data);		
		}
		else if(opt == 2)
		{
			cout<<"1)Inorder \n 2)Preorder \n 3)Postorder \n Choose: ";
			cin>>opt2;
			if(opt2 == 1)
			{
				inorder(Root);
			}
			else if(opt2 == 2)
			{
				preorder(Root);
			}
			else if(opt2 == 3)
			{
				postorder(Root);
			}
		}
		else if(opt == 3)
		{
			cout<<"Maximum Sub Tree: "<<maxsubtree(Root);
		}
		else if(opt == 4)
		{
			cout<<"Minimum Sub Tree: "<<minsubtree(Root);
		}
		else if(opt == 5)
		{
			cout<<"Enter Key: ";
			cin>>data;
			cout<<"Predecessor: "<<predecessor(Root,data)->data<<endl;
			cout<<"Successor: "<<successor(Root,data)->data;
		}
		else if(opt == 6)
		{
			 cout << "Enter Key to Delete: ";
		    cin >> data;
		    Root = delete_node(Root, data);
		    if(Root == NULL)
		    {
		    	cout<<"Tree is Empty";
			}
			else
			{
				cout<<"Node is deleted.";
			}
		}
		else if(opt == 7)
		{
			if(Root == NULL)
			{
				cout<<"Enter data first.";
			}
			else
			{
				cout<<"Enter Key To Search: ";
			cin>>data;
			search(Root,data);	
			}
			
		}	
	}
}
