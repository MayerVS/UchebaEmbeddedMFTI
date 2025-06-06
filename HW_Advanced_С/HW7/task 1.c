#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int key;//datatype 
    struct tree *left, *right;
    struct tree *parent; // необязательное поле
} tree;

void insert(tree **root,int key, tree *pt) {
    if(!(*root))
    { 
// дерево пустое или дошли до нужного места
        *root=(tree *)calloc(1,sizeof(tree));
        (*root)->key=key;
        (*root)->parent=pt;
// c calloc строчка ниже не нужа
        (*root)->left=(*root)->right= NULL;
    }
    else if( key < (*root)->key)
        insert( &((*root)->left) ,key,*root);
    else
        insert( &((*root)->right),key,*root);
}

void btUpView(tree *root)
{
	if(root == NULL || !(root->key))
		return;
	
	tree *cur = root;
	int i = 0, j = 0;
	while(cur->left)
	{
		i++;
		cur = cur->left;
	}
	cur = root;
	while(cur->right)
	{
		j++;
		cur = cur->right;
	}
	cur = root;
	while(i)
	{
		for(int k = i; k; k--)
			cur = cur->left;			
		printf("%d ", cur->key);
		cur = root;
		i--;
	}
	for(int k = 0; k <= j; k++)
	{
		for(int z = k; z; z--)
			cur = cur->right;	
		printf("%d ", cur->key);
		cur = root;
	}
}

int main(void)
{
    tree *tr = NULL;
    insert(&tr,10,NULL);
    insert(&tr,5, NULL);
    insert(&tr,15,NULL);
    insert(&tr,3, NULL);
    insert(&tr,7 ,NULL);  
    insert(&tr,18,NULL);  
    insert(&tr,1, NULL);    
    insert(&tr,6 ,NULL);
    btUpView(tr);
    
}
