/*=============================================================================
  Author
	Ohno Takuya

  Create
	2017/6/6
=============================================================================*/
/*-----------------------------------------------------------------------------
	Include
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"
#include "Player.h"
#include "Game.h"

/*-----------------------------------------------------------------------------
	Macro
-----------------------------------------------------------------------------*/
#define MAP_WIDTH (50)/*MAP_Width*/
#define MAP_HEIGHT (23)/*MAP_Height*/
#define TIME (100)

/*-----------------------------------------------------------------------------
	Function
-----------------------------------------------------------------------------*/
void Goal(void);

/*-----------------------------------------------------------------------------
	Global
-----------------------------------------------------------------------------*/
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


void InitializeGame(void)
{
	srand((unsigned)time(NULL));

	g_Time = TIME;

	InitializePlayer();

	int x, z;
	int _random;
	/*�㉺���E�ɕǂ��o��*/
	for (z = 2;z < 21;z += 2)
	{
		for (x = 3;x < 46;x += 2)
		{
			_random = rand() % 4;
			if (_random == 0)/*��*/
			{
				g_MAPdata[z][x - 1] = '*';
			}
			else if (_random == 1)/*��*/
			{
				g_MAPdata[z - 1][x] = '*';
			}
			else if (_random == 2)/*��*/
			{
				g_MAPdata[z][x + 1] = '*';
			}
			else if (_random == 3)/*�E*/
			{
				g_MAPdata[z + 1][x] = '*';
			}
		}
	}
}

void UpdateGame(void)
{
	Goal();

	UpdatePlayer();
}

void DrawGame(void)
{
	int y;

	
	system("cls");

	DrawPlayer();

	/*�}�b�v�\��*/
	for (y = 0;y < MAP_HEIGHT;y++)
	{
		printf("%s", &g_MAPdata[y][0]);
		printf("\n");
	}


	/*�ړ�����*/
	printf("������@::���@���@���@���@ �f��ڎw���I�I�@�c��^�[��:%3d\n", g_Time);
}

char GetMap(int x, int y)
{
	return g_MAPdata[y][x];
}

void SetMap(int x, int y, char icon)
{
	g_MAPdata[y][x] = icon;
}

void SubTime(void)
{
	g_Time--;
}

void Goal(void)
{
	if (g_MAPdata[GetPlayerPosition().y][GetPlayerPosition().x] == 'G')
	{
		ChangeMode(MODE_CLEAR);
	}
	else if (g_Time == 0)
	{
		ChangeMode(MODE_GAMEOVER);
	}
}