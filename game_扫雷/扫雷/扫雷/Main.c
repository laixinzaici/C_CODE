#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//这是服务器文件111
void Menu()
{
	printf("---------------------------\n");
	printf("--------  0.exit  ---------\n");
	printf("--------  1.play  ---------\n");
	printf("--------  2.clear ---------\n");
	printf("---------------------------\n");

}
void game()
{
	char board[ROWS][COLS];
	char show[ROWS][COLS];
		int dir[][2]={{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,-1},{-1,1},{1,1}};
	int len=sizeof(dir)/sizeof(dir[0]);
	int inputx,inputy;
	InitBoard(board,ROWS,COLS,'0');
	
	InitBoard(show,ROWS,COLS,'*');
	CreateMine(board,ROW,COL,MINE);
	

	

	while(1)
	{

		//OutBoard(board,ROW,COL);

	 OutBoard(show,ROW,COL);




	if(PlayerInputRet(board,show,ROW,COL))
	{
		break;
	}
	
	

	

	}
	
}

int main()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("请选择->");
		
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		case 2:
			 system("cls");
			 break;
		default:
			printf("选择错误\n");
			break;
		}
	}
	while(input);
	getchar();
	return 0;
}
