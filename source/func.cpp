#include<windows.h>
#include<stdio.h>

int randon(int a,int b)
{
    return rand()%(b-a+1)+a;
}
void gotoxy(int x, int  y)
{
        COORD point;
        point.X = x, point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void SetColor(int color=-1)
{
        switch (color)
        {
        case 0:    // White on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_RED |
                        FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
        case 1:    // Red on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_RED);
                break;
        case 2:    // Green on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                break;
        case 3:    // Yellow on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_RED |
                        FOREGROUND_GREEN);
                break;
        case 4:    // Blue on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                break;
        case 5:    // Magenta on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_RED |
                        FOREGROUND_BLUE);
                break;
        case 6:    // Cyan on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                        FOREGROUND_BLUE);
                break;
        case 7:    // Black on Gray
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | BACKGROUND_INTENSITY);
                break;
        case 8:    // Black on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE);
                break;
        case 9:    // Red on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE |
                        FOREGROUND_RED);
                break;
        case 10:    // Green on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_GREEN);
                break;
        case 11:    // Yellow on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_RED |
                        FOREGROUND_GREEN);
                break;
        case 12:    // Blue on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_BLUE);
                break;
        case 13:    // Magenta on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_RED |
                        FOREGROUND_BLUE);
                break;
        case 14:    // Cyan on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_GREEN |
                        FOREGROUND_BLUE);
                break;
        case 15:    // White on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_RED |
                        FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
        case 16:    // Gray on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE);
                break;
        default :    // White on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_RED |
                        FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
        }
}
void game_space(int x,int y)
{
    SetColor(0);
    for(int i=0; i<x; i++)
    {
        printf("-");
    }
    for(int i=0; i<=y; i++)
    {
        gotoxy(0,i);
        printf("|");
        gotoxy(x,i);
        printf("|");
    }
    gotoxy(0,y);
    for(int i=0; i<x; i++)
    {
        printf("-");
    }

    gotoxy(2,1);
    SetColor(1);
    printf("TIME");
    SetColor(0);
    gotoxy(1,4);
    for(int i=0; i<8; i++)
    {
        printf("-");
    }
    for(int i=1; i<=4; i++)
    {
        gotoxy(8,i);
        printf("|");
    }

    gotoxy(2,5);
    SetColor(3);
    printf("COMBE");
    SetColor(0);
    gotoxy(1,8);
    for(int i=0; i<8; i++)
    {
        printf("-");
    }
    for(int i=5; i<=8; i++)
    {
        gotoxy(8,i);
        printf("|");
    }

    gotoxy(x-25,4);
    for(int i=0; i<25; i++)
    {
        printf("-");
    }
    for(int i=1; i<=4; i++)
    {
        gotoxy(x-25,i);
        printf("|");
    }

    gotoxy(x-14,5);
    SetColor(5);
    printf("NEXT");
    SetColor(0);
    gotoxy(x-25,8);
    for(int i=0; i<25; i++)
    {
        printf("-");
    }
    for(int i=5; i<=8; i++)
    {
        gotoxy(x-25,i);
        printf("|");
    }

}

