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



Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
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
	//Velocity Change
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitLeft)
		{
			//Do nothing
		}
		else
		{
			vx_mobile -= 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if(inhibitRight)
		{
			//Do nothing
		}
		else
		{
			vx_mobile += 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (inhibitUp)
		{
			//Do nothing
		}
		else
		{
			vy_mobile -= 1;
			inhibitUp = true;
		}
	}
	else
	{
		inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (inhibitDown)
		{
			//Do nothing
		}
		else
		{
			vy_mobile += 1;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}
	
	//Position Change
	x_mobile = x_mobile + vx_mobile;
	y_mobile= y_mobile+ vy_mobile;
	//Check Screen Boundaries
	CheckScreenBoundaries(x_mobile, y_mobile, vx_mobile, vy_mobile, gfx.ScreenWidth, gfx.ScreenHeight);
	CheckScreenBoundaries(x_more_boxes[0], y_more_boxes[0], vx_more_boxes[0], vy_more_boxes[0], gfx.ScreenWidth, gfx.ScreenHeight);
	CheckScreenBoundaries(x_more_boxes[1], y_more_boxes[1], vx_more_boxes[1], vy_more_boxes[1], gfx.ScreenWidth, gfx.ScreenHeight);
	CheckScreenBoundaries(x_more_boxes[2], y_more_boxes[2], vx_more_boxes[2], vy_more_boxes[2], gfx.ScreenWidth, gfx.ScreenHeight);
	CheckScreenBoundaries(x_more_boxes[3], y_more_boxes[3], vx_more_boxes[3], vy_more_boxes[3], gfx.ScreenWidth, gfx.ScreenHeight);

	//Colour Change
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		red_mobile = 255;
		green_mobile = 0;
		blue_mobile = 255;
	}
	else if (!wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		red_mobile = 255;
		green_mobile = 255;
		blue_mobile = 255;
	}

	//Shape Change
	if(wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		shapeIsChanged = true;
	}
	else if (!wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		shapeIsChanged = false; //a.k.a. "shiftIsPressed" or "controlIsPressed"
	}

	//Collision Check and Colour Change 
	//If any of them return true, the flag is flipped to true
	hasCollided = OverlapTest(x_fixed, y_fixed, x_mobile, y_mobile) || 
					OverlapTest(x_more_boxes[0], y_more_boxes[0], x_mobile, y_mobile) ||
					OverlapTest(x_more_boxes[1], y_more_boxes[1], x_mobile, y_mobile) ||
					OverlapTest(x_more_boxes[2], y_more_boxes[2], x_mobile, y_mobile) ||
					OverlapTest(x_more_boxes[3], y_more_boxes[3], x_mobile, y_mobile);
}


void Game::ComposeFrame()
{
	//Draw Reticle or Box
	if (hasCollided)
	{
		red_mobile = 255;
		green_mobile = 0;
		blue_mobile = 0;
	}
	if(shapeIsChanged)
	{
		DrawBox(x_mobile, y_mobile, red_mobile, green_mobile, blue_mobile);
	}
	else
	{
		DrawReticle(x_mobile, y_mobile, red_mobile, green_mobile, blue_mobile);
	}

	//Draw Second Box
	DrawBox(x_fixed, y_fixed, red_fixed, green_fixed, blue_fixed);

	//Draw More Boxes
	DrawBox(x_more_boxes[0], y_more_boxes[0], 255, 255, 255);
	DrawBox(x_more_boxes[1], y_more_boxes[1], 255, 255, 255);
	DrawBox(x_more_boxes[2], y_more_boxes[2], 255, 255, 255);
	DrawBox(x_more_boxes[3], y_more_boxes[3], 255, 255, 255);
}

//Draw 5x5 box (corners only)
void Game::DrawBox(const int x, const int y, const int red, const int green, const int blue)
{
	//Square Pixels
	//Top Right
	gfx.PutPixel(+5 + x, -5 + y, red, green, blue);
	gfx.PutPixel(+5 + x, -4 + y, red, green, blue);
	gfx.PutPixel(+5 + x, -3 + y, red, green, blue);
	gfx.PutPixel(+4 + x, -5 + y, red, green, blue);
	gfx.PutPixel(+3 + x, -5 + y, red, green, blue);

	//Top Left
	gfx.PutPixel(-5 + x, -5 + y, red, green, blue);
	gfx.PutPixel(-5 + x, -4 + y, red, green, blue);
	gfx.PutPixel(-5 + x, -3 + y, red, green, blue);
	gfx.PutPixel(-4 + x, -5 + y, red, green, blue);
	gfx.PutPixel(-3 + x, -5 + y, red, green, blue);

	//Bottom Left
	gfx.PutPixel(-5 + x, +5 + y, red, green, blue);
	gfx.PutPixel(-5 + x, +4 + y, red, green, blue);
	gfx.PutPixel(-5 + x, +3 + y, red, green, blue);
	gfx.PutPixel(-4 + x, +5 + y, red, green, blue);
	gfx.PutPixel(-3 + x, +5 + y, red, green, blue);

	//Bottom Right
	gfx.PutPixel(+5 + x, +5 + y, red, green, blue);
	gfx.PutPixel(+5 + x, +4 + y, red, green, blue);
	gfx.PutPixel(+5 + x, +3 + y, red, green, blue);
	gfx.PutPixel(+4 + x, +5 + y, red, green, blue);
	gfx.PutPixel(+3 + x, +5 + y, red, green, blue);
}

