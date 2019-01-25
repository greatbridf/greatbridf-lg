// Hi-accurancy division
// Not recommanded
#include<bits/stdc++.h>
#define MAIN 110
int compare(int a[],int b[],int lena,int lenb)
{
    int flag;
    if(lena<lenb) flag=0;
    else if(lena>lenb) flag=1;
    else
    {
        int i=lena,judge=0;
        while(!judge&&i>0)
        {
            if(a[i]>b[i])
            {
                judge=1;
                flag=1;
            }
            else if(a[i]==b[i]) i--;
            else
            {
                judge=1;
                flag=0;
            }
        }
        if(i==0&&judge==0) flag=2;
    }
    return flag;
}
int subtraction(int a[],int b[],int lena,int lenb)
{
    int len,d[MAIN];
    for(int i=0; i<MAIN; i++)
    {
        if(i<lenb) d[i]=b[i];
        else d[i]=0;
    }
    len=lena-lenb-1;
    if(len<0) len=0;
    if(len>0)
    {
        for(int i=lenb-1; i>=0; i--)
            d[i+len]=d[i];
        for(int i=0; i<len; i++)
            d[i]=0;
    }
    for(int i=0; i<lena; i++)
    {
        if(a[i]>=d[i]) a[i]-=d[i];
        else a[i+1]=a[i+1]-1,a[i]=10+a[i]-d[i];
    }
    return len;
}
int main()
{
    int  a[MAIN]= {},b[MAIN]= {},c[MAIN]= {},d[MAIN]= {};

    int    t,  kk;
    char  a1[MAIN], b1[MAIN];

    scanf("%s", a1);
    int lena = strlen(a1);
    for(int i=0; i<lena; i++)
        a[i]=a1[lena-i-1]-'0';

    scanf("%s", b1);
    int lenb = strlen(b1);
    for(int i=0; i<lenb; i++)
        b[i]=b1[lenb-i-1]-'0';
    int lend=lena;
    int num=0,tmp_flag;
    do
    {
        while(!a[lena-1]) lena--;
        tmp_flag=compare(a,b,lena,lenb);
        if(tmp_flag>=1)
        {
            int len=subtraction(a,b,lena,lenb);
            c[len]++;
            if(len>num) num=len;
            int tmp1=0;
            for(int i=len; i<=num; i++)
            {
                int tmp=c[i]+tmp1;
                c[i]=tmp%10;
                tmp1=tmp/10;
            }
            if(tmp1>0)
            {
                num++;
                c[num]=tmp1;
            }
        }
    } while(tmp_flag==1);
    int flag2=compare(a,b,lena,lenb);
    if(!flag2)
    {
        printf("0 ");
        for(int i=lend-1; i>=0; i--)
            printf(" %d",a[i]);
        return 0;
    }
    if(flag2==2)
    {
        printf("1 0");
        return 0;
    }
    int lenk=lend;
    while(!c[lend-1]) lend--;

    for(int i = lend-1; i>=0; i--)
        printf("%d",c[i]);

    while(!a[lenk]) lenk--;
    if(lenk<0)
    {
        printf(" 0");
        return 0;
    }
    for(int i=lenk; i>=0; i--)
        printf(" %d",a[i]);
    return 0;
}
