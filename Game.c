/*=============================================================================
  Author
	Ohno Takuya

  Create
	2017/6/6
=============================================================================*/
/*-----------------------------------------------------------------------------
	include
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"
#include "Game.h"

/*-----------------------------------------------------------------------------
	Macro
-----------------------------------------------------------------------------*/
#define MAP_WIDTH (50)/*MAP_Width*/
#define MAP_HEIGHT (23)/*MAP_Height*/
#define TIME (100)

typedef struct
{
	int x;
	int y;
}Vector2;

/*-----------------------------------------------------------------------------
	Global
-----------------------------------------------------------------------------*/
Vector2 g_PlayerPosition;
int g_Time;
char g_MAPdata[MAP_HEIGHT][MAP_WIDTH] = {
		"||G--------------------------------------------**",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"|| * * * * * * * * * * * * * * * * * * * * * * ||",
		"||                                             ||",
		"**---------------------------------------------**" };


int InitializeGame(void)
{
	g_PlayerPosition.x = 46;
	g_PlayerPosition.y = 21;

	g_Time = TIME;

	int x, z;
	int _random;
	/*上下左右に壁を出現*/
	for (z = 2;z < 21;z += 2)
	{
		for (x = 3;x < 46;x += 2)
		{
			_random = rand() % 4;
			if (_random == 0)/*左*/
			{
				g_MAPdata[z][x - 1] = '*';
			}
			else if (_random == 1)/*上*/
			{
				g_MAPdata[z - 1][x] = '*';
			}
			else if (_random == 2)/*下*/
			{
				g_MAPdata[z][x + 1] = '*';
			}
			else if (_random == 3)/*右*/
			{
				g_MAPdata[z + 1][x] = '*';
			}
		}
	}
}

int UpdateGame(void)
{
	
}

int DrawGame(void)
{
	int y;
	char key;/*移動処理に使う変数*/
	srand((unsigned)time(NULL));


	if (g_MAPdata[g_PlayerPosition.y][g_PlayerPosition.x] != 'G' && g_Time == 0)
	{
		ChangeMode(MODE_GAMEOVER);
		return 0;
	}
	else if(g_MAPdata[g_PlayerPosition.y][g_PlayerPosition.x] == 'G')
	{
		ChangeMode(MODE_CLEAR);
		return 0;
	}

	
	system("cls");
	g_MAPdata[g_PlayerPosition.y][g_PlayerPosition.x] = 'P';/*プレイヤーの表示*/

	/*マップ表示*/
	for (y = 0;y < MAP_HEIGHT;y++)
	{
		printf("%s", &g_MAPdata[y][0]);
		printf("\n");
	}

	/*移動処理*/
	printf("操作方法::←　→　↑　↓　 Ｇを目指せ！！　残りターン:%3d\n", g_Time);

	g_MAPdata[g_PlayerPosition.y][g_PlayerPosition.x] = ' ';/*座標更新*/

	key = _getch();/*キーの取得*/
	if (key == 72)/*↑キー*/
	{
		g_PlayerPosition.y--;
		g_Time--;
		/*壁との当たり判定*/
		if (g_MAPdata[g_PlayerPosition.y][g_PlayerPosition.x] == '*' || g_MAPdata[g_PlayerPosition.y][g_PlayerPosition.x] == '-')
		{
			g_PlayerPosition.y++;
			g_Time++;
		}
	}
	else if (key == 80)/*↓キー*/
	{
		g_PlayerPosition.y++;
		g_Time--;
		/*壁との当たり判定*/
		if (g_MAPdata[g_PlayerPosition.y][g_PlayerPosition.x] == '*' || g_MAPdata[g_PlayerPosition.x][g_PlayerPosition.x] == '-')
		{
			g_PlayerPosition.y--;
			g_Time++;
		}
	}
	else if (key == 75)/*←キー*/
	{
		g_PlayerPosition.x--;
		g_Time--;
		/*壁との当たり判定*/
		if (g_MAPdata[g_PlayerPosition.y][g_PlayerPosition.x] == '*' || g_MAPdata[g_PlayerPosition.y][g_PlayerPosition.x] == '|')
		{
			g_PlayerPosition.x++;
			g_Time++;
		}
	}
	else if (key == 77)/*→キー*/
	{
		g_PlayerPosition.x++;
		g_Time--;
		/*壁との当たり判定*/
		if (g_MAPdata[g_PlayerPosition.y][g_PlayerPosition.x] == '*' || g_MAPdata[g_PlayerPosition.y][g_PlayerPosition.x] == '|')
		{
			g_PlayerPosition.x--;
			g_Time++;
		}
	}
	
	return 0;
}