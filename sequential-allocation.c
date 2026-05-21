#include<stdio.h>
#include<string.h>

struct block
{
    int b_id;
    int b_allocated;
};

struct block b[50];

int main()
{
    int no,i,j,n,sblock=0,eblock=0,count=0;
    int psize,flag=0,pname,bname;

    printf("\nEnter the no. of blocks: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        b[i].b_id=i;
        b[i].b_allocated=0;
    }

    printf("\nEnter the no. of blocks already allocated: ");
    scanf("%d",&no);

    for(i=0;i<no;i++)
    {
        printf("\nEnter the allocated block number: ");
        scanf("%d",&bname);

        b[bname].b_allocated=100;
    }

    printf("\nEnter the process name: ");
    scanf("%d",&pname);

    printf("\nEnter the process size: ");
    scanf("%d",&psize);

    for(i=0;i<n;i++)
    {
        if(b[i].b_allocated==0)
        {
            count++;

            if(count==1)
                sblock=i;

            if(count==psize)
            {
                eblock=i;

                for(j=sblock;j<=eblock;j++)
                    b[j].b_allocated=pname;

                printf("\nProcess %d is allocated blocks from %d to %d\n",
                pname,sblock,eblock);

                flag=1;
                break;
            }
        }
        else
        {
            count=0;
        }
    }

    if(flag==0)
        printf("\nProcess not allocated\n");

    printf("\nMemory Blocks Status:\n");

    for(i=0;i<n;i++)
    {
        printf("b[%d] -> %d\t",b[i].b_id,b[i].b_allocated);

        if((i+1)%4==0)
            printf("\n");
    }

    return 0;
}