#include<stdio.h>
#include<malloc.h>

#define INF 0x3f3f3f3f

typedef struct BinNode *Position;
typedef Position BinTree;
typedef struct Collection *BinQueue;
const int MaxTrees=10;

struct BinNode{
    int Element;
    Position leftChild;
    Position nextSibling;
};
struct Collection{
    int CurrentSize;
    BinTree TheTrees[MaxTrees];
};
BinTree CombineTrees(BinTree T1,BinTree T2){    //二项树合并
    if(T1->Element>T2->Element)
        CombineTrees(T2,T1);
    T2->nextSibling=T1->leftChild;
    T1->leftChild=T2;
    return T1;
}
BinQueue initQueue(){
    BinQueue H=(BinQueue)malloc(sizeof(struct Collection));
    H->CurrentSize=1;
    for(int i=0;i<MaxTrees;i++)
        H->TheTrees[i]=NULL;
    return H;
}
BinQueue merge(BinQueue H1,BinQueue H2){    //二项队列合并
    BinTree T1,T2,carry=NULL;
    H1->CurrentSize+=H2->CurrentSize;
    for(int i=0,j=1;j<=H1->CurrentSize;i++,j*=2){
        T1=H1->TheTrees[i];
        T2=H2->TheTrees[i];
        switch(!!T1+2*!!T2+4*!!carry){
            case 0:
            case 1:
                break;
            case 2:
                H1->TheTrees[i]=T2;
                H2->TheTrees[i]=NULL;
                break;
            case 3:
                carry=CombineTrees(T1,T2);
                H1->TheTrees[i]=H2->TheTrees[i]=NULL;
                break;
            case 4:
                H1->TheTrees[i]=carry;
                carry=NULL;
                break;
            case 5:
                carry=CombineTrees(T1,carry);
                H1->TheTrees[i]=NULL;
                break;
            case 6:
                carry=CombineTrees(T2,carry);
                H2->TheTrees[i]=NULL;
                break;
            case 7:
                H1->TheTrees[i]=carry;
                H2->TheTrees[i]=NULL;
                carry=CombineTrees(T1,T2);
                break;
        }
    }
    return H1;
}
int deleteMin(BinQueue H){  //二项队列删除最小值
    int minTree,minItem;
    BinTree deletedTree,oldRoot;
    BinQueue deletedQueue;
    minItem=INF;
    for(int i=0;i<MaxTrees;i++){
        if(H->TheTrees[i]&&H->TheTrees[i]->Element<minItem){
            minItem=H->TheTrees[i]->Element;
            minTree=i;
        }
    }
    deletedTree=H->TheTrees[minTree];
    oldRoot=deletedTree;
    deletedTree=deletedTree->leftChild;
    free(oldRoot);
    deletedQueue=initQueue();
    deletedQueue->CurrentSize=(1<<minTree)-1;
    for(int i=minTree-1;i>=0;i--){
        deletedQueue->TheTrees[i]=deletedTree;
        deletedTree=deletedTree->nextSibling;
        deletedQueue->TheTrees[i]->nextSibling=NULL;
    }
    H->TheTrees[minTree]=NULL;
    H->CurrentSize-=deletedQueue->CurrentSize+1;
    merge(H,deletedQueue);
    return minItem;
}
int main(){
    BinQueue H1=initQueue();
    H1->TheTrees[0]=(BinTree)malloc(sizeof(struct BinNode));
    H1->TheTrees[0]->Element=1;
    H1->TheTrees[0]->leftChild=H1->TheTrees[0]->nextSibling=NULL;
    BinQueue H2=initQueue();
    H2->TheTrees[0]=(BinTree)malloc(sizeof(struct BinNode));
    H2->TheTrees[0]->Element=2;
    H2->TheTrees[0]->leftChild=H2->TheTrees[0]->nextSibling=NULL;
    H1=merge(H1,H2);
    printf("%d\n",deleteMin(H1));
    printf("%d\n",deleteMin(H1));
    return 0;
}
