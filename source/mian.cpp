#include<stdio.h>
#include <ctype.h>
#include<stdlib.h>
#include"tool.h"
#include"func.h"
#include <iostream>
#include<time.h>
#include<windows.h>
#include <conio.h>
int main()
{
    char ans='Y';
    int x=61,y=25;
    srand(time(0));
    system("color f0");

    my_name();//打名字

    gotoxy(0,2);
    SetColor(12);
    printf("Game Instroction\n\n");
    SetColor(8);
    game_instroction();//遊戲簡介

    end_game(0,23);

    while(toupper(ans)=='Y')
    {
        int Score=0,maxcomb=0,rightdir=0,d=0,p=0;//計分用
        system("cls");
        system("color f0");
        game_star();
        system("cls");//準備遊戲開始
        game_space(x,y);//遊戲介面

        SetColor(9);
        Counttime(5,30,11);//倒數五秒遊戲開始

        int T=60;//秒數
        time_t START,END;
        int a[9999]= {0};//時間
        int arr1[7]= {}; //存木塊的陣列
        START=time(NULL);
        END=time(NULL);
        for(int i=1; i<9999; i++)
        {
            a[i]=i;
        }
        Sleep(998);

        for(int i=0; i<7; i++)//放木塊進陣列
        {
            gotoxy(15,11+i*2);
            put_block(i,arr1);
        }

        int b[2]= {0};
        next_block(b,arr1,&p);//要敲的木塊

        int x=12,y=23;
        hammer(&x,&y,&d);//放槌子

        char ch1='\0', ch2='0';
        int comb=0;

        while(END-START<T)
        {
            //計時
            END=time(NULL);
            for(int i=1; i<T+1; i++)//倒數
            {
                if(END-START==a[i])
                {
                    gotoxy(3,2);
                    SetColor(9);
                    printf("%2d",T-i);
                    break;
                }
            }

            ch1=getch();
            key_direction(ch1,ch2,&x,&y,&d);//方向控制

            if(nock(ch1,x,&y,arr1,b,&T,&p)==1)//敲木塊+計comb
            {
                if(d==p)rightdir++;//方向正確++
                comb++;
                Score++;
                gotoxy(3,6);
                SetColor(12);
                printf("%2d",comb);
            }
            else if(ch1==' ')//敲錯comb歸零
            {
                if(comb>maxcomb)maxcomb=comb;//紀錄最大comb
                comb=0;
                gotoxy(3,6);
                SetColor(12);
                printf("%2d",comb);
            }
            p=0;
        }
        if(comb>maxcomb)maxcomb=comb;//沒敲錯時的最大comb

        system("cls");
        gotoxy(20,11);
        SetColor(0);
        printf("遊戲結束 ");
        Sleep(300);
        system("pause");
        system("cls");

        printf("\n  *得分*\n"
               "        最大comb數 %2d\n"
               "        擊破數     %2d\n"
               "        方向加分   %2d x 2\n"
               "        合計總分   %2d\n",maxcomb,Score,rightdir,maxcomb+Score+rightdir*2);
        printf("\n\n   再玩一次?(Y/N)...>");
        ans=getchar();
        while(toupper(ans)!='Y'&&toupper(ans)!='N'){ans=getchar();}
        if(toupper(ans)=='N')break;
    }
    return 0;
}
