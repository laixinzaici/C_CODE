#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS (ROW+2)
#define COLS (COL+2)
#define MINE 10
void InitBoard(char board[ROWS][COLS],int rows,int cols,char c);
void OutBoard(char board[ROWS][COLS],int row,int col);
void CreateMine(char board[ROWS][COLS],int row,int col,int mine_num);
//踩到雷返回0,没有返回1
int PlayerInputRet(char board[ROWS][COLS],char show[ROWS][COLS],int row,int col);
void ScanMine(char board[ROWS][COLS],char show[ROWS][COLS],int x,int y,int row,int col);

//获取游戏状态，胜利返回1，正在游戏返回0
int GetGameStatus(char show[ROWS][COLS],int row,int col);
