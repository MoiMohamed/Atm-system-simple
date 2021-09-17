#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include "MyWindows.h"

int x = 0;
int u;

struct user
{
  char user[13];
  char password[17];
  double balance;
};

struct user users[1000];

void tempelate();
int choose(char [],char [],int );
int create();
int login();
int deposit();
int withdraw();
void showdetails();
void getdata();
void save();
double scan_money();
void showMbox();
void hideMbox();
void typeMbox();

void main(void)
{
    int ch;
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

    system("COLOR 1F");


    while(1)
    {

    SetConsoleTextAttribute(hand,0x1F);

    ///GET DATA
    getdata();


    hideCursor();
    tempelate();

    while(1)
    {
        gotoxy(40,15);
        printf("                                      ");
        gotoxy(40,16);
        printf("                                      ");
        ch = choose("Create An Account   ","Use existing account",0);

        if(ch == 1)
        {
            if(create() == 0)
            {
                break;
            }
        }
        else
        {
            if(login() == 0)
                break;
        }
    }

    showdetails();
    hideCursor();

    while(1)
    {
        gotoxy(40,14);
        printf("                                      ");
        gotoxy(40,15);
        printf("                                      ");
        gotoxy(40,16);
        printf("                                      ");

        ch = choose("      Deposit       ","      Withdraw      ",1);
        if(ch == 1)
        {   if(deposit() == -1)
                continue;
        }
        else if(ch == 2)
        {
            if(withdraw() == -1)
                continue;
        }
        else
            break;

        save();

        gotoxy(41,14);
        printf("Would you like to do other transcent?");

        gotoxy(40,15);
        printf("                                       ");
        ch = choose("        YES         ","         NO         ",0);

        if(ch == 2)
            break;
    }


    ///write new data
    save();

    system("cls");

    }





    gotoxy(0,31);
}

void tempelate()
{
  drawbox(120,30);

  gotoxy(53,0);
  printf("%c",203);
  gotoxy(65,0);
  printf("%c",203);

  gotoxy(53,1);
  printf("%c Bank of C %c",186,186);

  gotoxy(53,2);
  printf("%c",200);
  for(int i = 0;i < 11;i++)printf("%c",205);
  printf("%c",188);

  ///first line
  gotoxy(39,10);printf("%c",201);
  for(int i = 1;i <= 39;i++) printf("%c",205);
  gotoxy(79,20);printf("%c",188);

  ///rows
    for(int i = 11;i <= 19;i++)
    {
        gotoxy(39,i);
        for(int j = 1;j <= 41;j++)
        {
            if(j == 1 || j == 41)
                printf("%c",186);
            else
                printf(" ");
        }

    }
  ///last line
  gotoxy(39,20);printf("%c",200);
  for(int i =1;i <= 39;i++)  printf("%c",205);
  gotoxy(79,10);printf("%c",187);


}

int choose(char a[80],char b[80],int no)
{
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
    int pos = 1;
    char get;

    gotoxy(55,18);printf("           ");
    for(;;)
    {
        SetConsoleTextAttribute(hand,0x1F);
        gotoxy(55,18);printf("           ");

        gotoxy(50,15);printf("%s",a);
        gotoxy(50,16);printf("%s",b);

        switch(pos)
        {
        case 1:SetConsoleTextAttribute(hand,0xF1);
               gotoxy(50,15);printf("%s",a);
            break;
        case 2: SetConsoleTextAttribute(hand,0xF1);
                gotoxy(50,16);printf("%s",b);
            break;
        }

        get = getch();
        if (get == -32) get = getch();

        if(get == 13)
        {
            SetConsoleTextAttribute(hand,0x1F);
            break;
        }
        if(get == 'H')
        {
            pos--;
            if(pos == 0)pos = 2;
        }

         if(get == 'P')
        {
            pos++;
            if(pos == 3)pos = 1;
        }

        if(get == 27 && no == 1)
            return 10;
    }
    return pos;
}

