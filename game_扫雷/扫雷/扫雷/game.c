#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void InitBoard(char board[ROWS][COLS],int rows,int cols,char c)
{
	int i=0;
	for(i=0;i<rows;i++)
	{
		int j=0;
		for(j=0;j<cols;j++)
		{
			board[i][j]=c;
		}
	}
}

void CreateMine(char board[ROWS][COLS],int row,int col,int mine_num)
{

	while(mine_num)
	{
		int x=rand()%9+1;

		int y=rand()%9+1;
		if(board[x][y]=='0')
		{
			board[x][y]='1';
		}
		else
		{
			continue;
		}
		mine_num--;
	}

}


void OutBoard(char board[ROWS][COLS],int row,int col)
{
	
	int i=1;
	int j=1;
	printf("---------扫雷--------\n");
	
		printf("    ");
		for(j=1;j<=col;j++)
		{
			printf("%d ",j);
		}
		printf("\n\n");
	for(i=1;i<=row;i++)
	{

		

		printf("%d   ",i);

		for(j=1;j<=col;j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");

	}
	printf("---------扫雷--------\n");
}

//返回0表示附近没有雷
//返回>0的数字表示附近的雷的数量
int GetPosAboutMindNum(char board[ROWS][COLS],int x,int y,int dir[][2],int len)
{
	int i=0;
	int count=0;
	int newx,newy;
	for(i=0;i<len;i++)
	{
		newx=x+dir[i][1];
		newy=y+dir[i][0];
		if(board[newy][newx]=='1')
		{
			count++;
		}
	}

	
	return count;

}

int GetPosAboutMindNum2(char board[ROWS][COLS],int x,int y)
{
	int i=-1,j=-1;
	int count=0;
	
	for(i=-1;i<2;i++)
	{
		for(j=-1;j<2;j++)
		{
		
			count+=board[y+j][x+i];
			
		}
	}

	
	return count-'0'*9;

}


void ScanMine(char board[ROWS][COLS],char show[ROWS][COLS],int x,int y,int row,int col)
{
	
	int ret=0;
	int i=0;
	int j=0;
	if(y<1||y>row||x<1||x>col)
	{
		return;
	}

	ret= GetPosAboutMindNum2(board,x,y);
	
	
	if(ret==0)
	{

		show[y][x]=' ';

		
		for(i=-1;i<2;i++)
		{
			for(j=-1;j<2;j++)
			{
				if(i==0&&j==0)
					continue;
			if(show[i+y][j+x]=='*')
			{
				ScanMine(board,show,x+j,y+i,row,col);
			}
			}
		}
			
			
	}

	
	else if(ret>0)
	{
		show[y][x]=(char)(ret+48);
	}
	

}

int PlayerInputRet(char board[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x,y;
	while(1)
	{
	
	scanf("%d %d",&x,&y);
	

	if(y>=1&&y<=row&&x>=1&&x<=col&&show[y][x]=='*')
	{
		if(board[y][x]=='1')
		{
			printf("你输了\n");
			return 2;
		
		}
		ScanMine(board,show,x,y,row,col);

		if(GetGameStatus(show,ROW,COL))
		{
			printf("你赢了\n");
			return 1;
		}

		return 0;
	}
	else
	{
		printf("坐标非法\n");
	}
		
	}
	
	
	return 0;
	
	
}


int GetGameStatus(char show[ROWS][COLS],int row,int col)
{

	int i=1,j=1,count=0;
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			if(show[i][j]=='*')
			{
				count++;
			}
		}
	}
	if(count==MINE)
	{
		return 1;
	}
	return 0;
}