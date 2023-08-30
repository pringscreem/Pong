/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <stdlib.h>
#include <time.h>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	/********************************/
	/*  Pong Functions              */
	/********************************/
	void DrawFilledRectangle(const int xStart, const int yStart, const int xEnd, const int yEnd, const int red, const int green, const int blue);
	void DrawLine(const int xStart, const int yStart, const int xEnd, const int yEnd, const int red, const int green, const int blue);
	void DrawPaddle(const int x, const int y, int red, int green, int blue);
	void DrawBall(const int x, const int y, int red, int green, int blue);
	void CheckControlKeys();
	void UpdatePaddlePositions();
	void ClampPaddlesToScreen();
	void UpdateBallPosition();
	void ClampBallToScreen();
	void CheckBallCollision();
	void CheckWallCollision();
	void CheckPaddleCollision();
	void UpdateHelperVariables();
	void OutputToTextFile();
	void DrawPoints(const int playerScore1, const int playerScore2);
	void CheckScores();
	void DrawGameOverScreen();
	void CheckScoreCollision();
	void DrawBackGroundColour();
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	/********************************/
	/*  Pong Variables              */
	/********************************/
	//Ball
	int ballWidth = 15;

	float myNumber = 0;
	int myInt = 0;
	int ballX = 400;
	int ballY = 300;
	int ballVX = 5;
	int ballVY = 5;
	int inhibitBounceCounter = 18;
	const int fullBounceCounter = 18;
	
	//Paddles
	int paddleWidth = 100;
	int paddleThickness = 30;
	
	//Paddle 1 (Left)
	int paddleX1 = paddleThickness;
	int paddleY1 = gfx.ScreenHeight / 2;
	int paddleVY1 = 0;
	bool inhibitUp1 = false;
	bool inhibitDown1 = false;
	
	//Paddle 2 (Right)
	int paddleX2 = gfx.ScreenWidth - paddleThickness - 1;
	int paddleY2 = gfx.ScreenHeight / 2;
	int paddleVY2 = 0;
	bool inhibitUp2 = false;
	bool inhibitDown2 = false;

	//Helper Variables
	int ballTop = ballY + (ballWidth / 2);
	int ballBottom = ballY - (ballWidth / 2);
	int ballLeft = ballX - (ballWidth / 2);
	int ballRight = ballX + (ballWidth / 2);
	int paddleBottom1 = paddleY1 + (paddleWidth / 2);
	int paddleTop1 = paddleY1 - (paddleWidth / 2);
	int paddleSide1 = paddleX1 + (paddleThickness / 2);
	int paddleBottom2 = paddleY2 + (paddleWidth / 2);
	int paddleTop2 = paddleY2 - (paddleWidth / 2);
	int paddleSide2 = paddleX2 - (paddleThickness / 2);

	//Scorekeeping Variables
	int playerScore1 = 0;
	int playerScore2 = 0;
	bool gameIsOver = false;
	bool roundIsOver = true;
	int inhibitScoreCounter = 20;
	const int fullInhibitScoreCounter = 20;
	bool ballJustBouncedOffBackWall = false;
	int winningPlayer = 0;
	int redEnd = 0;
	int greenEnd = 0;
	int blueEnd = 0;
	int colourEnd = 0;
	int colourEndModifier = 2;

	//Point Drawing Variables
	int pointWidth = 5;
	int pointHeight = 10;
	int pointSpacing = 5;
	int offsetX = 10; //Offset from the left/right edge of the window
	int offsetY = 10; //Offset from the top edge of the window
};