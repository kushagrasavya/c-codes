#include <stdio.h>
typedef struct job{
    int profit;
    int deadline;
}job;
void sort (job GG[],int n)
{
        for(int i=n-1;i>0;i--)
    {
        int flag=0;
        for(int j=n-1;j>n-i-1;j--)
        {
            if(GG[j].profit>GG[j-1].profit)
            {
            job temp=GG[j];
            GG[j]=GG[j-1];
            GG[j-1]=temp;
            flag=1;
            }
        }
        if(flag==0)
        break;
    }
}
int maxdeadline(job a[],int n)
{
    int x=a[0].deadline;
    for(int i=0;i<n;i++)
    {
        if(x<a[i].deadline)
        x=a[i].deadline;
    }
    return x;
}
void sequence(job GG[],int n,job seq[],int x){
    for(int i=0;i<x;i++)
    seq[i].deadline=-1;
    for(int i=0;i<n;i++)
    {
        int j=GG[i].deadline-1;
        while(j>-1)
        {
            if (seq[j].deadline==-1)
            {
                seq[j]=GG[i];
                break;
            }
            j--;
        }
    }
}
void display(job aa[],int m)
{
    printf("\n Deadline :");
    for(int i=0;i<m;i++)
    {
        printf("\t%d",aa[i].deadline);
    }
    printf("\n Profit  :");
        for(int i=0;i<m;i++)
    {
        printf("\t%d",aa[i].profit);
    }
}
int totalprofit(job seq[],int x)
{
    int total=0;
    for(int i=0;i<x;i++)
    {
        total=total + seq[i].profit;
    }
    return total;
}
int main()
{
    job GG[10];
    int n;
    printf("Enter no of job : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter deadling of job %d :",i);
        scanf("%d",&GG[i].deadline);
        printf("Enter  profit of job  %d :",i);
        scanf("%d",&GG[i].profit);
    }
    sort(GG,n);
    int x=maxdeadline(GG,n);
    job seq[x];
    sequence(GG,n,seq,x);
    display(seq,x);
    printf("\nTotal profit : %d",totalprofit(seq,x));
    return 0;
}