int create()
{
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
    char get;
    char user[13];
    char password[17];
    int pos = 1;
    int countp = 0;
    int countu = 0;
    int compc = 0;

    gotoxy(50,15);
    for(int i = 0; i <= 20;i++)printf(" ");
    gotoxy(50,16);
    for(int i = 0; i <= 20;i++)printf(" ");

    while(1)
    {

        SetConsoleTextAttribute(hand,0x1F);

        gotoxy(50,15);printf("Username:");
        gotoxy(50,16);printf("Password:");
        gotoxy(55,18);printf("Continue");


        switch(pos)
        {
        case 1:SetConsoleTextAttribute(hand,0xF1);
               gotoxy(50,15);printf("Username:");
            break;
        case 2: SetConsoleTextAttribute(hand,0xF1);
                gotoxy(50,16);printf("Password:");
            break;
        case 3:SetConsoleTextAttribute(hand,0xF1);
                gotoxy(55,18);printf("Continue");
                break;
        }
        SetConsoleTextAttribute(hand,0x1F);
        if(pos == 1)
        {
            while(1)
            {
                if((get = getch()) == -32)
                {
                    get = getch();

                    if(get == 'H')
                        pos = 3;

                    if(get == 'P')
                       pos = 2;


                    goto jump;
                }

                if(get == 27)
                {
                    hideMbox();
                    return 1;
                }

                gotoxy(59+countu,15);
                if(get == 8 && countu > 0)
                {

                    putch(8);
                    putch(' ');
                    putch(8);
                    countu--;
                    user[countu] = '\0';
                }
                else if(get != 8 && countu < 12 && get != 13)
                {
                    user[countu] = get;
                    countu++;
                    putch(get);
                }

            }
        }
        if(pos == 2)
        {
            while(1)
            {
                if((get = getch()) == -32)
                {
                    get = getch();

                    if(get == 'H')
                        pos = 1;

                    if(get == 'P')
                       pos = 3;

                    goto jump;
                }

                if(get == 27)
                {
                    hideMbox();
                    return 1;
                }

                gotoxy(59+countp,16);
                if(get == 8 && countp > 0)
                {

                    putch(8);
                    putch(' ');
                    putch(8);
                    countp--;
                    password[countp] = '\0';
                }
                else if(get != 8 && countp < 16 && get != 13)
                {
                    password[countp] = get;
                    countp++;
                    putch('*');
                }
            }
        }
        if(pos == 3)
        {
            while(1)
            {
                if((get = getch()) == 13 && countu > 2 && countp > 3)
                {
                    user[countu] = '\0';
                    password[countp] = '\0';

                    for(int i = 0;i < x;i++)
                    {
                        compc = 0;

                        if(strcmp(user,users[i].user) == 0)
                        {
                            compc = 1;
                            break;
                        }
                    }

                    if(compc == 0)
                    {
                        hideMbox();

                        strcpy(users[x].user,user);
                        strcpy(users[x].password,password);
                        users[x].balance = 0;

                        u = x;
                        x++;
                        goto jump2;
                    }
                    else
                    {
                        showMbox();
                        typeMbox("         REAPEATED USERNAME");
                    }
                }
                else if(get == 13)
                {
                    showMbox();
                    if(countp < 4)
                        typeMbox("PASSWORD MUST BE 4 CHARACHTERS OR MORE");
                    if(countu < 3)
                        typeMbox("USERNAME MUST BE 3 CHARACHTERS OR MORE");
                }

                if(get == 27)
                {
                    hideMbox();
                    return 1;
                }



                if(get == -32)
                {
                    get = getch();

                    if(get == 'H')
                    {
                        pos--;
                        if(pos == 0)pos = 3;
                    }

                    if(get == 'P')
                    {
                       pos++;
                       if(pos == 4)pos = 1;
                    }
                    goto jump;
                }
            }
        }


        jump:continue;

    }
        gotoxy(59,16);
        printf("                                ");

        jump2:gotoxy(0,1);
        return 0;

}

