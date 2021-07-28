/*=============================================================================

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
void Collision(char collisionLetters1, char collisionLetters2);

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

	if (_key == 72)/*��*/
	{
		g_Position.y--;

		Collision('*', '-');
	}
	else if (_key == 80)/*��*/
	{
		g_Position.y++;

		Collision('*', '-');
	}
	else if (_key == 75)/*��*/
	{
		g_Position.x--;

		Collision('*', '|');
	}
	else if (_key == 77)/*���L�[*/
	{
		g_Position.x++;

		Collision('*', '|');
	}
}

void Collision(char collisionLetters1, char collisionLetters2)
{
	if (GetMap(g_Position.x, g_Position.y) == collisionLetters1 || GetMap(g_Position.x, g_Position.y) == collisionLetters2)
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