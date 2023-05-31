#include<bits\stdc++.h>
#include<iostream>
using namespace std;

int flag=0;
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
}*root;

class avlTree
{
    public:
           int max(int a, int b);
           int height(struct node *N);
           node* newNode(int key);
           void display(node *ptr, int level);
           node* rightRotate(struct node *y);
           node* leftRotate(struct node *x);
           int getBalance(struct node *N);
           struct node* insert(struct node* node, int key);
           struct node * minValueNode(struct node* node);
           struct node* Delete(struct node* root, int key);
           void inOrder(struct node *root);
           void search(int);

        avlTree()
        {
            root = NULL;
        }
};

void avlTree::search(int key)
{
     node *temp = root,*parent = root;
    if(temp==NULL)
        cout<<"\nThe AVL Tree is empty\n"<<endl;
    else
    {
        while(temp!=NULL && temp->key!=key)
        {
            parent=temp;
            if(temp->key<key)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
    }
    
    if(temp==NULL)
        cout<<"This element is NOT present in the tree!";
    else
        {cout<<"\nThis element is present in the tree! ";
        cout<<"\nIt's height is: "<<temp->height;
        }
        
}

int avlTree::max(int a, int b)
{
    return (a > b)? a : b;
}
 
int avlTree::height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

void avlTree::display(node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        cout << endl;
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->key;
        display(ptr->left, level + 1);
    }
}

struct node* avlTree::newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  
    return(node);
}
 
struct node* avlTree::rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}
 
struct node* avlTree::leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}
 

int avlTree::getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* avlTree::insert(struct node* node, int key)
{
    if (node == NULL)
        return(newNode(key));
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);
    // 1.Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    // 2.Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    // 3.Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    // 4.Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct node * avlTree::minValueNode(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;
    return current;
}
 
struct node* avlTree::Delete(struct node* root, int key)
{
    if (root == NULL)
        return root;
    if ( key < root->key )
        root->left = Delete(root->left, key);
    else if( key > root->key )
        root->right = Delete(root->right, key);
    else
    {   // 1 or 0 chid node
        if( (root->left == NULL) || (root->right == NULL) )
        {   struct node *temp = root->left ? root->left : root->right;
            flag=1;
            // 0 child
            if(temp == NULL)
            {       
                temp = root;
                root = NULL;
                flag=1;
            }
            else //1 child
             {*root = *temp;flag=1;}
        free(temp);
        }
        else
        {
            struct node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = Delete(root->right, temp->key);
        }
    }
    if (root == NULL)
      return root;
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    // 1.Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    // 2.Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
    // 3.Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    // 4.Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void avlTree::inOrder(struct node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->key <<" ";
        inOrder(root->right);
    }
}

int main()
{
    int choice, item;
    avlTree avl;
    while (1)
    {
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.Delete Element from tree"<<endl;
        cout<<"4.InOrder traversal"<<endl;
        cout<<"5.Search for an Element"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"\nEnter your Choice: ";
        cin>>choice;
        cout<<"\n";
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            root = avl.insert(root, item);
            system("cls");
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.display(root, 1);
            break;
        case 3: cout<<"\nEnter value to be deleted: ";
            cin>>item;
            root = avl.Delete(root, item);
            if(flag==0)
                       cout<<"\nElement not found in this tree!";
            else
                cout<<"\nElement deleted successfully!";
            break;
        case 4:
            cout<<"Inorder Traversal:"<<endl;
            avl.inOrder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"\nEnter element to search: ";
            cin>>item;
            avl.search(item);
            break;
        case 0:
            exit(1);    
            break;
        default:
            cout<<"\nWrong Choice!"<<endl;
        }
    }
}