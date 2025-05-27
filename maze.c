#include "maze.h"

int main()
{
	initscr();
	echo();

	srand((unsigned int)time(NULL));
	
	input();
	maze();
	getch();

	endwin();
	system("clear");
	return 0;
}

void input()
{
	int tmp_col, tmp_row;
	printw("input col: ");
	scanw("%d", &tmp_col);
	col = 1 + 2 * tmp_col;
	printw("input row: ");
	scanw("%d", &tmp_row);
	row = 1 + 2 * tmp_row;

	return;
}

void maze()
{
	//°ÑÇ½±ÚÐ´ÈëÊý×é
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (!(i % 2) && !(j % 2)) { maze_a[i][j] = '+'; }
			else if (!(i % 2) && j % 2) { maze_a[i][j] = '-'; }
			else if (i % 2 && !(j % 2)) { maze_a[i][j] = '|'; }
			else { maze_a[i][j] = ' '; }
		}
	}

	//Ëæ»úÉ¾³ýÃ¿Ò»ÅÅµÄÊúÇ½±Ú
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			int cat = rand() % 2;
			if (cat && maze_a[i][j] == '|' && j != 0 && j != row - 1)
			{
				maze_a[i][j] = ' ';
			}
		}
	}

	////¸ù¾ÝÊúÇ½±ÚÉ¾³ýºáÇ½±Ú
	//for (int i = 1; i < col - 2; i++)
	//{
	//	bool the_cat = false;
	//	for (int j = 1; j < row; j++)
	//	{
	//		int tmp_cat = rand() % 5;
	//		if (maze_a[i][j] == '|' && !the_cat)
	//		{
	//			maze_a[i + 1][j - 1] = ' ';
	//		}
	//		/*else if (!tmp_cat && maze_a[i][j] == '-')
	//		{
	//			maze_a[i][j] = ' ';
	//			the_cat = true;
	//		}*/
	//		
	//	}
	//}

	//	////¸ù¾ÝÊúÇ½±ÚÉ¾³ýºáÇ½±Únew
	for (int i = 1; i < col - 2; i++)
	{
		bool the_cat = false;
		for (int j = 1 ; j < row; j++)
		{
			int tmp_cat = rand() % 5;
			
			if (maze_a[i][j] == '|' && !the_cat)
			{
				maze_a[i + 1][j - 1] = ' ';
			}
			else if (!tmp_cat && i % 2 == 1 && j % 2 == 0 && !the_cat)
			{
				the_cat = true;
				maze_a[i + 1][j - 1] = ' ';
			}
			if (maze_a[i][j] == '|')
			{
				the_cat = false;
			}
		}
	}

	//Ö±½ÓÉ¾³ý×îºóÒ»ÅÅÊúÇ½±Ú
	for (int j = 1; j < row - 1; j++)
	{
		//int rand_cat = rand() % 2;
		if (maze_a[col -2][j] == '|')
		{
			maze_a[col - 2][j] = ' ';
		}
	}

	print_maze();
	return;
}

void print_maze()
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printw("%c ", maze_a[i][j]);
		}
		printw("\n");
	}

	return;
}