int login()
{

    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
    char get;
    int pos = 1;
    char user[13];
    char password[17];
    int countp = 0;
    int countu = 0;
    int compc = 0;

    gotoxy(50,15);
    for(int i = 0; i <= 20;i++)printf(" ");
    gotoxy(50,16);
    for(int i = 0; i <= 20;i++)printf(" ");

    while(1)
    {

        SetConsoleTextAttribute(hand,0x1F);

        gotoxy(50,15);printf("Username:");
        gotoxy(50,16);printf("Password:");
        gotoxy(55,18);printf("Continue");


        switch(pos)
        {
        case 1:SetConsoleTextAttribute(hand,0xF1);
               gotoxy(50,15);printf("Username:");
            break;
        case 2: SetConsoleTextAttribute(hand,0xF1);
                gotoxy(50,16);printf("Password:");
            break;
        case 3:SetConsoleTextAttribute(hand,0xF1);
                gotoxy(55,18);printf("Continue");
                break;
        }
        SetConsoleTextAttribute(hand,0x1F);
        if(pos == 1)
        {
            while(1)
            {
                if((get = getch()) == -32)
                {
                    get = getch();

                    if(get == 'H')
                        pos = 3;

                    if(get == 'P')
                       pos = 2;


                    goto jump;
                }

                if(get == 27)
                {
                    hideMbox();
                    return 1;
                }

                gotoxy(59+countu,15);
                if(get == 8 && countu > 0)
                {

                    putch(8);
                    putch(' ');
                    putch(8);
                    countu--;
                    user[countu] = '\0';
                }
                else if(get != 8 && countu < 12 && get != 13)
                {
                    user[countu] = get;
                    countu++;
                    putch(get);
                }

            }
        }
        if(pos == 2)
        {
            while(1)
            {
                if((get = getch()) == -32)
                {
                    get = getch();

                    if(get == 'H')
                        pos = 1;

                    if(get == 'P')
                       pos = 3;

                    goto jump;
                }

                if(get == 27)
                {
                    hideMbox();
                    return 1;
                }

                gotoxy(59+countp,16);
                if(get == 8 && countp > 0)
                {

                    putch(8);
                    putch(' ');
                    putch(8);
                    countp--;
                    password[countp] = '\0';
                }
                else if(get != 8 && countp < 16 && get != 13)
                {
                    password[countp] = get;
                    countp++;
                    putch('*');
                }
            }
        }
        if(pos == 3)
        {
            while(1)
            {
                if((get = getch()) == 13 && countu > 2 && countp > 3)
                {
                    user[countu] = '\0';
                    password[countp] = '\0';

                    for(int i = 0;i < x;i++)
                    {
                        compc = 0;

                        if(strcmp(user,users[i].user) == 0)
                            compc++;
                        if(strcmp(password,users[i].password) == 0)
                            compc++;

                        if(compc == 2)
                        {
                            u = i;
                            break;
                        }
                    }

                    if(compc == 2)
                    {
                        hideMbox();
                        goto jump2;
                    }
                    else
                    {
                        showMbox();
                        typeMbox("     WRONG USERNAME OR PASSWORD");
                    }

                }
                else if(get == 13)
                {
                    showMbox();
                    if(countp < 4)
                        typeMbox("PASSWORD MUST BE 4 CHARACHTERS OR MORE");
                    if(countu < 3)
                        typeMbox("USERNAME MUST BE 3 CHARACHTERS OR MORE");
                }

                if(get == 27)
                {
                    hideMbox();
                    return 1;
                }

                if(get == -32)
                {
                    get = getch();

                    if(get == 'H')
                    {
                        pos--;
                        if(pos == 0)pos = 3;
                    }

                    if(get == 'P')
                    {
                       pos++;
                       if(pos == 4)pos = 1;
                    }
                    goto jump;


                }
            }
        }


        jump:continue;

    }


        jump2:gotoxy(0,1);

        return 0;

}

int deposit()
{
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
    double get;
    char g;

    while(1)
    {

        gotoxy(50,16);
        printf("                      ");

        SetConsoleTextAttribute(hand,0xF1);
        gotoxy(57,18);
        printf("ENTER");

        SetConsoleTextAttribute(hand,0x1F);
        gotoxy(41,15);
        printf("ENTER AMOUNT TO DEPOSIT:              ");
        gotoxy(65,15);
        get = scan_money();

        if(get + users[u].balance <= 99999999999.99)
        {
            hideMbox();
            break;
        }
        else
        {
            showMbox();
            typeMbox("        BALANCE LIMIT EXCEEDED");
        }

    }

    if(get == -1)
    {
        hideMbox();
        return -1;
    }

    SetConsoleTextAttribute(hand,0xF1);
    gotoxy(57,18);
    printf("SURE?");
    SetConsoleTextAttribute(hand,0x1F);



    while(1)
    {
        if((g = getch()) == 13)
        {
            users[u].balance += get;
            break;
        }
    }

    showdetails();
}

