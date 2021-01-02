#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}
void a(int x)
{
    int hour,minutes;
    while(1)
    {
        printf("Enter alarm HOURs in 24 formet:");
        scanf("%d",&hour);
        printf("\nEnter alarm Minutes:");
        scanf("%d",&minutes);
        printf("\nalarm set successfully\n");
        printf("\n");
        system("cls");
        save(hour,minutes);
        break;
    }
}
void pri(int a,int x,int y)
{
    if(a==0)
    {
        gotoxy(x,y);
        printf("****");
        gotoxy(x,y+1);
        printf("*  *");
        gotoxy(x,y+2);
        printf("*  *");
        gotoxy(x,y+3);
        printf("*  *");
        gotoxy(x,y+4);
        printf("****");
    }
    else if(a==1)
    {
        gotoxy(x,y);
        printf("   *");
        gotoxy(x,y+1);
        printf("   *");
        gotoxy(x,y+2);
        printf("   *");
        gotoxy(x,y+3);
        printf("   *");
        gotoxy(x,y+4);
        printf("   *");
    }
    else if(a==2)
    {
        gotoxy(x,y);
        printf("****");
        gotoxy(x,y+1);
        printf("   *");
        gotoxy(x,y+2);
        printf("****");
        gotoxy(x,y+3);
        printf("*   ");
        gotoxy(x,y+4);
        printf("****");
    }
    else if(a==3)
    {
        gotoxy(x,y);
        printf("****");
        gotoxy(x,y+1);
        printf("   *");
        gotoxy(x,y+2);
        printf("****");
        gotoxy(x,y+3);
        printf("   *");
        gotoxy(x,y+4);
        printf("****");
    }
    else if(a==4)
    {
        gotoxy(x,y);
        printf("*  *");
        gotoxy(x,y+1);
        printf("*  *");
        gotoxy(x,y+2);
        printf("****");
        gotoxy(x,y+3);
        printf("   *");
        gotoxy(x,y+4);
        printf("   *");
    }
    else if(a==5)
    {
        gotoxy(x,y);
        printf("****");
        gotoxy(x,y+1);
        printf("*   ");
        gotoxy(x,y+2);
        printf("****");
        gotoxy(x,y+3);
        printf("   *");
        gotoxy(x,y+4);
        printf("****");
    }
    else if(a==6)
    {
        gotoxy(x,y);
        printf("****");
        gotoxy(x,y+1);
        printf("*   ");
        gotoxy(x,y+2);
        printf("****");
        gotoxy(x,y+3);
        printf("*  *");
        gotoxy(x,y+4);
        printf("****");
    }
    else if(a==7)
    {
        gotoxy(x,y);
        printf("****");
        gotoxy(x,y+1);
        printf("   *");
        gotoxy(x,y+2);
        printf("   *");
        gotoxy(x,y+3);
        printf("   *");
        gotoxy(x,y+4);
        printf("   *");
    }
    else if(a==8)
    {
        gotoxy(x,y);
        printf("****");
        gotoxy(x,y+1);
        printf("*  *");
        gotoxy(x,y+2);
        printf("****");
        gotoxy(x,y+3);
        printf("*  *");
        gotoxy(x,y+4);
        printf("****");
    }
    else if(a==9)
    {
        gotoxy(x,y);
        printf("****");
        gotoxy(x,y+1);
        printf("*  *");
        gotoxy(x,y+2);
        printf("****");
        gotoxy(x,y+3);
        printf("   *");
        gotoxy(x,y+4);
        printf("****");
    }
}
void pos(int a,int x,int y)
{
    int c,d;
    c=a/10;
    d=a%10;
    pri(c,x,y);
    pri(d,x+=5,y);

}
void save(int h,int m)
{
    FILE *db;
    db = fopen("savetime.txt","w");
    fprintf(db,"%d\n%d",h,m);
    fclose(db);

}
int hour(int x)
{
    int h,m;
    FILE *db;
    db = fopen("savetime.txt","r");
    fscanf(db,"%d\n%d",&h,&m);
    fclose(db);
    return h;
}
int mint(int y)
{
    int h,m;
    FILE *db;
    db = fopen("savetime.txt","r");
    fscanf(db,"%d\n%d",&h,&m);
    fclose(db);
    return m;
}
int main()
{
    char buf[150];
    time_t curtime;
    struct tm* loc_time;
    strftime (buf, 150, "%A\n", loc_time);
    gotoxy(3,0);
    fputs (buf, stdout);
    gotoxy(24,0);
    printf("%s",__DATE__);
    time_t t;
    struct tm* current_time;
    t=time(NULL);
    current_time=localtime(&t);
    time(&t);
    int h=0,m=0,s=0,x=5,y=5,yes=1,hr,min,g=0,k=0;
    char st[10];
    h=current_time->tm_hour;
    m=current_time->tm_min;
    s=current_time->tm_sec;
    while(1)
    {
        sleep(1);
        x=5, y=5;
        //00:00:00
        s++;
        if(s==60)
        {
            s=0;
            m++;
        }
        else if(m==60)
        {
            m=0;
            h++;
        }
        else if(h==24)
        {
            s=0;
            m=0;
            h=0;
        }
        if(yes!=0)
        {

            gotoxy(0,10);
            printf("\npress 1 to set alarm");
            printf("\npress 0 to continue\nenter key=");
            scanf("%d",&yes);

            if(yes==1)
            {
                a(yes);
                yes=0;
            }
        }

        hr=hour(g);
        min=mint(k);
        pos(h,x,y);
        x+=13;
        gotoxy(x,y);
        pos(m,x,y);
        x+=13;
        pos(s,x,y);
        printf("\n");
        gotoxy(0,20);
        printf("\n\nalarm=%d:%d",hr,min);
        time(&t);
        current_time=localtime(&t);
        if(hr==current_time->tm_hour & min== current_time->tm_min)
        {
            sleep(0.02);
            gotoxy(100,0);
            printf("\nTime MATCH FOUND\n");
            printf("\a");
        }

    }
}
