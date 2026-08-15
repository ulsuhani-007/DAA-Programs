#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node* create_node(int value){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
struct node* insert(struct node*root,int value){
    if(root==NULL){
        return create_node(value);
    }
    if(value < root->data){
        root->left=insert(root->left,value);
    }
    else if(value > root->data){
        root->right=insert(root->right,value);
    }
    return root;
}
struct node* min(struct node*root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
struct node*delete_node(struct node*root,int value){
    if (root == NULL){
        return root;
    }

    if (value < root->data){
        root->left = delete_node(root->left, value);
    }
    else if (value > root->data){
        root->right = delete_node(root->right, value);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            struct node*temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL){
            struct node*temp= root->left;
            free(root);
            return temp;
        }
        else {
            struct node*temp=min(root->right);
            root->data=temp->data;
            root->right=delete_node(root->right,temp->data);
        }
    }
    return root;
}

void inorder(struct node*root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main() {
    struct node*root=NULL;
    int n,x,del;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root=insert(root,x);
    }
    printf("BST: ");
    inorder(root);
    printf("\n");
    printf("Enter element to delete: ");
    scanf("%d",&del);
    root = delete_node(root, del);
    printf("After deletion: ");
    inorder(root);
    return 0;
}
    