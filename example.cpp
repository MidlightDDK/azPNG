//-- Including all the necessary files

#include <iostream>
#include "azPNG.h"


//-- Starting the main function

int main(int argc, char *argv[])
	{
	
	//-- Prepare dimensions
	
	int width = 400, height = 300;
	
	//-- We initialize random numbers
	
	std::srand(std::time(0));

	//-- We create an image

	azPNG::Image IM_DRAWING(width, height);
	for(int y = 0; y < height; y++)
		{
		for(int x = 0; x < width; x++)
			IM_DRAWING.DrawPixel(x, y, azPNG::Color::RandColor());
		}
		
	std::cout << IM_DRAWING.GetWidth() << ' ' << IM_DRAWING.GetHeight() << '\n';

	//-- We save it

	IM_DRAWING.Save();

	//-- We explain that everything went well

	return 0;
	}
