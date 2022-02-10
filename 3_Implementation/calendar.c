#include<stdio.h>

void print(int,int,int,int);
static char *months[]={"January","February",
"March","April","May","June","July","August",
"September","October","November","December"};

void main()
{
    int year,month;
    int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("enter the year(Example:2022):");
    scanf("%d",&year);
    printf("enter the month:(Example:(march as) 3)");
    scanf("%d",&month);
    int start=1;
    year=year-1;
    int nlp,nlpd,nlpr;
    //1600 is the leap year//
    nlp=year-1600;
    //nlpd is divided by 100//
    nlpd=nlp/100;
    if (nlpd==4||nlpd==8||nlpd==12||nlpd==16)
    {
        int nlpo=(nlpd*5)+1;
    }
    nlpr=nlp%100;
    // nlpo is no of odd in year//
    int nlpo=nlpd*5;
    int no_of_ly=nlpr/4;
    int no_of_oy=nlpr-no_of_ly;
    // a is declared for odd days//
    int a=(no_of_ly*2)*no_of_oy;
    int tod=nlpd+a;
    tod=tod%7;
    if(year+1%4==0)
    {
        mon[1]=29;

    }
    for(int i=0;i<=month-2;i++)
    {
        //tm=total month//
        int tm=tm+mon[i];
    }
    int tm= tm+start;
    //odd days nod//
    int nod=tm%7;
    // add tnod//
    int tnod=tod+nod;
    if (tnod>7)
    {
        tnod=tnod%7;
    }
    printf(year,month,mon[month-1],tnod*5);   
}
void printf(year,month,int td,int o)
{
    int i,b=o+20,c,r;
    gotoxy(28,6);
    printf("%s  %d",months[month-1],year+1);
    gotoxy(20,9);
    printf("sun  mon  thu  wed  thu  fri  sat");
    for(int i=1;i<=1;i++)
    {
        gotoxy(c,r);
        printf("%d",i);
        c=c+5;
        if(c>=55)
        {
            r=r+2;
            c=20;
        }
    }
}