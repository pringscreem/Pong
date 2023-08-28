	////Blue background and a black square in the middle
	//for(int i = 0; i < gfx.ScreenWidth; i++) //800
	//	for(int j = 0; j < gfx.ScreenHeight; j++) //600
	//	{ 
	//		gfx.PutPixel(i, j, 0, 0, 255);
	//	}
	//int startX = (gfx.ScreenWidth / 2) - 50;
	//int startY = (gfx.ScreenHeight / 2) - 50;
	//		for (int k = startX; k < startX + 100; k++)
	//			for (int m = startY; m < startY + 100; m++)
	//				gfx.PutPixel(k, m, 0, 0, 0);
	
	
	////Put dots on the screen every 100 pixels
	//int xFlag = 0, yFlag= 0;
	//int red = 255, green = 255, blue = 255;
	//while (yFlag < gfx.ScreenHeight)
	//{
	//		while(xFlag < gfx.ScreenWidth)
	//		{
	//			if((xFlag % 100 == 0) && (yFlag % 100 == 0))
	//				{
	//					gfx.PutPixel(xFlag, yFlag, red, green, blue);
	//				}
	//			//xFlag++;
	//			xFlag += 100;
	//		}
	//	xFlag = 0;
	//	yFlag += 100;
	//	//yFlag++;
	//}

	////Write the value of iterationCounter to a file named MyCounter.txt
	////The previous location of this file (when using the Debug builder) was:
	//// C:\msys64\home\ssonn\GitHub2023\Chili-Framework-2016\Debug
	//#include <fstream>
	//int iterationCounter = 0;
	//std::ofstream MyCounterFile;
	//MyCounterFile.open("MyCounter.txt");
	//MyCounterFile << "The value of iterationCounter is " << iterationCounter;
	//MyCounterFile.close();


////Homework 3:
//void Game::ComposeFrame()
//{
//	int x = 400, y = 300;
//	int red = 255, green = 255, blue = 255;
//
//	if (wnd.kbd.KeyIsPressed(VK_LEFT))
//	{
//		x -= 100; //This is only  executed once because everytime the frame is drawn the variables are remade.
//	}			  //This is a consequence of the way we have it set up right now (variable declaration in ComposeFrame).
//	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
//	{
//		x += 100;
//	}
//	else //We don't need the else statements because the frame creates the variables and resets them during creation everytime.
//	{	 //It seems like the frame is drawn at the end of the ComposeFrame function.
//		x = 400;
//	}
//
//	if (wnd.kbd.KeyIsPressed(VK_UP))
//	{
//		y -= 100;
//	}
//	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
//	{
//		y += 100;
//	}
//	else
//	{
//		y = 300;
//	}
//
//	if (wnd.kbd.KeyIsPressed(VK_SPACE))
//	{
//		red = 255;
//		green = 0;
//		blue = 0;
//	}
//	else
//	{
//		red = 255;
//		green = 255;
//		blue = 255;
//	}
//
//	if (wnd.kbd.KeyIsPressed(VK_SHIFT))
//	{
//		//Square Pixels
//		//Top Right
//		gfx.PutPixel(+5 + x, -5 + y, red, green, blue);
//		gfx.PutPixel(+5 + x, -4 + y, red, green, blue);
//		gfx.PutPixel(+5 + x, -3 + y, red, green, blue);
//		gfx.PutPixel(+4 + x, -5 + y, red, green, blue);
//		gfx.PutPixel(+3 + x, -5 + y, red, green, blue);
//
//		//Top Left
//		gfx.PutPixel(-5 + x, -5 + y, red, green, blue);
//		gfx.PutPixel(-5 + x, -4 + y, red, green, blue);
//		gfx.PutPixel(-5 + x, -3 + y, red, green, blue);
//		gfx.PutPixel(-4 + x, -5 + y, red, green, blue);
//		gfx.PutPixel(-3 + x, -5 + y, red, green, blue);
//
//		//Bottom Left
//		gfx.PutPixel(-5 + x, +5 + y, red, green, blue);
//		gfx.PutPixel(-5 + x, +4 + y, red, green, blue);
//		gfx.PutPixel(-5 + x, +3 + y, red, green, blue);
//		gfx.PutPixel(-4 + x, +5 + y, red, green, blue);
//		gfx.PutPixel(-3 + x, +5 + y, red, green, blue);
//
//		//Bottom Right
//		gfx.PutPixel(+5 + x, +5 + y, red, green, blue);
//		gfx.PutPixel(+5 + x, +4 + y, red, green, blue);
//		gfx.PutPixel(+5 + x, +3 + y, red, green, blue);
//		gfx.PutPixel(+4 + x, +5 + y, red, green, blue);
//		gfx.PutPixel(+3 + x, +5 + y, red, green, blue);
//	}
//	else
//	{
//		//Reticle Pixels:
//		gfx.PutPixel(-5 + x, y, red, green, blue);
//		gfx.PutPixel(-4 + x, y, red, green, blue);
//		gfx.PutPixel(-3 + x, y, red, green, blue);
//		gfx.PutPixel(+5 + x, y, red, green, blue);
//		gfx.PutPixel(+4 + x, y, red, green, blue);
//		gfx.PutPixel(+3 + x, y, red, green, blue);
//		gfx.PutPixel(x, -5 + y, red, green, blue);
//		gfx.PutPixel(x, -4 + y, red, green, blue);
//		gfx.PutPixel(x, -3 + y, red, green, blue);
//		gfx.PutPixel(x, +5 + y, red, green, blue);
//		gfx.PutPixel(x, +4 + y, red, green, blue);
//		gfx.PutPixel(x, +3 + y, red, green, blue);
//		gfx.PutPixel(x, y, red, green, blue); //shift + ctrl + space to pull up Intellisense function info
//	}
//}
//

