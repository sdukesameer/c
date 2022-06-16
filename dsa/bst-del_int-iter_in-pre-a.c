#include<stdio.h> 
#include<stdlib.h> 
typedef struct n
{ 
	int key;
	struct n *left, *right; 
}list;
list *newNode(int item) 
{ 
	list *temp = (list*)malloc(sizeof(list)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
list* rec_insert(list* node, int key) 
{ 
	if (node == NULL) 
	return newNode(key); 
	if (key < node->key) 
		node->left = rec_insert(node->left, key); 
	else if (key > node->key) 
		node->right = rec_insert(node->right, key); 
	return node;
}
void iter_inorder(list* node)
{
    int top=-1;
	list *stk[20];
	while(1)
	{
		while(node!=NULL)
		{
			stk[++top]=node;
			node=node->left;
		}
		if(top==-1)
			break;
		printf(" %d",stk[top]->key);
		node=stk[top]->right;
		top=top-1; 
    }
}
void iter_preorder(list* node)
{
    int top=-1;
    list *stk[20];
    while(1)
    {
        while(node!=NULL)
        {
            printf(" %d",node->key);
			stk[++top]=node;
				node=node->left;
		}
		if(top==-1)
			break;
		node=stk[top]->right;
		top=top-1;
    }
}
list* minValNode(list* node)
{
    list* curr=node;
    while(curr && curr->left!=NULL)
    curr=curr->left;
    return curr;
}
int find(list* root, int n)
{
    if (root==NULL)
        return 0;
    else
    {
        if (n<root->key)
            find(root->left,n);
        else if(n>root->key)
            find(root->right,n);
        else
            return 1;
    }
}
list* Del_Node(list* node, int n)
{
    if(node==NULL)
        return node;
    if(n<node->key)
        node->left=Del_Node(node->left,n);
    else if(n>node->key)
        node->right=Del_Node(node->right,n);
    else
    {
        if(node->left==NULL)
        {
            list*temp=node->right;
            free(node);
            return temp;
        }
        else if (node->right==NULL)
        {
            list* temp=node->left;
            free(node);
            return temp;
        }
        list* temp=minValNode(node->right);
        node->key=temp->key;
        node->right=Del_Node(node->right,temp->key);
    }
    return node;
}
void printtree(list *node, int n) 
{
	int COUNT = 4;
    if (node == NULL) 
        return; 
    n += COUNT; 
    printtree(node->right, n); 
    printf("\n"); 
    for (int i = COUNT; i < n; i++) 
        printf(" ");
    printf("%d\n", node->key); 
    printtree(node->left, n); 
}
int main() 
{ 
    int ch;
    int d;
    list* T;
    list* root=NULL;
    while(1)
    {
        printf("\n");
        printf("1. Insertion Using Recursive Function \n");
        printf("2. Iterative In-Order Traversal \n");
        printf("3. Iterative Pre-Order Traversal \n");
        printf("4. Deleting an integer from BST  \n");
        printf("5. Display the BST \n");
        printf("6. Exit Program \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if (ch==1)
        {
            int n;
            printf("Enter the element: ");
            scanf("%d",&n);
            root=rec_insert(root,n);
            printf("%d inserted in Binary Tree\n",n);
        }
        else if(ch==2)
        {
            printf("\nIN-ORDER\n");
            iter_inorder(root);
        }
        else if(ch==3)
        {
            printf("\nPRE-ORDER\n");
            iter_preorder(root);
        }
        else if(ch==4)
        {
            int d;
            printf("Enter No.to be deleted: ");
            scanf("%d",&d);
            if(find(root,d)==1)
            {
                root=Del_Node(root,d);
                printf("%d has been Deleted \n",d);
            }
            else
                printf("%d not found in tree.\n");
        }
        else if(ch==5)
            printtree(root,1);
        else if (ch==6)
        {
            printf("Thank You.\n");
            break;
        }
        else
            printf("Invalid Choice.\n");
    }
	return 0; 
}