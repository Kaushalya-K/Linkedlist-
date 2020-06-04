#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;    //pointer self referential
}*first=NULL,*second=NULL,*third=NULL;      //global pointer

void create(int a[],int n)
{
    int i;
    struct Node *t,*last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


void create2(int b[],int n)
{
    int i;
    struct Node *t,*last;
    second = (struct Node*)malloc(sizeof(struct Node));
    second->data=b[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=b[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


int count(struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}
int rcount(struct Node *p)
{
    if(p!=0)
    {
        return rcount(p->next)+1;
    }
    else
        return 0;
}
int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int rsum(struct Node *p)
{
    if(p!=NULL)
    {
        return rsum(p->next)+p->data;
    }
    else
      return 0;
}
int Max(struct Node *p)
{
    int max=-32768;

    while(p)
    {
        if(p->data > max)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}
int RMax(struct Node *p)
{
    int x;
    if(p==0)
      return -32768;
    x=RMax(p->next);
    return x>p->data?x:p->data;
}
struct node * Linear(struct Node *p,int key)
{
   struct Node *q=p;
   while(p!=0)
   {
       if(key==p->data)
       {
           q->next=p->next;
           p->next=first;
           first=p;
           return p;
       }
       q=p;
       p=p->next;
   }
   return 0;
}

void display(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        display(p->next);

    }
}
void insert(struct Node *p,int pos,int x)
{
    struct Node *t;
    if(pos < 0 || pos > rcount(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(pos==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;

    }
}
void sortinsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next= NULL;

    if(first==NULL)
    {
        first=t;
    }
    else
    {
        while(p<x && p->next < x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}
int deletee(struct Node *p,int pos)
{
    struct Node *q;
    int x=-1;
    if(pos < 1 || pos > count(p))
    {
        return -1;
    }
    if(pos==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;//deleted element
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }

}
int issorted(struct Node *p)
{
    int x=-65536;
    while(p!=NULL)
    {
        if(p->data < x)
        {
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}
void removeduplicate(struct Node *p)
{
    struct Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
void reverse1(struct Node *p)
{
    int *a;int i=0;
    struct Node *q;
    a=(int*)malloc(count(p) * sizeof(int));
    while(q!=NULL)
    {
        a[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=a[i];
        q=q->next;
        i--;
    }
}
void reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

void concat(struct Node *p,struct Node *q)
{
    third = p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
    q=NULL;
}

void merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
        last->next=p;
    else if (q)
        last->next=q;
}

int isloop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;

    do
    {
        p=p->next;
        q=q->next;
        q=q!=NULL ? q->next : q;
    }while(p && q && p!=q);
    if(p==q)
        return 1;
    else
        return 0;
}
int main()
{
    struct Node *temp,*t1,*t2;
    int a[]={10,20,30,40,50};
    int b[]={2,15,19,36,55};

    create(a,5);
    //t1=first->next->next;                     //isloop
    //t2=first->next->next->next->next;         //isloop
    //t2->next=t1;                              //isloop
    create2(b,5);

    printf("FIRST\n");
    display(first);
    printf("\n");
    printf("SECOND\n");
    display(second);
    printf("\n");

    printf("\nlength is %d",count(first));

    printf("\nSum is %d",rsum(first));

    printf("\nMax is %d",RMax(first));


    temp=Linear(first,7);
    temp=Linear(first,9);
    if(temp)
      printf("\nKey is found %d\n",temp->data);
    else{
        printf("\nKey is not found");
    }
    printf("\n");
    display(first);
    printf("\n");


    //insert(first,2,10);
    //sortinsert(first,55);


    //printf("the deleted element is %d\n",deletee(first,3));
    //display(first);




    printf("\n%d\n",issorted(first));
    display(first);
    if(issorted(first))
        printf("\nSorted\n");
    else
        printf("\nNot sorted\n");


    removeduplicate(first);
    display(first);
    printf("\nduplicates removed\n");
    printf("\n\n");

    reverse2(first);
    display(first);
    printf("reversed");
    printf("\n\n");

    reverse3(NULL,first);
    display(first);
    printf("reversed");
    printf("\n\n");

    concat(first,second);
    printf("Concatenated\n");
    display(third);
    printf("\n");


    merge(first,second);
    printf("MERGED\n");
    display(third);
    printf("\n");


    printf("%d\n",isloop(first));


}
