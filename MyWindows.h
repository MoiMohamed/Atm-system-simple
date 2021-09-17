#include<stdio.h>
#include<windows.h>

COORD cord = {0,0};

void drawbox(int x,int y)
{
    ///first line
    printf("%c",201);
    for(int i = 1;i <= x-2;i++)printf("%c",205);
    printf("%c\n",187);

    ///rows
    for(int i = 1;i <= y-2;i++)
    {
        for(int j = 1;j <= x;j++)
        {
            if(j == 1 || j == x)
             printf("%c",186);
             else printf(" ");
        }
       printf("\n");
    }

    ///last line
    printf("%c",200);
    for(int i = 1;i <= x-2;i++)printf("%c",205);
    printf("%c",188);
}

void gotoxy(int x,int y)
{
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(hand,cord);
}

void showCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

    cursor.bVisible = 1;
    cursor.dwSize = sizeof(cursor);

    SetConsoleCursorInfo(hand,&cursor);
}

void hideCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

    cursor.bVisible = 0;
    cursor.dwSize = sizeof(cursor);

    SetConsoleCursorInfo(hand,&cursor);
}
