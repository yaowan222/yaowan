``c
#include<stdio.h>
#include<malloc.h>
const int MinData=1e-9;
typedef struct HeapStruct *PriorityQueue;
struct HeapStruct{
    int capacity;
    int size;
    int *element;
};
PriorityQueue init(int maxSize){
    PriorityQueue H=(PriorityQueue)malloc(sizeof(struct HeapStruct));
    H->element=(int*)malloc(sizeof(int)*(maxSize+1));
    H->capacity=maxSize;
    H->size=0;
    H->element[0]=MinData;
    return H;
}
void insert(int x,PriorityQueue H){
    int i;
    for(i=++H->size;H->element[i/2]>x;i/=2)
        H->element[i]=H->element[i/2];
    H->element[i]=x;
}
int deleteMin(PriorityQueue H){
    int i,child,minElement,lastElement;
    minElement=H->element[1];
    lastElement=H->element[H->size--];
    for(i=1;i*2<=H->size;i=child){
        child=i*2;
        if(child!=H->size&&H->element[child+1]<H->element[child])
            child++;
        if(lastElement>H->element[child])
            H->element[i]=H->element[child];
        else
            break;
    }
    H->element[i]=lastElement;
    return minElement;
}
//输入n个数求前kx
void test(){
    int n,k,tmp,ans;
    scanf("%d%d",&n,&k);
    PriorityQueue Q=init(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        insert(tmp,Q);
    }
    for(int i=1;i<k;i++){
        deleteMin(Q);
    }
    ans=deleteMin(Q);
    printf("%d\n",ans);
}
int main(){
    test();
    return 0;
}