int withdraw()
{
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
    double get;
    char g;

    gotoxy(50,16);
    printf("                    ");

    while(1)
    {
        SetConsoleTextAttribute(hand,0xF1);
        gotoxy(57,18);
        printf("ENTER");

        SetConsoleTextAttribute(hand,0x1F);
        gotoxy(40,15);
        printf("ENTER AMOUNT TO WITHDRAW:              ");
        gotoxy(65,15);
        get = scan_money();

         if(get == -1)
         {
            hideMbox();
            return -1;
         }

        if(get > users[u].balance)
        {
            showMbox();
            typeMbox("   YOU EXCEDEED THE BALANCE AMOUNT");
        }
        else
        {
            hideMbox();
            break;
        }

    }

    SetConsoleTextAttribute(hand,0xF1);
    gotoxy(57,18);
    printf("SURE?");
    SetConsoleTextAttribute(hand,0x1F);

    while(1)
    {
        if((g = getch()) == 13)
        {
            users[u].balance -= get;
            break;
        }
    }
    showdetails();

}

void showdetails()
{
    gotoxy(41,11);
    printf("Username:%s",users[u].user);
    gotoxy(41,12);
    printf("Balance:%.2lf",users[u].balance);

}

void getdata()
{
    FILE * ptr;

    ptr = fopen("Database.txt","rb");

    fscanf(ptr,"%d",&x);
    for(int i = 0;i < x;i++)
    fread(&users[i], sizeof(struct user), 1,ptr);
    fclose(ptr);
}

void save()
{
    FILE * ptr;

    ptr = fopen("Database.txt","wb");

    fprintf(ptr,"%d",x);
    for(int i = 0;i < x;i++)
    fwrite(&users[i], sizeof(struct user), 1,ptr);
    fclose(ptr);///
}

double scan_money()
{
    double num;

    char get;

    int count_int = 0;
    int count_dec = 0;
    int dot = 0;

    int dec = 0;
    long long in = 0;

    float deci = 0;

    while(1)
    {
      get = getch();


      if(get == 27)
        return -1;


      if(dot == 0)
      {
        if(get == 13 && count_int > 0)
            break;

        if(get >= 48 && get <= 57 && count_int < 11)
        {
            putch(get);

            if(count_int == 0)
            {
                in += (get - 48);
            }
            else
                in = in * 10 + (get - 48);

            count_int++;
        }

        if(get == 46)
        {
            putch(get);
            dot = 1;
        }

        if(get == 8 && count_int > 0)
        {
            putch(8);
            putch(' ');
            putch(8);

            in = in / 10;

            count_int--;
        }
    }

    if(dot == 1)
    {
        if(get == 13 && count_dec > 0)
            break;

        if(get >= 48 && get <= 57 && count_dec < 2)
        {
            putch(get);

            if(count_dec == 0)
            {
                dec += (get - 48);
            }
            else
                dec = dec * 10 + (get - 48);

            count_dec++;

        }

            if(get == 8)
            {
                if(count_dec > 0)
                {
                    putch(8);
                    putch(' ');
                    putch(8);

                    dec = dec / 10;

                    count_dec--;
                }
                else
                {
                    putch(8);
                    putch(' ');
                    putch(8);

                    dot = 0;
                }

            }
        }
    }

    if(count_dec == 1)
        deci = dec / 10.0;
    else
        deci = dec / 100.0;

    num = (double)in + deci;


    return num;
}

void showMbox()
{

    ///first line
    gotoxy(27,22);
    printf("MESSAGE BOX:");

    gotoxy(39,21);
    printf("%c" , 201);
    for(int i = 1;i <= 39;i++) printf("%c",205);
    gotoxy(79,21);printf("%c",187);

    ///rows
    for(int i = 22;i <= 22;i++)
    {
        gotoxy(39,i);
        for(int j = 1;j <= 41;j++)
        {
            if(j == 1 || j == 41)
                printf("%c",186);
            else
                printf(" ");
        }

    }
  ///last line
  gotoxy(39,23);printf("%c",200);
  for(int i =1;i <= 39;i++)  printf("%c",205);
  gotoxy(79,23);printf("%c",188);

}

void hideMbox()
{
    gotoxy(27,22);
    printf("                ");
    gotoxy(39,21);
    printf("                                                                 ");
    gotoxy(39,22);
    printf("                                                                 ");
    gotoxy(39,23);
    printf("                                                                 ");

}

void typeMbox(char s[])
{
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hand,0x1C);
    gotoxy(41,22);
    printf("%s",s);
    SetConsoleTextAttribute(hand,0x1F);
}
