/*=============================================================================
  Author
	Ohno Takuya

  Create
	2017/6/6
=============================================================================*/
/*-----------------------------------------------------------------------------
	warning
-----------------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

/*-----------------------------------------------------------------------------
	Include
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include "Game.h"
#include "Clear.h"
#include "GameOver.h"
#include "main.h"


/*-----------------------------------------------------------------------------
	Function
-----------------------------------------------------------------------------*/
void Update(void);
void Draw(void);

/*-----------------------------------------------------------------------------
	Global
-----------------------------------------------------------------------------*/
int g_Time;
MODE g_mode = MODE_CLEAR;// Now Mode

/*-----------------------------------------------------------------------------
	main
-----------------------------------------------------------------------------*/
void  main(void)
{

	ChangeMode(g_mode);

	for (;;)
	{
		Update();

		Draw();
	}
}


void Update(void)
{
	Mode _UpdateFunction[] = {
	UpdateGame,
	UpdateClear,
	UpdateGameOver
	};

	_UpdateFunction[g_mode]();
}

void Draw(void)
{
	Mode _DrawFunction[] = {
	DrawGame,
	DrawClear,
	DrawGameOver
	};

	_DrawFunction[g_mode]();
}

void ChangeMode(MODE mode)
{
	Mode _InitializeFunction[] = {
	InitializeGame,
	InitializeClear,
	InitializeGameOver
	};
	
	_InitializeFunction[mode]();

	g_mode = mode;

	system("cls");

}