////Mouse Cursor
//int mouseRed = 0, mouseGreen = 0, mouseBlue = 255;
//int mouseX = 400, mouseY = 300;
//if (wnd.mouse.GetPosX() < gfx.ScreenWidth && wnd.mouse.GetPosX() > 0)
//{
//	mouseX = wnd.mouse.GetPosX();
//}
//if (wnd.mouse.GetPosY() < gfx.ScreenHeight && wnd.mouse.GetPosY() > 0)
//{
//	mouseY = wnd.mouse.GetPosY();
//}
//if (wnd.mouse.LeftIsPressed() == true)
//{
//	mouseRed = 255;
//}
//gfx.PutPixel(-5 + mouseX, mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(-4 + mouseX, mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(-3 + mouseX, mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(+5 + mouseX, mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(+4 + mouseX, mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(+3 + mouseX, mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(mouseX, -5 + mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(mouseX, -4 + mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(mouseX, -3 + mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(mouseX, +5 + mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(mouseX, +4 + mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(mouseX, +3 + mouseY, mouseRed, mouseGreen, mouseBlue);
//gfx.PutPixel(mouseX, mouseY, mouseRed, mouseGreen, mouseBlue);

////Cursor position movement
//if (wnd.kbd.KeyIsPressed(VK_LEFT))
//{
//	x -= 3;
//}
//else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
//{
//	x += 3;
//}
//
//if (wnd.kbd.KeyIsPressed(VK_UP))
//{
//	y -= 3;
//}
//else if (wnd.kbd.KeyIsPressed(VK_DOWN))
//{
//	y += 3;
//}
//
//if (wnd.kbd.KeyIsPressed(VK_SPACE))
//{
//	red = 255;
//	green = 0;
//	blue = 0;
//}
//else
//{
//	red = 255;
//	green = 255;
//	blue = 255;
//}

	////Check Screen Boundaries
	//if ((x > gfx.ScreenWidth - 5 || x < 0 + 5) || (y > gfx.ScreenHeight - 5 || y < 0 + 5))
	//{
	//	vx_mobile = 0;
	//	vy_mobile = 0;
	//	x = 400; //This just resets the position to the centre
	//	y = 300; //His version (leave it at the nearest edge position) 
	//			 //is better, but he uses hardcoded values.
	//}

	//}
	////Central Column Colour Change
	//if(200 < x && x < 600 && !wnd.kbd.KeyIsPressed(VK_SPACE))
	//{
	//	inCentralColumn = true;
	//	red = 0;
	//	green = 255;
	//	blue = 0;
	//}

			////Reticle Pixels:
		//gfx.PutPixel(-5 + x,     y, red, green, blue);
		//gfx.PutPixel(-4 + x,     y, red, green, blue);
		//gfx.PutPixel(-3 + x,     y, red, green, blue);
		//gfx.PutPixel(+5 + x,     y, red, green, blue);
		//gfx.PutPixel(+4 + x,     y, red, green, blue);
		//gfx.PutPixel(+3 + x,     y, red, green, blue);
		//gfx.PutPixel(     x,-5 + y, red, green, blue);
		//gfx.PutPixel(     x,-4 + y, red, green, blue);
		//gfx.PutPixel(     x,-3 + y, red, green, blue);
		//gfx.PutPixel(     x,+5 + y, red, green, blue);
		//gfx.PutPixel(     x,+4 + y, red, green, blue);
		//gfx.PutPixel(     x,+3 + y, red, green, blue);
		//gfx.PutPixel(     x,     y, red, green, blue);

				////Square Pixels
		////Top Right
		//gfx.PutPixel(+5 + x, -5 + y, red, green, blue);
		//gfx.PutPixel(+5 + x, -4 + y, red, green, blue);
		//gfx.PutPixel(+5 + x, -3 + y, red, green, blue);
		//gfx.PutPixel(+4 + x, -5 + y, red, green, blue);
		//gfx.PutPixel(+3 + x, -5 + y, red, green, blue);
		//
		////Top Left
		//gfx.PutPixel(-5 + x, -5 + y, red, green, blue);
		//gfx.PutPixel(-5 + x, -4 + y, red, green, blue);
		//gfx.PutPixel(-5 + x, -3 + y, red, green, blue);
		//gfx.PutPixel(-4 + x, -5 + y, red, green, blue);
		//gfx.PutPixel(-3 + x, -5 + y, red, green, blue);
		//
		////Bottom Left
		//gfx.PutPixel(-5 + x, +5 + y, red, green, blue);
		//gfx.PutPixel(-5 + x, +4 + y, red, green, blue);
		//gfx.PutPixel(-5 + x, +3 + y, red, green, blue);
		//gfx.PutPixel(-4 + x, +5 + y, red, green, blue);
		//gfx.PutPixel(-3 + x, +5 + y, red, green, blue);
		//
		////Bottom Right
		//gfx.PutPixel(+5 + x, +5 + y, red, green, blue);
		//gfx.PutPixel(+5 + x, +4 + y, red, green, blue);
		//gfx.PutPixel(+5 + x, +3 + y, red, green, blue);
		//gfx.PutPixel(+4 + x, +5 + y, red, green, blue);
		//gfx.PutPixel(+3 + x, +5 + y, red, green, blue);

	////Collision Check
	//hasCollided = false; //The reset is important.
	//
	////X Collision
	////Check Right Side
	//if ((x_mobile < x) && (x - x_mobile < 5))
	//{
	//	hasCollided = true;
	//}
	////Check Left Side
	//if ((x_mobile > x) && (x_mobile - x < 5))
	//{
	//	hasCollided = true;
	//}
	//
	////Y Collision
	////Check Bottom Side
	//if ((y_mobile < y) && (y - y_mobile < 5))
	//{
	//	hasCollided = true;
	//}
	////Check Top Side
	//if ((y_mobile > y) && (y_mobile - y < 5))
	//{
	//	hasCollided = true;
	//}

	////Repeated code from collision check
	//else if((x_mobileMax >= xMin) && (x_mobileMax <= xMax))
	//{
	//	//The right (max) edge of Box 2 is in bounds.
	//	if ((y_mobileMin <= yMax) && (y_mobileMin >= yMin))
	//	{
	//		//Top of Box 2 is in bounds.
	//		hasCollided = true;
	//	}
	//	if ((y_mobileMax >= yMin) && (y_mobileMax <= yMax))
	//	{
	//		//Bottom of Box 2 is in bounds.
	//		hasCollided = true;
	//	}
	//}
