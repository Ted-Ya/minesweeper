
#include "game.h"

void manu()
{
	printf("**************************\n");
	printf("**** 1.play 0.exit *******\n");
	printf("**************************\n");
}

void play()
{
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};

	InitalBoard(mine,ROWS,COLS,'0');
	InitalBoard(show, ROWS, COLS, '*');

	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	FillMine(mine,ROW,COL);
	/*DisplayBoard(mine, ROW, COL);*/

	FindMine(mine,show,ROW,COL);

}

void game()
{
   
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{   
		manu();
		printf("please input your selection:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			play();
			break;
		case 0:
			printf("exiting gaming\n");
			break;

		default:
			printf("no this option,please re-selection\n");
			break;
		}
	} while (input);
	
}

int main()
{

	game();
	return 0;
}