#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#define SIZE (sizeof(int)*8)

void toBinary(int,char *);
void binaryAdd(char *,char *,char *);
void rComplement(char *);
int  toDecimal(char *c);
int  pow(int,int);



int main(void)
    {
    int a,b;
    char *c,*d,*e,choice;
    printf("Enter the numbers a and b.\nFor Subtraction enter '-' in between else '+'.\n");
    scanf("%d%c%d",&a,&choice,&b);
    c=(char *)malloc(SIZE+1);
    d=(char *)malloc(SIZE+1);
    e=(char *)malloc(SIZE+1);
    if(c==NULL||d==NULL||e==NULL)
        {
        printf("Memory Allocation Failed.....\nExiting....\n");
        getch();
        return 1;
        }
    switch(choice)
        {
        case '+':
            if(a>=0)
                toBinary(a,c);
            else
                {
                toBinary(abs(a),c);
                rComplement(c);
                }
            if(b>=0)
                toBinary(b,d);
            else
                {
                toBinary(abs(b),d);
                if(b!=-1)
                    rComplement(d);
                }
            binaryAdd(c,d,e);
            printf("\t %s\t %d\n",c,a);
            printf("\t+%s\t+%d\n",d,b);
            if(*(e)=='1')
                {
                printf("\t %s\t",e);
                rComplement(e);
                printf("-%d",toDecimal(e));
                }
            else
                {
                printf("\t %s\t ",e);
                printf("%d",toDecimal(e));
                }
            break;
        case '-':
            if(a>=0)
                toBinary(a,c);
            else
                {
                toBinary(abs(a),c);
                rComplement(c);
                }
            if(b>=0)
                {
                toBinary(b,d);
                if(b!=0)
                    rComplement(d);
                }
            else
                {
                toBinary(abs(b),d);
                }
            binaryAdd(c,d,e);
            printf("\t %s\t %d\n",c,a);
            if(b<0)
                printf("\t+%s\t+%d\n ",d,abs(b));
            else
                printf("\t+%s\t-%d\n ",d,b);
            if(*(e)=='1')
                {
                printf("\t %s\t",e);
                rComplement(e);
                printf("-%d",toDecimal(e));
                }
            else
                {
                printf("\t %s\t ",e);
                printf("%d",toDecimal(e));
                }
            break;
        default:
            printf("Invalid Input....\n");
        }
    getch();
    return 1;
    }
void toBinary(int a,char *c)
    {
    char *s=c;
    int r;
    while(a!=0)
        {
        r=a%2;
        *c='0'+r;
        c++;
        a=a/2;
        }

    while((c-s)!=(SIZE))
        {
        *c='0';
        c++;
        }
    *c='\0';
    strrev(s);
    }
int toDecimal(char *c)
    {
    int d=0,count=SIZE-1;
    while(count!=-1)
        {
        if(*(c+count)=='1')
            {
            d+=pow(2,SIZE-count-1);
            }
        count--;
        }
    return d;
    }
int pow(int a,int b)
    {
    int r=1,i;
    if(b==0)
        return 1;
    for(i=1; i<=b; i++)
        r*=a;
    return r;
    }
void rComplement(char *c)
    {

    int count=strlen(c)-1;
    while((*(c+count))!='1')
        {
        count--;
        }
    count--;
    while(count!=-1)
        {
        if((*(c+count))=='1')
            *(c+count)='0';
        else
            *(c+count)='1';
        count--;
        }
    }
void binaryAdd(char *first,char *second,char *sum)
    {
    int count=SIZE-1,temp;
    char carry='0';
    *(sum+SIZE)='\0';
    while(count!=-1)
        {
        temp=(*(first+count)-'0')+(*(second+count)-'0')+carry-'0';
        if(temp<2)
            {
            *(sum+count)=temp+'0';
            carry='0';
            }
        else if(temp==2)
            {
            *(sum+count)='0';
            carry='1';
            }
        else
            {
            *(sum+count)='1';
            carry='1';
            }
        count--;
        }
    }
