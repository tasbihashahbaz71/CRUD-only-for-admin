#include <iostream>
#include <windows.h>
using namespace std;

const int ROWS = 10;
const int COLS = 20;

char maze[ROWS][COLS];

// FUNCTIONS

void delay();
void moveBackward();
void moveForward();
void drawMaze();
void createMaze();
void gotoXY(int x, int y);
char getCharacter(int x, int y);

int main()
{
    system("cls");

    createMaze();
    drawMaze();

    while (true)
    {
        moveForward();   
        moveBackward();  
    }

    return 0;
}


// Function to move cursor
void gotoXY(int x, int y)  
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/* Function to get character from maze */
char getCharacter(int x, int y)
{
    return maze[y][x];
}

/* Create the maze */
void createMaze()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
                maze[i][j] = '#';
            else
                maze[i][j] = ' ';
        } 
    }
}

/* Print maze */
void drawMaze()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

/* Delay function */
void delay()
{
    Sleep(150);
}

/* Move enemy forward */
void moveForward()        
{ 
    int x, y;

    for (y = 1; y < ROWS - 1; y++)
    {
        if (y % 2 == 1)
        {
            for (x = 1; x < COLS - 1; x++)
            {
                gotoXY(x, y);
                cout << 'P';
                delay();
                gotoXY(x, y);
                cout << ' ';
            }
        }
        else
        {
            for (x = COLS - 2; x > 0; x--)
            {
                gotoXY(x, y);
                cout << 'P';
                delay();
                gotoXY(x, y);
                cout << ' ';
            }
        }
    }
}

/* Move enemy backward */
void moveBackward()
{
    int x, y;

    for (y = ROWS - 2; y > 0; y--)
    {
        if (y % 2 == 1)
        {
            for (x = COLS - 2; x > 0; x--)
            {
                gotoXY(x, y);
                cout << 'P';
                delay();
                gotoXY(x, y);
                cout << ' ';
            }
        }
        else
        {
            for (x = 1; x < COLS - 1; x++)
            {
                gotoXY(x, y);
                cout << 'P';
                delay();
                gotoXY(x, y);
                cout << ' ';
            }
        }
    }
}
