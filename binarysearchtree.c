#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int value;
    struct treenode *lc;
    struct treenode *rc;
} tree;

void BuildBST(tree *root, int x);
void preorder(tree *root);
void inorder(tree *root);
void postorder(tree *root);
void search(tree *root,int k);
void insert(tree *root);
tree* inorderpredecessor( tree *root);
tree* delete(tree *root,int y);
tree* largest(tree *root);
tree* smallest(tree *root);
int height(tree *root);
int getleafcount(tree *root);

int main() {
    tree *root;
    root = (tree *)malloc(sizeof(tree));

    // Initialize root with a value
    printf("Enter the value for the root node: ");
    scanf("%d", &(root->value));

    root->lc = NULL;
    root->rc = NULL;
    char ch;

    while (ch!='n') {
        int x;
        printf("Enter a value to insert into the BST: ");
        scanf("%d", &x);
        BuildBST(root, x);
        getchar();
        printf("would you like to continue(y for yes and n for no):");
        ch=getchar();
    }

    printf("1.preorder\n 2.inorder\n 3.postorder\n 4.search\n 5.insert\n 6.delete\n 7.Largest\n 8.Smallest\n 9.Height\n 10.count leaf nodes\n 11.EXIT\n");
    int choice,k,y,height1,count;
    tree *largestnode,*smallestnode;
    start:printf("\nenter choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1:printf("Preorder: ");
           preorder(root);
           goto start;
    case 2:printf("\nInorder: ");
           inorder(root);
           goto start;
    case 3:printf("\nPostorder: ");
           postorder(root);
           goto start;
    case 4:printf("\nelement to be searched:");
           scanf("%d",&k);
           search(root,k);
           goto start;
    case 5:insert(root);
           goto start;
    case 6:printf("the value to be deleted:");
           scanf("%d",&y);
           delete(root,y);
           goto start;
    case 7:largestnode=largest(root);
           printf("largest value is: %d",largestnode->value);
           goto start;
    case 8:smallestnode=smallest(root);
           printf("smallest value is:%d",smallestnode->value);
           goto start;
    case 9:height1=height(root);
           printf("height of tree is:%d",height1-1);
           goto start;
    case 10:count=getleafcount(root);
            printf("no. of leaf is:%d",count);
            goto start;
    case 11:printf("you are exited");
           break;
    default:printf("invalid choice");
    }

    return 0;
}

void BuildBST(tree *root, int x) {
    tree *new;
    if (x > root->value) {
        if (root->rc == NULL) {
            new = (tree *)malloc(sizeof(tree));
            new->value = x;
            new->lc = NULL;
            new->rc = NULL;
            root->rc = new;
        } else {
            BuildBST(root->rc, x);
        }
    } else if (x < root->value) {
        if (root->lc == NULL) {
            new = (tree *)malloc(sizeof(tree));
            new->value = x;
            new->lc = NULL;
            new->rc = NULL;
            root->lc = new;
        } else {
            BuildBST(root->lc, x);
        }
    } else {
        printf("\nDuplicate element=%d\n", x);
    }
}

void preorder(tree *root) {
    if (root != NULL) { 
        printf("%d ", root->value);
        preorder(root->lc);
        preorder(root->rc);
    }
}

void inorder(tree *root) {
    if (root != NULL) {
        inorder(root->lc);
        printf("%d ", root->value);
        inorder(root->rc);
    }
}

void postorder(tree *root) {
    if (root != NULL) {
        postorder(root->lc);
        postorder(root->rc);
        printf("%d ", root->value);
    }
}

void search(tree *root, int k) {
    if (root == NULL) {
        printf("\nElement is not present\n");
        return;
    }

    if (k == root->value) {
        printf("\nElement is present\n");
    } else if (k < root->value) {
        search(root->lc, k);
    } else {
        search(root->rc, k);
    }
}

void insert(tree *root){
    int a;
    printf("element to be insert:");
    scanf("%d",&a);
    tree *pre=NULL;

    while(root!=NULL){
        pre=root;
        if(a==root->value){
            printf("element is already present");
            return;
        }
        else if(a<root->value){
            root=root->lc;
        }
         else {
           root=root->rc;
        }
    }
    tree *new;
    new=(tree*)malloc(sizeof(tree));
    new->value=a;
    new->lc=NULL;
    new->rc=NULL;
    if(a<pre->value){
        pre->lc=new;
    }
    else{
        pre->rc=new;
    }
}

tree* inorderpredecessor( tree *root){
    tree *temp=root;
    temp=temp->lc;
    while(temp->rc!=NULL){
        temp=temp->rc;
    }
    return temp;
}

tree* delete(tree *root, int y) {
    if (root == NULL) {
        return NULL;
    }

    if (y > root->value) {
        root->rc = delete(root->rc, y);
    } else if (y < root->value) {
        root->lc = delete(root->lc, y);
    } else {
        if (root->lc == NULL) {
            tree *temp = root->rc;
            free(root);
            return temp;
        } else if (root->rc == NULL) {
            tree *temp = root->lc;
            free(root);
            return temp;
        }

        tree *ipre = inorderpredecessor(root);
        root->value = ipre->value;
        root->lc = delete(root->lc, ipre->value);
    }

    return root;
}

tree* largest(tree *root){
    if(root==NULL){
        return NULL;
    }
    else if(root->rc==NULL){
        return root;
    }
    else{
        largest(root->rc);
    }
}

tree* smallest(tree *root){
    if(root==NULL){
        return NULL;
    }
    else if(root->lc==NULL){
        return root;
    }
    else{
        smallest(root->lc);
    }
}

int height(tree *root) {
    if (root == NULL) {
        return 0;
    }
    int lheight = height(root->lc);
    int rheight = height(root->rc);
    if (lheight > rheight) {
        return lheight + 1;
    } else {
        return rheight + 1;
    }
}

int getleafcount(tree *root){
    if(root==NULL){
        return 0;
    }
    if(root->lc==NULL && root->rc==NULL){
        return 1;
    }
    else{
        return getleafcount(root->lc)+getleafcount(root->rc);
    }
}