////Colour change when collision occurs
//if (hasCollided)
//{
//	red_mobile = 255;
//	green_mobile = 0;
//	blue_mobile = 0;
//}
//else
//{
//	red_mobile = 255;
//	green_mobile = 255;
//	blue_mobile = 255;
//}

	////The previous collision check
	////The actual check:
	//if(((left_box1 <= right_box0) && (left_box1 >= left_box0)) || ((right_box1 >= left_box0) && (right_box1 <= right_box0)))
	//{ //My check is different from his, but it has the same number of condition checks
	//	//The left (_left) edge of Box 2 is in bounds.
	//	if((top_box1 <= bottom_box0) && (top_box1 >= top_box0))
	//	{
	//		//Top of Box 1 is in bounds.
	//		return true;
	//	}
	//	if((bottom_box1 >= top_box0) && (bottom_box1 <= bottom_box0))
	//	{
	//		//Bottom of Box 1 is in bounds.
	//		return true;
	//	}
	//}

	////Grid of boxes
	//for (int i = 20; i < gfx.ScreenWidth - 20; i += 20)
	//	for (int j = 20; j < gfx.ScreenHeight - 20; j += 20)
	//	{
	//		DrawBox(i, j, red_mobile + i, green_mobile + j, blue_mobile + i + j);
	//	}