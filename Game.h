#pragma once

/*-----------------------------------------------------------------------------
	Function
-----------------------------------------------------------------------------*/
void InitializeGame(void);
void UpdateGame(void);
void DrawGame(void);

char GetMap(int x, int y);
void SetMap(int x, int y, char icon);

void SubTime(void);
