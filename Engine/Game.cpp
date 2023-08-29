/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili Directx_mobileFramework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili Directx_mobileFramework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>



Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	//Initialize Some Variables
	srand(time(NULL));
	ballVX = rand() % 5;
	ballVY = rand() % 5;
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{	
	CheckControlKeys();
	UpdatePaddlePositions();
	UpdateBallPosition();
	//OutputToTextFile();
}


void Game::ComposeFrame()
{
	//Draw two paddles:
	DrawPaddle(paddleX1, paddleY1, 255, 255, 255);
	DrawPaddle(paddleX2, paddleY2, 255, 255, 255);

	//Draw the "ball"
	DrawBall(ballX, ballY, 255, 255, 255);
}


//Draw a rectangle between two points in the designated colour
void Game::DrawFilledRectangle(const int xStart, const int yStart, const int xEnd, const int yEnd, const int red, const int green, const int blue)
{
	for(int i = xStart; i < xEnd; i++)
		for(int j = yStart; j < yEnd; j++)
			{
				gfx.PutPixel(i, j, red, green, blue);
			}
}

//Draw a line between two points in the designated colour
void Game::DrawLine (int xStart, int yStart, int xEnd, int yEnd, const int red, const int green, const int blue)
{
	//y = mx + b
	float m = (float(yStart) - float(yEnd)) / (float(xStart) - float(xEnd));
	float b = float(yStart);

	//Use the same algorithm even if the end is smaller
	if(xStart > xEnd)
	{
		std::swap(xStart, xEnd);
		std::swap(yStart, yEnd);
		b = float(yStart);
	}
	for(int x = xStart; x < gfx.ScreenWidth && x < xEnd; x++)
	{
		const float y = m * (float)x + b;
		if(y < gfx.ScreenHeight)
		{
			gfx.PutPixel(x, (int)y, red, green, blue);
		}
	}
}


//Draw the paddle
//The paddle will be 30 pixels thick
//Uses the centre coordinates
void Game::DrawPaddle(const int x, const int y, int red, int green, int blue)
{
	int xStart = x - (paddleThickness / 2);
	int xEnd = x + (paddleThickness / 2);
	int yStart = y - (paddleWidth / 2);
	int yEnd = y + (paddleWidth / 2);
	DrawFilledRectangle(xStart, yStart, xEnd, yEnd, red, green, blue);
}

//Draw the "ball"
//The ball will be 15 pixels wide
//Uses the centre coordinates
void Game::DrawBall(const int x, const int y, int red, int green, int blue)
{
	int xStart = x - (ballWidth / 2);
	int xEnd = x + (ballWidth / 2);
	int yStart = y - (ballWidth / 2);
	int yEnd = y + (ballWidth / 2);
	DrawFilledRectangle(xStart, yStart, xEnd, yEnd, red, green, blue);
}

//w, s, space for the left paddle
//up, down, numpad0 for the right paddle
void Game::CheckControlKeys()
{
	//Check Paddle 1 (Left) Keys
	if (wnd.kbd.KeyIsPressed(0x57))
	{
		if (inhibitUp1)
		{
			//Do nothing
		}
		else
		{
			paddleVY1 = -7;
			inhibitUp1 = true;
		}
	}
	else
	{
		inhibitUp1 = false;
	}

	if (wnd.kbd.KeyIsPressed(0x53))
	{
		if (inhibitDown1)
		{
			//Do nothing
		}
		else
		{
			paddleVY1 = 7;
			inhibitDown1 = true;
		}
	}
	else
	{
		inhibitDown1 = false;

	}
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		paddleVY1 = 0;
	}

	//Check Paddle 2 (Right) Keys
	if (wnd.kbd.KeyIsPressed(VK_UP)) //W Key
	{
		if (inhibitUp2)
		{
			//Do nothing
		}
		else
		{
			paddleVY2 = -7;
			inhibitUp2 = true;
		}
	}
	else
	{
		inhibitUp2 = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN)) //S key
	{
		if (inhibitDown2)
		{
			//Do nothing
		}
		else
		{
			paddleVY2 = 7;
			inhibitDown2 = true;
		}
	}
	else
	{
		inhibitDown2 = false;

	}
	if (wnd.kbd.KeyIsPressed(VK_NUMPAD0))
	{
		paddleVY2 = 0;
	}
}

void Game::UpdatePaddlePositions()
{
	paddleY1 = paddleY1 + paddleVY1;
	paddleY2 = paddleY2 + paddleVY2;
	ClampPaddlesToScreen();
}

void Game::ClampPaddlesToScreen()
{
	//Check Paddle 1 (Left)
	//Top
	if(paddleY1 - (paddleWidth / 2) - 1 < 0)
	{
		paddleY1 = paddleWidth / 2;
		paddleVY1 = 0;
	}
	//Bottom
	if(paddleY1 + (paddleWidth / 2) > gfx.ScreenHeight - 1)
	{
		paddleY1 = gfx.ScreenHeight - (paddleWidth / 2) - 1;
		paddleVY1 = 0;
	}

	//Check Paddle 1 (Left)
	//Top
	if (paddleY2 - (paddleWidth / 2) - 1 < 0)
	{
		paddleY2 = paddleWidth / 2;
		paddleVY2 = 0;
	}
	//Bottom
	if (paddleY2 + (paddleWidth / 2) > gfx.ScreenHeight - 1)
	{
		paddleY2 = gfx.ScreenHeight - (paddleWidth / 2) - 1;
		paddleVY2 = 0;
	}
}

