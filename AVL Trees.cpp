#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
	int key;
	node* left;
	node* right;
	int height;		
};
node* newNode(int key)
{
	node* n=new node();
	n->key=key;
	n->left=NULL;
	n->right=NULL;
	n->height=1;
	return n;
}
int height(node* N)
{
	if(N==NULL)
	{
		return 0;
	}
	return N->height;
}
int Balance_factor(node* N)
{
	if (N==NULL)
	{
		return 0;
	}
	return height(N->left)-height(N->right);
}
int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
node* right_rotation(node* p)
{
	node* c=p->left;
	node* T2=c->right;
	c->right=p;
	p->left=T2;
	
	p->height=max(height(p->left),height(p->right))+1;
	c->height=max(height(c->left),height(c->right))+1;
	cout<<"Right Rotation is done.\n";
	return c;
}
node* left_rotation(node* p)
{
	node* c = p->right;
	node* T2 = c->left;
	c->left = p;
	p->right = T2;
	
	p->height=max(height(p->left),height(p->right))+1;
	c->height=max(height(c->left),height(c->right))+1;
	cout<<"Left Rotation is done.\n";
	return c;
}
node* left_right(node* p)
{
	p->left = left_rotation(p->left);
	return right_rotation(p);
}
node* right_left(node* p)
{
	p->right = right_rotation(p->right);
	return left_rotation(p);
}

node* insert_Node(node* N, int key)
{
	if(N==NULL)
	{
		return(newNode(key));
	}
	if(key<N->key)
	{
		N->left=insert_Node(N->left,key);
		
	}
	else if(key>N->key)
	{
		N->right=insert_Node(N->right,key);
	}
	
	// update height
	N->height = 1 + max(height(N->left), height(N->right));
	
	// balancing factor code
	int BF = Balance_factor(N);
	if(BF>1)
	{
		if(key<N->left->key)
		{	
			cout<<"Left Left Case.\n";
			return right_rotation(N);
		}
		else if(key>N->left->key)
		{
			cout<<"Left Right Case.\n";
			return left_right(N);
		}
		
	}
	else if(BF<-1)
	{
		if(key<N->right->key)
		{
			cout<<"Right Left Case.\n";
			return right_left(N);
		}
		else if(key>N->right->key)
		{
			cout<<"Right Right Case.\n";
			return left_rotation(N);
		}
		
	}
	return N;
}
node* search(struct node* root, int key)
{
	int ctr;
	bool flag = false;
	while(root != NULL)
	{
		if(key == root->key)
		{
			cout<<"Node Found.\n";
			return root;	
		}
		else if(root->key > key)
		{
			root = root->left;
			ctr++;
		}
		else if(root->key < key)
		{
			root = root->right;
			ctr++;
		}
	}
	flag = true;
	if(flag)
	{
		cout<<"Node doesn't exist in the BST. \n";
		return NULL;
	}
	
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
		cout<<root->key<<" ";
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
		cout<<root->key<<" ";
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
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

struct node* minimum(struct node* root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root;
}


struct node* delete_node(struct node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
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
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    
        // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Calculate balance factor of the current node
    int BF = Balance_factor(root);

    // Balance the tree if needed
    if (BF > 1 && Balance_factor(root->left) >= 0)
        return right_rotation(root);
    
    if (BF < -1 && Balance_factor(root->right) <= 0)
        return left_rotation(root);
    
    if (BF > 1 && Balance_factor(root->left) < 0) {
        root->left = left_rotation(root->left);
        return right_rotation(root);
    }

    if (BF < -1 && Balance_factor(root->right) > 0) {
        root->right = right_rotation(root->right);
        return left_rotation(root);
    }

    
    return root;
}

int main()
{
	struct node* Root = NULL;
    int opt;
    int data;
    int opt2;
    while(opt != 7)
    {
    	cout << "\nOptions: \n 1)Insert node \n 2)Height Of Sub Tree \n 3)Balance Factor of any node \n 4)Deletion of node \n 5)Traversal \n 6)Search \n 7)Exit \n Choose: " << endl;
    	cin>>opt;
    	if(opt == 1)
    	{
    		cout<<"Enter Value You Want To Add In BST: ";
			cin>>data;
			Root = insert_Node(Root,data);	
		}
		else if(opt == 2)
		{
			if(Root == NULL)
			{
				cout<<"Enter data first.";
			}
			else
			{
				cout<<"Enter Key To Search: ";
				cin>>data;
				cout<<"Height: "<<height(search(Root,data))<<endl;	
			}
		}
		else if(opt == 3)
		{
			if(Root == NULL)
			{
				cout<<"Enter data first.";
			}
			else
			{
				cout<<"Enter Key To Search: ";
				cin>>data;
				cout<<"Balancing Factor: "<<Balance_factor(search(Root,data))<<endl;	
			}
		}
		else if(opt == 4)
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
		else if(opt == 5)
		{
			cout<<"1)Inorder \n2)Preorder \n3)Postorder \nChoose: ";
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
		else if(opt == 6)
		{
			if(Root == NULL)
			{
				cout<<"Enter data first.";
			}
			else
			{
				cout<<"Enter Key To Search: ";
			cin>>data;
			if(search(Root,data)==NULL)
			{
				cout<<"Node Doesn't Exists.";
			}
			else
			{
				cout<<search(Root,data)->key;
			}	
			}
		}
	}
}
