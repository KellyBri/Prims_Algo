// Prim’s Algorithm for computing Minimum Spanning Tree


#include <stdio.h>
#include <stdlib.h>

struct node{
    int destination;
    int weight;
    node *next;
};
node *vertex[51];
node *ptr1, *ptr2, *temp;



void initial(){
    for (int i=0; i<=50; i++){
        vertex[i]=(node *)malloc(sizeof(node));
        vertex[i]=NULL;
    }
}


int main() {
    
    unsigned int u = 0;
    unsigned int n, N, m, M, i, j, w, s, sum=0;
    int key[51],parent[51],W[51]={0};
    int min;
    initial();
    for (i=0; i<=50; i++) key[i]=2147483647;
    
    scanf("%d %d",&N,&M);
    if (N>=1 && N<=50 && M>=1 && M<=200) {
        
        for (m=1; m<=M; m++) {
            
            scanf("%d %d %d", &i, &j, &w);
            if (i>N || i<1 || j>N || j<1 || i==j) break;
            ptr1=(node *)malloc(sizeof(node));
            ptr2=(node *)malloc(sizeof(node));
            temp=(node *)malloc(sizeof(node));
            
            ptr1->destination=j;
            ptr1->weight=w;
            temp=vertex[i];
            ptr1->next=temp;
            vertex[i]=ptr1;
            
            ptr2->destination=i;
            ptr2->weight=w;
            temp=vertex[j];
            ptr2->next=temp;
            vertex[j]=ptr2;
        }
        scanf("%d",&s);
        key[s]=0;
        if (s<=N && s>=1) {
            for (j=1; j<=N; j++) {
                
                min=2147483647;
                for (i=1; i<=N; i++){
                    if (key[i]<min && key[i]!=-1) {
                        u=i;
                        min=key[i];
                    }
                }
                
                while (vertex[u]!=NULL) {
                    if (key[vertex[u]->destination]>vertex[u]->weight){
                        key[vertex[u]->destination]=vertex[u]->weight;
                        parent[vertex[u]->destination]=u;
                        W[vertex[u]->destination]=vertex[u]->weight;
                    }
                    vertex[u]=vertex[u]->next;
                }
                key[u]=-1;
            }
        }
        
        //output
        for (i=1; i<=N; i++) {
            printf("%d",parent[i]);
            if (i!=N) printf(" ");
        }
        printf("\n");
        for (i=1; i<=N; i++) sum+=W[i];
        printf("%d\n",sum);
    }
    return 0;
}