void Game::UpdateBallPosition()
{
	ballX = ballX + ballVX;
	ballY = ballY + ballVY;
	CheckBallCollision();
}

void Game::ClampBallToScreen()
{
	//Check Paddle 1 (Left)
	//Top
	if (ballY - (ballWidth / 2) - 1 < 0)
	{
		ballY = ballWidth / 2;
		ballVY = 0;
	}
	//Bottom
	if (ballY + (ballWidth / 2) > gfx.ScreenHeight - 1)
	{
		ballY = gfx.ScreenHeight - (ballWidth / 2) - 1;
		ballVY = 0;
	}
	//Left
	if (ballX - (ballWidth / 2) - 1 < 0)
	{
		ballX = ballWidth / 2;
		ballVX = 0;
	}
	//Right
	if (ballX + (ballWidth / 2) > gfx.ScreenWidth - 1)
	{
		ballX = gfx.ScreenWidth - (ballWidth / 2) - 1;
		ballVX = 0;
	}
}

void Game::CheckBallCollision()
{
	CheckWallCollision();
	CheckPaddleCollision();
}

void Game::CheckWallCollision()
{
	//Check Paddle 1 (Left)
	//Top
	if (ballY - (ballWidth / 2) - 1 < 0)
	{
		ballY = ballWidth / 2;
		ballVY *= -1;
	}
	//Bottom
	if (ballY + (ballWidth / 2) > gfx.ScreenHeight - 1)
	{
		ballY = gfx.ScreenHeight - (ballWidth / 2) - 1;
		ballVY *= -1;
	}
	//Left
	if (ballX - (ballWidth / 2) - 1 < 0)
	{
		ballX = ballWidth / 2;
		ballVX *= -1;
	}
	//Right
	if (ballX + (ballWidth / 2) > gfx.ScreenWidth - 1)
	{
		ballX = gfx.ScreenWidth - (ballWidth / 2) - 1;
		ballVX *= -1;
	}
}

void Game::CheckPaddleCollision()
{
	UpdateHelperVariables();
	//If the ball is close to the edges
	if(
		(ballLeft <= paddleSide1 ) || 
		(ballRight >= paddleSide2 )
	  )
	{ 
			//If the ball has not recently bounced
			if(inhibitBounceCounter == fullBounceCounter)
			{ 
				inhibitBounceCounter--;
				//Left Side of Ball (Left Paddle)
				if(ballLeft <= paddleSide1)
				{
					//Front of Paddle
					if(ballTop <= paddleBottom1 && ballBottom >= paddleTop1)
					{
						ballVX *= -1;
					}
					//Top Side of Paddle
					else if(ballBottom >= paddleTop1 && ballTop <= paddleTop1)
					{	//Has Collided with the top of Paddle 1 (Left Paddle)
						ballVY *= -1;
					}
					//Bottom Side of Paddle
					else if(ballTop <= paddleBottom1 && ballBottom >= paddleBottom1)
					{
						ballVY *= -1;
					}
				}
				//Right Side of Ball (Right Paddle)
				if (ballRight >= paddleSide2)
				{
					//Front of Paddle
					if (ballTop <= paddleBottom2 && ballBottom >= paddleTop2)
					{
						ballVX *= -1;
					}
					//Top Side of Paddle
					else if(ballBottom >= paddleTop2 && ballTop <= paddleTop2)
					{	//Has collided with the top of Paddle 2 (Right Paddle)
						ballVY *= -1;
					}
					//Bottom Side of Paddle
					else if (ballTop <= paddleBottom2 && ballBottom >= paddleBottom2)
					{
						ballVY *= -1;
					}
				}
			}
			else
			{
				inhibitBounceCounter--;
			}
	}
	else if (ballLeft > paddleSide1 && 
			 ballRight < paddleSide2)
	{
		inhibitBounceCounter = fullBounceCounter;
	}
}

void Game::UpdateHelperVariables()
{
	ballTop = ballY - (ballWidth / 2);
	ballBottom = ballY + (ballWidth / 2);
	ballLeft = ballX - (ballWidth / 2);
	ballRight = ballX + (ballWidth / 2);
	paddleBottom1 = paddleY1 + (paddleWidth / 2);
	paddleTop1 = paddleY1 - (paddleWidth / 2);
	paddleSide1 = paddleX1 + (paddleThickness / 2);
	paddleBottom2 = paddleY2 + (paddleWidth / 2);
	paddleTop2 = paddleY2 - (paddleWidth / 2);
	paddleSide2 = paddleX2 - (paddleThickness / 2);
}

void Game::OutputToTextFile()
{
	//Write the value of iterationCounter to a file named MyCounter.txt
	//The previous location of this file (August 28, 2023) was:
	// C:\msys64\home\ssonn\GitHub2023\Pong\Engine\Debug

	int iterationCounter = 0;
	std::ofstream MyCounterFile;
	MyCounterFile.open("MyCounter.txt");

	MyCounterFile << "The value of iterationCounter is " << iterationCounter << '\n';
	MyCounterFile << "First number: " << rand() % 100 << '\n';
	srand(time(NULL));
	MyCounterFile << "Random number: " << rand() % 100 << '\n';
	srand(1);
	MyCounterFile << "Again the first number: " << rand() % 100 << '\n';

	MyCounterFile.close();
}