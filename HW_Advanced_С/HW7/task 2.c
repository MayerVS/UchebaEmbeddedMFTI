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

tree * findBrother(tree *root, int key)
{

    if(root==NULL)
        return root;   

    tree *cur = root;
    while (cur != NULL) {
        if (key == cur->key) 
            break;
        if (key < cur->key) 
            cur = cur->left;
        else 
            cur = cur->right;
    }
    
    if (cur == NULL) 
        return NULL;
    if (cur->parent == NULL) 
        return NULL;

    if (cur->parent->left == cur) 
        return cur->parent->right;
    else 
        return cur->parent->left;
}

int main(void)
{
    tree *tr = NULL, *cur = NULL;
    insert(&tr,10,NULL);
    insert(&tr,5, NULL);
    insert(&tr,15,NULL);
    insert(&tr,3, NULL);
    insert(&tr,7 ,NULL);  
    insert(&tr,18,NULL);  
    insert(&tr,1, NULL);    
    insert(&tr,6 ,NULL);
    
    cur = findBrother(tr, 7);
    
    printf("%d", cur->key);
    
}
