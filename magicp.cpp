#include<iostream>
#define MAXSIZE 12
#define MEX 10000
using namespace std;
int lencheck(int i);
int charcheck(char str[],int ind);
int setcheck(char str[],int ind);
int numcheck(char str[],int ind);
int capcheck(char str[],int ind);
int excheck(char str[],int ind);
struct magic{
                char str[MAXSIZE];
                int ind;
            };
int main()
{
    struct magic b[MEX];
    int i,t,l,m,j,z,d,e,f;
    cin>>t;                 //Enter the number of passwords you want to check
    for(i=0;i<t;i++)
        cin>>b[i].str;      //Enter all the passwords one by one
    for(i=0;i<t;i++)
    {
        f=0,l=0,m=0,z=0,d=0,e=0;
        b[i].ind=0;
        for(j=0;b[i].str[j]!='\0';j++)
           b[i].ind++;
        l=lencheck(b[i].ind);
        if(l==1)
           m=charcheck(b[i].str,b[i].ind);
        if(m==1)
           z=setcheck(b[i].str,b[i].ind);
        if(z==1)
           d=numcheck(b[i].str,b[i].ind);
        if(d==1)
           e=capcheck(b[i].str,b[i].ind);
        if(e==1)
           f=excheck(b[i].str,b[i].ind);
        if(f==1)
           cout<<"\t Success. \n";
    }
    return 0;
}
int lencheck(int i)
{
    if(i<6)
    {
        cout<<"\t Failure: Password must be at least 6 characters long. \n";
        return 0;
    }
    else if(i>12)
    {
        cout<<"\t Failure: Password must be at max 12 characters long. \n";
        return 0;
    }
    else
        return 1;
}
int charcheck(char str[],int ind)
{
    int i,c=0;
    for(i=0;i<ind;i++)
    {
        if(str[i]=='%'||str[i]=='!'||str[i]=='('||str[i]==')')
            c++;
    }
    if(c==0)
        return 1;
    else
    {
        cout<<"\t Failure: Password cannot contain %, !, (, ). \n";
        return 0;
    }
}
int setcheck(char str[],int ind)
{
    int i,c=0;
    for(i=0;i<ind;i++)
    {
            if(int(str[i])>64&&int(str[i])<91)
                c++;
    }
    if(c>0)
        return 1;
    else
    {
        cout<<"\t Failure: Password must contain atleast one letter from A-Z. \n";
        return 0;
    }
}
int numcheck(char str[],int ind)
{
    int i,c=0;
    for(i=0;i<ind;i++)
    {
            if(int(str[i])>47&&int(str[i])<58)
                c++;
    }
    if(c>0)
        return 1;
    else
    {
        cout<<"\t Failure: Password must contain atleast one letter from 0-9. \n";
        return 0;
    }
}
int capcheck(char str[],int ind)
{
    int i,c=0;
    for(i=0;i<ind;i++)
    {
            if(int(str[i])>96&&int(str[i])<123)
                c++;
    }
    if(c>0)
        return 1;
    else
    {
        cout<<"\t Failure: Password must contain atleast one letter from a-z. \n";
        return 0;
    }
}
int excheck(char str[],int ind)
{
    int i,c=0;
    for(i=0;i<ind;i++)
    {
            if(int(str[i])==95||int(str[i])==42||int(str[i])==36||int(str[i])==64||int(str[i])==35||int(str[i])==61)
                c++;
    }
    if(c>0)
        return 1;
    else
    {
        cout<<"\t Failure: Password must contain atleast one letter from *, @, $, #, _ or =. \n";
        return 0;
    }
}