//Draw 5x5 reticle (with middle dot)
void Game::DrawReticle(const int x, const int y, const int red, const int green, const int blue)
{
	//Reticle Pixels:
	gfx.PutPixel(-5 + x,      y, red, green, blue); //Changed -5 to -6 (Debugger demo)
	gfx.PutPixel(-4 + x,      y, red, green, blue);
	gfx.PutPixel(-3 + x,      y, red, green, blue);
	gfx.PutPixel(+5 + x,      y, red, green, blue);
	gfx.PutPixel(+4 + x,      y, red, green, blue);
	gfx.PutPixel(+3 + x,      y, red, green, blue);
	gfx.PutPixel(     x, -5 + y, red, green, blue);
	gfx.PutPixel(     x, -4 + y, red, green, blue);
	gfx.PutPixel(     x, -3 + y, red, green, blue);
	gfx.PutPixel(     x, +5 + y, red, green, blue);
	gfx.PutPixel(     x, +4 + y, red, green, blue);
	gfx.PutPixel(     x, +3 + y, red, green, blue);
	gfx.PutPixel(     x,      y, red, green, blue);
}

//Check if two 5x5 pixel objects overlap
bool Game::OverlapTest(const int x_box0, const int y_box0, const int x_box1, const int y_box1)
{
	//Helper Variables
	//Box 0 (User-Controlled Box)
	const int left_box0 = x_box0 - 5;
	const int right_box0 = x_box0 + 5;
	const int top_box0 = y_box0 - 5;
	const int bottom_box0 = y_box0 + 5;
	//Box 1 (Target Box)
	const int left_box1 = x_box1 - 5;
	const int right_box1 = x_box1 + 5;
	const int top_box1 = y_box1 - 5;
	const int bottom_box1 = y_box1 + 5;

	return
		left_box0 <= right_box1 &&
		right_box0 >= left_box1 &&
		top_box0 <= bottom_box1 &&
		bottom_box0 >= top_box1;
}

//Check the screen boundaries and enforce them by setting the x or y value within the bounds 
//and resetting the x or y velocity to zero.
void Game::CheckScreenBoundaries(int& x, int& y, int& vx, int& vy, const int ScreenWidth, const int ScreenHeight)
{
	if (x + 5 >= ScreenWidth) //5 == cursor radius
	{
		x = ScreenWidth - 6;//6 == cursor radius + 1
		vx = 0;
	}
	if (x - 5 < 0)
	{
		x = 0 + 5;
		vx = 0;
	}

	if (y - 5 < 0)
	{
		y = 0 + 5;
		vy = 0;
	}
	if (y + 5 >= ScreenHeight)
	{
		y = ScreenHeight - 6;
		vy = 0;
	}
}

//His function for checking/enforcing screen boundaries (tightly coupled to "_mobile" box)
void Game::ContainBox()
{
	const int left = x_mobile - 5;
	const int right = x_mobile + 5;
	const int top = y_mobile - 5;
	const int bottom = y_mobile + 5;

	if (left < 0)
	{
		x_mobile = 5;
	}
	else if (right >= gfx.ScreenWidth)
	{
		x_mobile = gfx.ScreenWidth - 6;
	}

	if (top < 0)
	{
		y_mobile = 5;
	}
	else if (bottom >= gfx.ScreenHeight)
	{
		y_mobile = gfx.ScreenHeight - 6;
	}
}

//His function for checking/enforcing x boundaries (not tightly coupled)
int Game::ClampScreenX(int x)
{
	const int left = x - 5;
	const int right = x + 5;

	if (left < 0)
	{
		return 5;
	}
	else if (right >= gfx.ScreenWidth)
	{
		return gfx.ScreenWidth - 6;
	}
	else
	{
		return x;
	}
}

//His function for checking/enforcing y boundaries (not tightly coupled)
int Game::ClampScreenY(int y)
{
	const int top = y - 5;
	const int bottom = y + 5;

	if (top < 0)
	{
		return 5;
	}
	else if (bottom >= gfx.ScreenHeight)
	{
		return gfx.ScreenHeight - 6;
	}
	else
	{
		return y;
	}
}
