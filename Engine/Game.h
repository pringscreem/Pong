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
	void DrawBox(const int x, const int y, const int red, const int green, const int blue);
	void DrawReticle(const int x, const int y, const int red, const int green, const int blue);
	bool OverlapTest(const int x_fixed, const int y_fixed, const int x_mobile, const int y_mobile);
	void CheckScreenBoundaries(int& x, int& y, int& vx, int& vy, const int ScreenWidth, const int ScreenHeight);
	/********************************/
	/*  Tutorial Functions          */
	/********************************/
	void ContainBox();
	int ClampScreenX(int x);
	int ClampScreenY(int y);
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	//These are still private
	//Box 1 (User-Controlled Box)
	int x_mobile = 400, y_mobile = 300;
	int vx_mobile = 0, vy_mobile = 0;
	int red_mobile = 255, green_mobile = 255, blue_mobile = 255;
	bool shapeIsChanged = false;
	bool colourIsChanged = false; //a.k.a. "shiftIsPressed" or "controlIsPressed"
	bool inhibitUp = false;
	bool inhibitDown = false;
	bool inhibitLeft = false;
	bool inhibitRight = false;
	bool inCentralColumn = false;

	//Box 2 (Target Box)
	int x_fixed = gfx.ScreenWidth / 2, y_fixed = gfx.ScreenHeight / 2;
	int red_fixed = 0, green_fixed = 255, blue_fixed = 0;

	//More Boxes
	int x_more_boxes[4] = {100, 200, 300, 700};
	int y_more_boxes[4] = {100, 200, 300, 500};
	int vx_more_boxes[4] = { 0,0,0,0 };
	int vy_more_boxes[4] = { 0,0,0,0 };
	//Collision Check
	bool hasCollided = false;
};