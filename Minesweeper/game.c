#include "game.h"


void InitalBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= col; i++)
	{
		printf("%d ",i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++) {

			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

}

void FillMine(char board[ROWS][COLS],int row,int col)
{
	int count = MINE_COUNT;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}

int GetMineCounts(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y - 1]
		+ board[x - 1][y]
		+ board[x - 1][y + 1]
		+ board[x][y - 1]
		+ board[x][y + 1]
		+ board[x + 1][y - 1]
		+ board[x + 1][y]
		+ board[x + 1][y + 1] - 8 * '0';

}


void Spread(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	int count = GetMineCounts(mine, x, y);
	if (count != 0) 
	{
		show[x][y] = count + '0';
	}
	else
	{
		show[x][y] = '0';
		if (x  > 1 && show[x - 1][y] == '*')
		{
			Spread(mine, show, row, col, x - 1, y);
		}
		if (y  > 1 && show[x][y - 1] == '*')
		{
			Spread(mine, show, row, col, x, y-1);
		}
		if (y < col && show[x][y + 1] == '*')
		{
			Spread(mine, show, row, col, x, y + 1);
		}
		if (x < row && show[x + 1][y] == '*')
		{
			Spread(mine, show, row, col, x + 1, y);
		}
	}


}

int OpenNume(char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] != '*')
			{
				count++;
			}
		}
	}
	return count;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-MINE_COUNT)
	{
		printf("please input the indexs of position your choice:>");
		scanf("%d%d",&x,&y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) 
		{
			if (mine[x][y] == '1')
			{
				printf("regreted,this is a mine\n");
				DisplayBoard(mine,row,col);
				break;
			}
			else
			{
				Spread(mine,show,row,col,x,y);
				DisplayBoard(show,row,col);
			}
		

		}
		win = OpenNume(show,row,col);	
	}

	if (win == row * col - MINE_COUNT)
	{
		printf("Greate! Success");
		DisplayBoard(mine,row,col);
	}
}

