#include<time.h>
#include<stdio.h>
#include<windows.h>
#include <iostream>
#include <conio.h>
#include"func.h"
using namespace std;
int Counttime(int T,int x,int y)
{
    time_t START,END;
    int a[T+1][2]= {0};
    for(int i=1; i<T+1; i++)
    {
        a[i][0]=i;
    }
    START=time(NULL);
    END=time(NULL);
    while(END-START!=T)
    {
        END=time(NULL);
        for(int i=1; i<T+1; i++)
        {
            if(END-START==a[i][0]&&a[i][1]==0)
            {
                gotoxy(x,y);
                printf("%2d",T-i);
                a[i][1]=1;
                break;
            }
        }
    }
    return 0;
}
void my_name()
{
    SetColor(16);
    printf("40541204S 物二乙 梁湘梅    ");
    char s2[]="敲木塊小遊戲";
    SetColor(3);
    for(int i = 0; i < (sizeof(s2)/sizeof(s2[0])); i++)
    {
        if(s2[i] == '\0')
            cout << "\n";
        else
        {
            cout << s2[i];
            Sleep(100);
        }
    }
    cout << endl;

}
void game_instroction()
{
    Sleep(700);
    gotoxy(2,3);
    printf("總共會有6種不同顏色的普通木塊和2個特殊木塊\n\n  |_\n\n  |_");
    Sleep(700);
    SetColor(10);
    gotoxy(4,5);
    printf("特殊木塊A--時間+10秒\n");
    Sleep(700);
    gotoxy(4,7);
    printf("特殊木塊B--木塊變成單一顏色,一次\n");
    Sleep(700);
    SetColor(8);
    gotoxy(2,9);
    printf("遊戲時間限制1min，顯示在左上角\n\n  |_");
    Sleep(700);
    gotoxy(4,11);
    SetColor(9);
    printf("需有鍵盤上的操作才會顯示剩餘時間");
    Sleep(700);
    SetColor(8);
    gotoxy(2,13);
    printf("遊戲開始時，會有7個木塊疊高在一起\n");
    Sleep(700);
    gotoxy(2,15);
    printf("介面右上角會出現這次&下次要你敲掉的木塊(有時會因為同色木塊剩餘太少而換色)\n");
    Sleep(700);
    SetColor(9);
    gotoxy(2,17);
    printf("使用「上下鍵移動」至指定顏色的木塊旁按下「空白鍵敲擊」");
    Sleep(700);
    gotoxy(2,19);
    printf("有時會出現需從左邊右邊敲擊的指示(不強制，做加分用)可使用「左右鍵移動」至木塊左右兩邊敲擊");
    Sleep(700);
    SetColor(8);
    gotoxy(2,21);
    printf("有累計comb，敲錯木塊comb歸零，最大comb數顯示在左上角(時間下方)\n");
    Sleep(300);
}
void end_game(int x,int y)
{
    SetColor(16);
    gotoxy(x,y);
    system("pause");
}
void game_star()
{
    system("color f0");
    gotoxy(5,5);

    char s1[] = "GAME STAR ! ~ ~ ~";
    for(int i = 0; i < (sizeof(s1)/sizeof(s1[0])); i++)
    {
        cout << s1[i];
        Sleep(250);
    }
    Sleep(300);
}
void game_block(int n)
{
    switch(n)
    {
    case 0:
        SetColor(9);
        printf("███████████\n");
        break;
    case 1:
        SetColor(14);
        printf("███████████\n");
        break;
    case 2:
        SetColor(10);
        printf("███████████\n");
        break;
    case 3:
        SetColor(12);
        printf("███████████\n");
        break;
    case 4:
        SetColor(11);
        printf("███████████\n");
        break;
    case 5:
        SetColor(13);
        printf("███████████\n");
        break;
    case 6:
        SetColor(16);
        printf("█A██A█A█A█A█A█\n");//+10s
        break;
    case 7:
        SetColor(8);
        printf("█B██B█B█B█B█B█\n");//換色
        break;
    }
}
void put_block(int i,int arr[])
{
    arr[i]=randon(0,7);
    if((arr[i]==6||arr[i]==7)&&randon(0,5)>=1)
    {
        arr[i]=randon(0,5);
        game_block(arr[i]);
    }
    else
        game_block(arr[i]);
}
void hammer(int *x,int *y,int *d)
{
    gotoxy(*x,*y);
    SetColor(8);
    if(*x==12)
    {
        printf("=>");
        *d=1;
    }
    if(*x==38)
    {
        printf("<=");
        *d=2;
    }
}
void key_direction(char ch1,char ch2,int *x,int *y,int *d)
{
    if(ch1 == -32)
    {
        ch2 = getch();
        if(ch2 == 72)
        {
            gotoxy(*x,*y);
            printf("   ");
            *y-=2;
            if(*y<11)*y=11;
            hammer(x,y,d);
        }
        if(ch2 == 75)
        {
            gotoxy(*x,*y);
            printf("   ");
            *x=12;
            hammer(x,y,d);
        }
        if(ch2 == 77)
        {
            gotoxy(*x,*y);
            printf("   ");
            *x=38;
            hammer(x,y,d);
        }
        if(ch2 == 80)
        {
            gotoxy(*x,*y);
            printf("   ");
            *y+=2;
            if(*y>23)*y=23;
            hammer(x,y,d);
        }
    }
}
void next_block(int b[],const int arr[],int *p)
{
    int n=0;
    b[0]=b[1];
    b[1]=randon(0,6);
    while(b[0]==b[1]||arr[b[0]]==6||arr[b[0]]==7||arr[b[1]]==6||arr[b[1]]==7||(arr[b[0]]==arr[b[1]]&&n<7))
    {
        b[1]=randon(0,6);
        for(int i=0; i<2; i++)
        {
            while(arr[b[i]]==6||arr[b[i]]==7)
            {
                b[i]=randon(0,6);
            }
        }
        if(arr[b[0]]==arr[b[1]])
        {
            b[1]=randon(0,6);
            n++;
        }
    }
    for(int i=0; i<2; i++)
    {
        if(i==0)gotoxy(38,2);//這次
        if(i==1)gotoxy(38,6);//下次
        game_block(arr[b[i]]);
    }
    if(randon(0,6)>4)//方向
    {
        gotoxy(46,3);
        SetColor(8);
        if(randon(0,1)==1){printf("=>");*p=1;}
        else {printf("<=");*p=2;}
    }
    else
    {
        gotoxy(45,3);
        printf("   ");
    }
}

int nock(char ch1,int x,int *y,int arr[],int b[],int *t,int *p)
{
    if(ch1==' '&& arr[b[0]]==arr[(*y-11)/2])
    {
        gotoxy(15,*y);
        put_block((*y-11)/2,arr);//放新木塊
        next_block(b,arr,p);
        return 1;
    }
    if(ch1==' '&&arr[(*y-11)/2]==6)//特A+10s
    {
        *t+=10;
        gotoxy(15,*y);
        put_block((*y-11)/2,arr);//放新木塊
        return 1;
    }
    if(ch1==' '&& arr[(*y-11)/2]==7)//特B單色
    {
        int q=randon(0,5);
        for(int i=0; i<7; i++)
        {
            arr[i]=q;
            gotoxy(15,11+i*2);
            game_block(arr[i]);
        }//放同色木塊
        next_block(b,arr,p);
        return 1;
    }
    return 0;
}

