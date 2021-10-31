#include<stdio.h>
#include<malloc.h>

#define insert(x,H) ( H=insert1( (x), H) )
#define delteMin(H) (H=delteMin1(H))
typedef struct TreeNode *PriorityQueue;
PriorityQueue merge1(PriorityQueue H1,PriorityQueue H2);

struct TreeNode{
    int Element;
    PriorityQueue left;
    PriorityQueue right;
    int Npl;
};

PriorityQueue init(){
    PriorityQueue H=(PriorityQueue)malloc(sizeof(struct TreeNode));
    H->Element=0;
    H->Npl=0;
    H->left=H->right=0;
    return H;
}
void swapChildren(PriorityQueue H){
    PriorityQueue tmp=H->left;
    H->left=H->right;
    H->right=tmp;
}
PriorityQueue merge(PriorityQueue H1,PriorityQueue H2){
    if(H1==NULL)
        return H2;
    if(H2==NULL)
        return H1;
    if(H1->Element<H2->Element)
        return merge1(H1,H2);
    else
        return merge1(H2,H1);
}
PriorityQueue merge1(PriorityQueue H1,PriorityQueue H2){
    if(H1->left==NULL)
        H1->left=H2;
    else{
        H1->right=merge(H1->right,H2);
        if(H1->left->Npl<H1->right->Npl)
            swapChildren(H1);
        H1->Npl=H1->right->Npl+1;
    }
    return H1;
}
PriorityQueue insert1(int x,PriorityQueue H){
    PriorityQueue SingleNode=(PriorityQueue)malloc(sizeof(struct TreeNode));
    SingleNode->Element=x;
    SingleNode->Npl=0;
    SingleNode->left=SingleNode->right=NULL;
    H=merge(SingleNode,H);
    return H;
}
PriorityQueue delteMin1(PriorityQueue H){
    PriorityQueue leftHeap,rightHeap;
    leftHeap=H->left;
    rightHeap=H->right;
    free(H);
    return merge(leftHeap,rightHeap);
}
int findMin(PriorityQueue H){
    return H->Element;
}
int main(){
    PriorityQueue H1=init();
    H1->Element=10;
    PriorityQueue H2=init();
    H2->Element=9;
    insert(2,H1);
    insert(1,H1);
    insert(4,H2);
    insert(5,H2);
    PriorityQueue H=merge(H1,H2);
    while(H){
        printf("%d\n",findMin(H));
        delteMin(H);
    }
    return 0;
}
