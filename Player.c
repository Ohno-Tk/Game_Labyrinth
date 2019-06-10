/*=============================================================================
  Author
	Ohno Takuya

  Create
	2017/6/9
=============================================================================*/
/*-----------------------------------------------------------------------------
	Include
-----------------------------------------------------------------------------*/
#include "Game.h"
#include "Player.h"


/*-----------------------------------------------------------------------------
	Function
-----------------------------------------------------------------------------*/
void Move(void);
void Collision(char collisionLetters);

/*-----------------------------------------------------------------------------
	Global
-----------------------------------------------------------------------------*/
Vector2 g_OldPosition;
Vector2 g_Position;


void InitializePlayer(void)
{
	g_Position.x = 46;
	g_Position.y = 21;
}

void UpdatePlayer(void)
{
	Move();
}

void DrawPlayer(void)
{
	SetMap(g_OldPosition.x, g_OldPosition.y, ' ');
	SetMap(g_Position.x, g_Position.y, 'P');
}

void Move(void)
{
	char _key;

	_key = _getch();/*Get Keyboard key*/


	g_OldPosition = g_Position;

	if (_key == 72)/*Å™*/
	{
		g_Position.y--;

		Collision('*');
		Collision('-');
	}
	else if (_key == 80)/*Å´*/
	{
		g_Position.y++;

		Collision('*');
		Collision('-');
	}
	else if (_key == 75)/*Å©*/
	{
		g_Position.x--;

		Collision('*');
		Collision('|');
	}
	else if (_key == 77)/*Å®ÉLÅ[*/
	{
		g_Position.x++;

		Collision('*');
		Collision('|');
	}
}

void Collision(char collisionLetters)
{
	if (GetMap(g_Position.x, g_Position.y) == collisionLetters)
	{
		g_Position = g_OldPosition;
	}
	else
	{
		SubTime();
	}
}

Vector2 GetPlayerPosition(void)
{
	return g_Position;
}