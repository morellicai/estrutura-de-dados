/*
============ Source code ============
Link        : https://raw.githubusercontent.com/zoelabbb/conio.h/master/conio.h
GitHub      : https://github.com/zoelabbb/conio.h.git
=====================================
*/

/**
 * conio4linux (Conio.h for linux)
 * Copyright (C) 2013 by Alif Ryuu B R
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @author Alif Ryuu B R <zoelabbb@gmail.com>
 * @date 2023-12-21
 * @version 1.1
 */





// clreal -- Clear Line
// gotoxy -- Set Cursor Position
// clrscr -- Clear Screen




#ifndef __CONIO4LINUX_H
#define __CONIO4LINUX_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128


#ifdef __cplusplus
extern "C" {
#endif
/* Variáveis globais */
int background_color = 40;

/* Funções de controle do console */

void clreol(void)
{
    printf("\033[K");
}


void gotoxy(int x, int y)
{
    printf("\033[%d;%df", y, x);
}


void clrscr(void)
{
    printf("\033[%dm\033[2J\033[1;1f", background_color);
}


void textbackground(int color)
{
    background_color = (color % 16) + 40;
}


void textcolor(short color)
{
    if (color >= 0 && color < 16)
    {
        printf("\033[0;%d;%dm", 30 + color, background_color);
    }
}


int setEchoMode(bool enable)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ICANON;
    if (enable) newt.c_lflag |= ECHO;
    else newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}


int getch(void)
{
    return setEchoMode(false);
}


int getche(void)
{
    return setEchoMode(true);
}


int ungetch(int ch)
{
    return ungetc(ch, stdin);
}


int wherexy(int *x, int *y)
{
    printf("\033[6n");
    if (getch() != '\x1B') return 0;
    if (getch() != '\x5B') return 0;
    int in;
    int ly = 0;
    while ((in = getch()) != ';')
        ly = ly * 10 + in - '0';
    int lx = 0;
    while ((in = getch()) != 'R')
        lx = lx * 10 + in - '0';
    *x = lx;
    *y = ly;
}



int wherex(void)
{
    int x = 0, y =0;
    wherexy(&x, &y);
    return x;
}


int wherey(void)
{
    int x = 0, y = 0;
    wherexy(&x, &y);
    return y;
}




/* Funções de entrada/saída */


int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}


int putch(int c)
{
    printf("%c", c);
    return c;
}


int putchar(int c)
{
    return putch(c);
}


int cputs(const char *str)
{
    printf("%s", str);
    return 0;
}


int cprintf(const char *format, ...)
{
    va_list args;
    int result;
    va_start(args, format);
    result = vprintf(format, args);
    va_end(args);
    return result;
}


int cscanf(const char *format, ...)
{
    va_list args;
    int result;
    va_start(args, format);
    result = vscanf(format, args);
    va_end(args);
    return result;
}

/* Funções compatibilidade Dev C++ */
#define _cprintf cprintf
#define _cscanf cscanf
#define _cputs cputs
#define _getche getche
#define _kbhit kbhit
#define _putch putch
#define _ungetch ungetch

#ifdef __cplusplus
}
#endif

#endif /* __CONIO4LINUX_H */
