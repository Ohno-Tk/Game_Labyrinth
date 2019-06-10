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
#include "Map.h"
#include "Game.h"

/*-----------------------------------------------------------------------------
	Macro
-----------------------------------------------------------------------------*/
#define TIME (100)

/*-----------------------------------------------------------------------------
	Function
-----------------------------------------------------------------------------*/
void Goal(void);

/*-----------------------------------------------------------------------------
	Global
-----------------------------------------------------------------------------*/
int g_Time;


void InitializeGame(void)
{
	g_Time = TIME;

	InitializePlayer();

	InitializeMap();
}

void UpdateGame(void)
{
	Goal();

	UpdatePlayer();
}

void DrawGame(void)
{
	system("cls");
	
	DrawPlayer();
	DrawMap();

	printf("操作方法::←　→　↑　↓　 Ｇを目指せ！！　残りターン:%3d\n", g_Time);
}

void SubTime(void)
{
	g_Time--;
}

void Goal(void)
{
	if (GetMap(GetPlayerPosition().x, GetPlayerPosition().x) == 'G')
	{
		ChangeMode(MODE_CLEAR);
	}
	else if (g_Time == 0)
	{
		ChangeMode(MODE_GAMEOVER);
	}
}