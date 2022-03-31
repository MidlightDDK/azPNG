/*

Thanks for using the azPNG header made my AZAR Majed ! It tool has been designed for Linux.
To be able to render images, you need to run the following command :
sudo apt-get install netpbm

---Image--- Image object

*/

//-- Including all the necessary files

#ifndef AZ_PNG_H
#define AZ_PNG_H

#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

namespace azPNG
	{

	//-- We create a color class

	class Color
		{
		public :
		
			//-- Function : Default constructor
		
			Color()
				{
				
				//-- Set the color to pure black
				
				SetColor(0,0,0);
				}
				
			//-- Function : Constructor with values for grey scale
			
			Color(short const& I_GREY)
				{
				
				//-- If an invalid color is passed down, set the color to black
				
				if(!(SetColor(I_GREY,I_GREY,I_GREY)))
					SetColor(0,0,0);
				}
				
			//-- Function : Constructor with values for all colors
			
			Color(short const& I_RED, short const& I_GREEN, short const& I_BLUE)
				{
				
				//-- If an invalid color is passed down, set the color to black
				
				if(!(SetColor(I_RED,I_GREEN,I_BLUE)))
					SetColor(0,0,0);
				}
				
			//-- Returns the value for red
				
			unsigned short GetRed() const
				{
				return I_RED;
				}
				
			//-- Returns the value for green
				
			unsigned short GetGreen() const
				{
				return I_GREEN;
				}
				
			//-- Returns the value for blue
				
			unsigned short GetBlue() const
				{
				return I_BLUE;
				}
				
			//-- Return a string with all the colors
			
			std::string GetColor() const
				{
				return std::string(std::to_string(I_RED)+" "+std::to_string(I_GREEN)+" "+std::to_string(I_BLUE));
				}
				
			//-- Change the value for red 
			
			bool SetRed(short const& I_INTENSITY)
				{
				
				//-- If the value is correct, we change it
				
				if(I_INTENSITY >= 0 && I_INTENSITY < 256)
					I_RED = I_INTENSITY;
				else
					return false;
				
				//-- If everything went well, we state it	
					
				return true;
				}
				
			//-- Change the value for green
			
			bool SetGreen(short const& I_INTENSITY)
				{
				
				//-- If the value is correct, we change it
				
				if(I_INTENSITY >= 0 && I_INTENSITY < 256)
					I_GREEN = I_INTENSITY;
				else
					return false;
				
				//-- If everything went well, we state it	
					
				return true;
				}
				
			//-- Change the value for blue
			
			bool SetBlue(short const& I_INTENSITY)
				{
				
				//-- If the value is correct, we change it
				
				if(I_INTENSITY >= 0 && I_INTENSITY < 256)
					I_BLUE = I_INTENSITY;
				else
					return false;
				
				//-- If everything went well, we state it	
					
				return true;
				}
				
			//-- Change the color
			
			bool SetColor(short const& I_RED, short const& I_GREEN, short const& I_BLUE)
				{
				
				//-- If the value is correct, we change it
				
				if(I_RED >= 0 && I_RED < 256 && I_GREEN >= 0 && I_GREEN < 256 && I_BLUE >= 0 && I_BLUE < 256)
					{
					this->I_RED 	= I_RED;
					this->I_GREEN 	= I_GREEN;
					this->I_BLUE 	= I_BLUE;
					}
				else
					return false;
				
				//-- If everything went well, we state it	
					
				return true;
				}
				
			//-- Change the color
			
			bool SetColor(Color const& CL_COLOR)
				{
				
				//-- If the value is correct, we change it
				
				if(CL_COLOR.GetRed() >= 0 && CL_COLOR.GetRed() < 256 && CL_COLOR.GetGreen() >= 0 && CL_COLOR.GetGreen() < 256 && CL_COLOR.GetBlue() >= 0 && CL_COLOR.GetBlue() < 256)
					{
					this->I_RED 	= CL_COLOR.GetRed();
					this->I_GREEN 	= CL_COLOR.GetGreen();
					this->I_BLUE 	= CL_COLOR.GetBlue();
					}
				else
					return false;
				
				//-- If everything went well, we state it	
					
				return true;
				}
				
			//-- Returns a random color
				
			Color static RandColor()
				{
				
				//-- We return a random color
				
				return Color(rand() % 256, rand() % 256, rand() % 256);
				}
				
			//-- Returns a random red
				
			Color static RandRed()
				{
				
				//-- We return a random color
				
				return Color(rand() % 256, 0, 0);
				}
				
			//-- Returns a random green
				
			Color static RandGreen()
				{
				
				//-- We return a random color
				
				return Color(0, rand() % 256, 0);
				}
				
			//-- Returns a random blue
				
			Color static RandBlue()
				{
				
				//-- We return a random color
				
				return Color(0, 0, rand() % 256);
				}
				
			//-- Returns a random yellow
				
			Color static RandYellow()
				{
				
				//-- We return a random color
				
				return Color(rand() % 256, rand() % 256, 0);
				}
				
			//-- Returns a random cyan
				
			Color static RandCyan()
				{
				
				//-- We return a random color
				
				return Color(0, rand() % 256, rand() % 256);
				}
				
			//-- Returns a random magenta
				
			Color static RandMagenta()
				{
				
				//-- We return a random color
				
				return Color(rand() % 256, 0, rand() % 256);
				}
				
			//-- Returns a random grey
				
			Color static RandGrey()
				{
				
				//-- We return a random color
				
				return Color(rand() % 256, rand() % 256, rand() % 256);
				}
				
			//-- Returns black
				
			Color static Black()
				{
				
				//-- We return the color
				
				return Color(0, 0, 0);
				}
				
			//-- Returns red
				
			Color static Red()
				{
				
				//-- We return the color
				
				return Color(255, 0, 0);
				}
				
			//-- Returns green
				
			Color static Green()
				{
				
				//-- We return the color
				
				return Color(0, 255, 0);
				}
				
			//-- Returns blue
				
			Color static Blue()
				{
				
				//-- We return the color
				
				return Color(0, 0, 255);
				}
				
			//-- Returns yellow
				
			Color static Yellow()
				{
				
				//-- We return the color
				
				return Color(255, 255, 0);
				}
				
			//-- Returns cyan
				
			Color static Cyan()
				{
				
				//-- We return the color
				
				return Color(0, 255, 255);
				}
				
			//-- Returns magenta
				
			Color static Magenta()
				{
				
				//-- We return the color
				
				return Color(255, 0, 255);
				}
				
			//-- Returns white
				
			Color static White()
				{
				
				//-- We return the color
				
				return Color(255, 255, 255);
				}
				
			//-- Returns dark red
				
			Color static DarkRed()
				{
				
				//-- We return the color
				
				return Color(127, 0, 0);
				}
				
			//-- Returns dark green
				
			Color static DarkGreen()
				{
				
				//-- We return the color
				
				return Color(0, 127, 0);
				}
				
			//-- Returns dark blue
				
			Color static DarkBlue()
				{
				
				//-- We return the color
				
				return Color(0, 0, 127);
				}
				
			//-- Returns dark yellow
				
			Color static DarkYellow()
				{
				
				//-- We return the color
				
				return Color(127, 127, 0);
				}
				
			//-- Returns dark cyan
				
			Color static DarkCyan()
				{
				
				//-- We return the color
				
				return Color(0, 127, 127);
				}
				
			//-- Returns dark magenta
				
			Color static DarkMagenta()
				{
				
				//-- We return the color
				
				return Color(127, 0, 127);
				}
				
			//-- Returns grey
				
			Color static Grey()
				{
				
				//-- We return the color
				
				return Color(127, 127, 127);
				}
				
			//-- Returns very dark red
				
			Color static VeryDarkRed()
				{
				
				//-- We return the color
				
				return Color(63, 0, 0);
				}
				
			//-- Returns very dark green
				
			Color static VeryDarkGreen()
				{
				
				//-- We return the color
				
				return Color(0, 63, 0);
				}
				
			//-- Returns very dark blue
				
			Color static VeryDarkBlue()
				{
				
				//-- We return the color
				
				return Color(0, 0, 63);
				}
				
			//-- Returns very dark yellow
				
			Color static VeryDarkYellow()
				{
				
				//-- We return the color
				
				return Color(63, 63, 0);
				}
				
			//-- Returns very dark cyan
				
			Color static VeryDarkCyan()
				{
				
				//-- We return the color
				
				return Color(0, 63, 63);
				}
				
			//-- Returns very dark magenta
				
			Color static VeryDarkMagenta()
				{
				
				//-- We return the color
				
				return Color(63, 0, 63);
				}
				
			//-- Returns dark grey
				
			Color static DarkGrey()
				{
				
				//-- We return the color
				
				return Color(63, 63, 63);
				}
				
			//-- Adds a value to a color
				
			void Add(unsigned short I_VALUE)
				{
				
				//-- There is a focus
				
				unsigned short I_FOCUS;
				
				//-- We determine which one is the focus
				
				if(I_GREEN == 0 && I_BLUE == 0)
					I_FOCUS = 1;
				else if(I_BLUE == 0 && I_RED == 0)
					I_FOCUS = 2;
				else if(I_RED == 0 && I_GREEN == 0)
					I_FOCUS = 3;
				else if(I_BLUE == 0)
					I_FOCUS = 1;
				else if(I_RED == 0)
					I_FOCUS = 2;
				else
					I_FOCUS = 3;
					
				//-- We go throught the cycle
					
				for(unsigned int i=0; i < I_VALUE; i++)
					{
					
					//-- Depending on the focus, we switch the color
					
					if(I_FOCUS == 1)
						{
						if(I_GREEN < 255)
							{
							I_GREEN++;
							}
						else
							{
							I_RED--;
								
							//-- Change focus
							
							if(I_RED == 0)
								I_FOCUS = 2;
							}
						}
					else if(I_FOCUS == 2)
						{
						if(I_BLUE < 255)
							{
							I_BLUE++;
							}
						else
							{
							I_GREEN--;
								
							//-- Change focus
							
							if(I_GREEN == 0)
								I_FOCUS = 3;
							}
						}
					else
						{
						if(I_RED < 255)
							{
							I_RED++;
							}
						else
							{
							I_BLUE--;
								
							//-- Change focus
							
							if(I_BLUE == 0)
								I_FOCUS = 1;
							}
						}
					}
				}
				
			//-- Substracts a value to a color
				
			void Substract(unsigned short I_VALUE)
				{
				
				//-- There is a focus
				
				unsigned short I_FOCUS;
				
				//-- We determine which one is the focus
				
				if(I_GREEN == 0 && I_BLUE == 0)
					I_FOCUS = 1;
				else if(I_BLUE == 0 && I_RED == 0)
					I_FOCUS = 2;
				else if(I_RED == 0 && I_GREEN == 0)
					I_FOCUS = 3;
				else if(I_BLUE == 0)
					I_FOCUS = 2;
				else if(I_RED == 0)
					I_FOCUS = 3;
				else
					I_FOCUS = 1;
					
				//-- We go throught the cycle
					
				for(unsigned int i=0; i < I_VALUE; i++)
					{
					
					//-- Depending on the focus, we switch the color
					
					if(I_FOCUS == 1)
						{
						if(I_BLUE < 255)
							{
							I_BLUE++;
							}
						else
							{
							I_RED--;
								
							//-- Change focus
							
							if(I_RED == 0)
								I_FOCUS = 3;
							}
						}
					else if(I_FOCUS == 2)
						{
						if(I_RED < 255)
							{
							I_RED++;
							}
						else
							{
							I_GREEN--;
								
							//-- Change focus
							
							if(I_GREEN == 0)
								I_FOCUS = 1;
							}
						}
					else
						{
						if(I_GREEN < 255)
							{
							I_GREEN++;
							}
						else
							{
							I_BLUE--;
								
							//-- Change focus
							
							if(I_BLUE == 0)
								I_FOCUS = 2;
							}
						}
					}
				}
				
			//-- Get a Shaded version of the color
				
			Color GetShade(unsigned short I_VALUE)
				{
				
				//-- We get the values
				
				short I_NEW_RED = I_RED - I_RED * I_VALUE / 100;
				short I_NEW_GREEN = I_GREEN - I_GREEN * I_VALUE / 100;
				short I_NEW_BLUE = I_BLUE - I_BLUE * I_VALUE / 100;
				
				//-- We shade down in case
				
				if(I_NEW_RED < 0)
					I_NEW_RED = 0;
				if(I_NEW_GREEN < 0)
					I_NEW_GREEN = 0;
				if(I_NEW_BLUE < 0)
					I_NEW_BLUE = 0;
				
				//-- We return the color
				
				return Color(I_NEW_RED, I_NEW_GREEN, I_NEW_BLUE);
				}
				
			//-- Get a Tinted version of the color
				
			Color GetTint(unsigned short I_VALUE)
				{
				
				//-- We get the values
				
				short I_NEW_RED = I_RED + I_RED * I_VALUE / 100;
				short I_NEW_GREEN = I_GREEN + I_GREEN * I_VALUE / 100;
				short I_NEW_BLUE = I_BLUE + I_BLUE * I_VALUE / 100;
				
				//-- We shade down in case
				
				if(I_NEW_RED > 255)
					I_NEW_RED = 255;
				if(I_NEW_GREEN > 255)
					I_NEW_GREEN = 255;
				if(I_NEW_BLUE > 255)
					I_NEW_BLUE = 255;
				
				//-- We return the color
				
				return Color(I_NEW_RED, I_NEW_GREEN, I_NEW_BLUE);
				}
				
			//-- Shade the color
			
			void Shade(unsigned short I_VALUE)
				{
				
				//-- We apply the value
				
				SetColor(GetShade(I_VALUE));
				}
				
			//-- Tint the color
			
			void Tint(unsigned short I_VALUE)
				{
				
				//-- We apply the value
				
				SetColor(GetTint(I_VALUE));
				}
				
			//-- Is the color darker or lighter
			
			bool isDark()
				{
				
				//-- We check if the color is dark or not
				
				return (I_RED < 128 && I_GREEN < 128 && I_BLUE < 128);
				}
				
			//-- Get the opposite color
				
			Color GetAdd2()
				{
				
				//--
				
				return Color(255 - I_RED, 255 - I_GREEN, 255 - I_BLUE);
				}
				
			//-- Get the 1/3 color on the wheel
				
			Color GetAdd3()
				{
				
				//--
				
				Color CL_TEMP(I_RED, I_GREEN, I_BLUE);
				CL_TEMP.Add(510);
				
				//--
				
				return CL_TEMP;
				}
				
			//-- Get the other 1/3 color on the wheel
				
			Color GetSubstract3()
				{
				
				//--
				
				Color CL_TEMP(I_RED, I_GREEN, I_BLUE);
				CL_TEMP.Substract(510);
				
				//--
				
				return CL_TEMP;
				}
				
			//-- Get the 1/4 color on the wheel
				
			Color GetAdd4()
				{
				
				//--
				
				Color CL_TEMP(I_RED, I_GREEN, I_BLUE);
				CL_TEMP.Add(382);
				
				//--
				
				return CL_TEMP;
				}
				
			//-- Get the other 1/4 color on the wheel
				
			Color GetSubstract4()
				{
				
				//--
				
				Color CL_TEMP(I_RED, I_GREEN, I_BLUE);
				CL_TEMP.Substract(382);
				
				//--
				
				return CL_TEMP;
				}
				
			//-- 
		
		private :
			unsigned short I_RED;
			unsigned short I_GREEN;
			unsigned short I_BLUE;
		};

	//-- We create a class for our image

	class Image
		{
		public:
		
			//-- Function : Construct the image
		
			Image(short const& I_WIDTH, short const& I_HEIGHT)
				{
				
				//-- We transfer the right dimensions
				
				if(I_WIDTH >= 0)
					this->I_WIDTH 	= I_WIDTH;
				else
					this->I_WIDTH 	= 1;
				if(I_HEIGHT >= 0)
					this->I_HEIGHT 	= I_HEIGHT;
				else
					this->I_HEIGHT 	= 1;
				
				//-- We make columns
				
				CL_PIXELS 	= new Color*[I_HEIGHT];
				
				//-- We fill the lines inside the columns
				
				for(unsigned short i = 0; i < I_HEIGHT; i++)
					CL_PIXELS[i] = new Color[I_WIDTH];
				}
		
			//-- Function : Construct the image with a color
		
			Image(short const& I_WIDTH, short const& I_HEIGHT, Color const& CL_COLOR) : Image(I_WIDTH, I_HEIGHT)
				{
					
				//-- We initialize those with values
				
				Clear(CL_COLOR);
				}
				
			//-- Function : Returns the width of the image
				
			unsigned short GetWidth() const
				{
				
				//-- We return the value
				
				return I_WIDTH;
				}
				
			//-- Function : Returns the height of the image
				
			unsigned short GetHeight() const
				{
				
				//-- We return the value
				
				return I_HEIGHT;
				}
				
			//-- Function : Return the corresponding pixel
			
			Color GetPixel(short const& I_X, short const& I_Y) const
				{
				
				//-- If the coordinates are wrong, we exit
				
				if(I_X < 0 || I_X >= I_WIDTH || I_Y < 0 || I_Y >= I_HEIGHT)
					return Color();
				
				//-- We return the value
				
				return CL_PIXELS[I_Y][I_X];
				}
				
			//-- Function : Returns a croped version of the image
			
			Image GetCrop(short I_X1, short I_Y1, short I_X2, short I_Y2) const
				{
				
				//-- If the coordinates are wrong, we exit
				
				if(I_X1 < 0 || I_X1 >= I_WIDTH || I_Y1 < 0 || I_Y1 >= I_HEIGHT || I_X2 < 0 || I_X2 >= I_WIDTH || I_Y2 < 0 || I_Y2 >= I_HEIGHT)
					return Image(1,1);
				
				//-- We arrange the coordinates
				
				OrdonatePoints(I_X1, I_X2);
				OrdonatePoints(I_Y1, I_Y2);
				
				//-- We create a croped version
				
				Image IM_CROPED_VERSION(I_X2 - I_X1, I_Y2 - I_Y1);
				
				//-- We transfer the colors
				
				for(unsigned short y = 0; y <= I_Y2 - I_Y1; y++)
					for(unsigned short x = 0; x <= I_X2 - I_X1; x++)
						IM_CROPED_VERSION.DrawPixel(x,y,CL_PIXELS[I_Y1 + y][I_X1 + x]);
				
				//-- We return it
				
				return IM_CROPED_VERSION;
				}
					
			//-- Function : Returns a croped version of the image
			
			Image GetScale(short const& I_RATIO) const
				{
				
				//-- If there is a bad ratio, we exit
				
				if(I_RATIO <= 0)
					return Image(1,1);
				
				//-- We create the scaled version
				
				Image IM_SCALED_VERSION(I_WIDTH * I_RATIO, I_HEIGHT * I_RATIO);
				
				//-- We put the colors inside it
				
				for(unsigned short y = 0; y < I_HEIGHT; y++)
					for(unsigned short x = 0; x < I_WIDTH; x++)
						IM_SCALED_VERSION.FillRectangle(x * I_RATIO, y * I_RATIO, ((x+1) * I_RATIO) - 1, ((y+1) * I_RATIO) - 1, CL_PIXELS[y][x]);
				
				//-- We return it
				
				return IM_SCALED_VERSION;
				}
				
			//-- Function : Draw a pixel on the image
			
			void DrawPixel(float const& F_X, float const& F_Y, Color const& CL_COLOR = Color(255))
				{
				
				//-- We take the right value
				
				short I_X = round(F_X);
				short I_Y = round(F_Y);
				
				//-- If the pixel is inside the image, we draw it
				
				if(I_X >= 0 && I_X < I_WIDTH && I_Y >=0 && I_Y < I_HEIGHT)
					CL_PIXELS[I_Y][I_X].SetColor(CL_COLOR);
				}
				
			//-- Function : Draw a line on the image
			
			void DrawLine(float const& F_X1, float const& F_Y1, float const& F_X2, float const& F_Y2, Color const& CL_COLOR = Color(255))
				{
				
				//-- We initialize the step
				
				float F_STEP_X = F_X2 - F_X1;
				float F_STEP_Y = F_Y2 - F_Y1;
				
				//-- We look for the main direction of the line
				
				if(round(F_X2 - F_X1) > round(F_Y2 - F_Y1))
					{
					
					//-- We normalize our direction vector to 1
					
					F_STEP_X /= round(F_X2 - F_X1);
					F_STEP_Y /= round(F_X2 - F_X1);
					
					//-- We draw
					
					for(unsigned short I_STEP = 0; I_STEP <= round(F_X2 - F_X1); I_STEP++)
						DrawPixel(F_X1 + F_STEP_X * I_STEP, F_Y1 + F_STEP_Y * I_STEP, CL_COLOR);
					}
				else
					{
					
					//-- We normalize our direction vector to 1
					
					F_STEP_X /= round(F_Y2 - F_Y1);
					F_STEP_Y /= round(F_Y2 - F_Y1);
					
					//-- We draw
					
					for(unsigned short I_STEP = 0; I_STEP <= round(F_Y2 - F_Y1); I_STEP++)
						DrawPixel(F_X1 + F_STEP_X * I_STEP, F_Y1 + F_STEP_Y * I_STEP, CL_COLOR);
					}
				}
			
			//-- Function : Draw a rectangle on the image
			
			void DrawRectangle(float F_X1, float F_Y1, float F_X2, float F_Y2, Color const& CL_COLOR = Color(255))
				{
				
				//-- We adjust the coordinates
				
				OrdonatePoints(F_X1, F_X2);
				OrdonatePoints(F_Y1, F_Y2);
				
				//-- We draw the columns
				
				for(short y = F_Y1; y <= F_Y2; y++)
					{
					
					//-- First column
				
					DrawPixel(F_X1,y,CL_COLOR);
						
					//-- Second column
				
					DrawPixel(F_X2,y,CL_COLOR);
					}
					
				//-- We draw the lines
				
				for(short x = F_X1; x <= F_X2; x++)
					{
					
					//-- First line
				
					DrawPixel(x,F_Y1,CL_COLOR);
					
					//-- Second line
				
					DrawPixel(x,F_Y2,CL_COLOR);
					}
				}
				
			//-- Function : Draw a filled rectange on the image
			
			void FillRectangle(float F_X1, float F_Y1, float F_X2, float F_Y2, Color const& CL_COLOR = Color(255))
				{
				
				//-- We adjust the coordinates
				
				OrdonatePoints(F_X1, F_X2);
				OrdonatePoints(F_Y1, F_Y2);
				
				//-- We fill the rectangle
				
				for(short y = F_Y1; y <= F_Y2; y++)
					for(short x = F_X1; x <= F_X2; x++)
						DrawPixel(x,y,CL_COLOR);
				}
				
			//-- Function : Draw a cube on the image
			
			void DrawCube(float F_X, float F_Y, float F_C, Color const& CL_COLOR = Color(255))
				{
				
				//-- We draw it using a rectange
				
				DrawRectangle(F_X, F_Y, F_X + F_C, F_Y + F_C, CL_COLOR);
				}
				
			//-- Function : Draw a filled cube on the image
			
			void FillCube(float F_X, float F_Y, float F_C, Color const& CL_COLOR = Color(255))
				{
				
				//-- We draw it using a rectange
				
				FillRectangle(F_X, F_Y, F_X + F_C, F_Y + F_C, CL_COLOR);
				}
				
			//-- Function : Draw a triangle on the image
			
			void DrawTriangle(float const& F_X1, float const& F_Y1, float const& F_X2, float const& F_Y2, float const& F_X3, float const& F_Y3 , Color const& CL_COLOR = Color(255))
				{
				
				//-- We draw the shape using lines
				
				DrawLine(F_X1,F_Y1,F_X2,F_Y2);
				DrawLine(F_X2,F_Y2,F_X3,F_Y3);
				DrawLine(F_X3,F_Y3,F_X1,F_Y1);
				}
				
			//-- Function : Draw a filled triangle on the image
			
			void FillTriangle(float const& F_X1, float const& F_Y1, float const& F_X2, float const& F_Y2, float const& F_X3, float const& F_Y3 , Color const& CL_COLOR = Color(255))
				{
				
				//-- We prepare the searching area
				
				float F_XMIN = F_X1;
				float F_XMAX = F_X1;
				float F_YMIN = F_Y1;
				float F_YMAX = F_Y1;
				
				//-- We retrieve the min and the max
				
				if(F_X2 < F_XMIN)
					F_XMIN = F_X2;
				if(F_X3 < F_XMIN)
					F_XMIN = F_X3;
				if(F_X2 > F_XMAX)
					F_XMAX = F_X2;
				if(F_X3 > F_XMAX)
					F_XMAX = F_X3;
				if(F_Y2 < F_YMIN)
					F_YMIN = F_Y2;
				if(F_Y3 < F_YMIN)
					F_YMIN = F_Y3;
				if(F_Y2 > F_YMAX)
					F_YMAX = F_Y2;
				if(F_Y3 > F_YMAX)
					F_YMAX = F_Y3;
				
				//-- We retrieve the area of the triangle
				
				float F_AREA = round(AreaTriangle(F_X1, F_Y1, F_X2, F_Y2, F_X3, F_Y3));
				
				//-- We draw the shape
				
				for(short y = F_YMIN; y <= F_YMAX; y++)
					{
					for(short x = F_XMIN; x <= F_XMAX; x++)
						{
						
						//-- 
						
						float F_CURRENT_AREA = round(AreaTriangle(x, y, F_X2, F_Y2, F_X3, F_Y3) + AreaTriangle(F_X1, F_Y1, x, y, F_X3, F_Y3) + AreaTriangle(F_X1, F_Y1, F_X2, F_Y2, x, y));
						if(F_CURRENT_AREA <= F_AREA + 1)
							DrawPixel(x,y,CL_COLOR);
						}
					}
					
				//-- We add outlines
				
				DrawTriangle(F_X1, F_Y1, F_X2, F_Y2, F_X3, F_Y3);
				}
				
			//-- Function : Draw a parallepipede on the image
				
			void DrawTrapeze(float const& F_X1, float const& F_Y1, float const& F_X2, float const& F_Y2, float const& F_X3, float const& F_Y3, float const& F_X4, float const& F_Y4 , Color const& CL_COLOR = Color(255))
				{
				
				//-- We draw the shape using lines
				
				DrawLine(F_X1,F_Y1,F_X2,F_Y2);
				DrawLine(F_X2,F_Y2,F_X3,F_Y3);
				DrawLine(F_X3,F_Y3,F_X4,F_Y4);
				DrawLine(F_X4,F_Y4,F_X1,F_Y1);
				}
				
			//-- Function : Draw a filled parallepipede on the image
				
			void FillTrapeze(float const& F_X1, float const& F_Y1, float const& F_X2, float const& F_Y2, float const& F_X3, float const& F_Y3, float const& F_X4, float const& F_Y4 , Color const& CL_COLOR = Color(255))
				{
				
				//-- We draw the shape using lines
				
				FillTriangle(F_X1,F_Y1,F_X2,F_Y2,F_X3,F_Y3);
				FillTriangle(F_X1,F_Y1,F_X4,F_Y4,F_X3,F_Y3);
				}
				
			//-- Function : Draw a circle on the image
			
			void DrawCircle(float const& F_X, float const& F_Y, float const& F_R, Color const& CL_COLOR = Color(255))
				{
				
				//-- We draw the shape
				
				for(short y = F_Y - F_R; y <= F_Y + F_R; y++)
					for(short x = F_X - F_R; x <= F_X + F_R; x++)
						if(sqrt( (pow(y-F_Y,2)) + (pow(x-F_X,2)) ) <= F_R && sqrt( (pow(y-F_Y,2)) + (pow(x-F_X,2)) ) >= F_R - 1)
								DrawPixel(x,y,CL_COLOR);
				}
				
			//-- Function : Draw a filled circle on the image
			
			void FillCircle(float const& F_X, float const& F_Y, float const& F_R, Color const& CL_COLOR = Color(255))
				{
				
				//-- We draw the shape
				
				for(short y = F_Y - F_R; y <= F_Y + F_R; y++)
					for(short x = F_X - F_R; x <= F_X + F_R; x++)
						if(sqrt( (pow(y-F_Y,2)) + (pow(x-F_X,2)) ) <= F_R)
							DrawPixel(x,y,CL_COLOR);
				}
				
			//-- Function : Fill the entire image using a color
				
			void Clear(Color const& CL_COLOR = Color(255,255,255))
				{
				
				//-- We initialize those with values
				
				for(unsigned short y = 0; y < I_HEIGHT; y++)
					for(unsigned short x = 0; x < I_WIDTH; x++)
						CL_PIXELS[y][x].SetColor(CL_COLOR);
				}
				
			//-- Function : Save the image inside a ppm and png file

			bool Save(std::string const& S_PATH = "image.ppm", bool const& B_CONVERT = true)
				{
				//-- We try to open a file to save our image

				std::ofstream FS_IMAGE(S_PATH);

				//-- If we can we save it, else we return an error

				if(FS_IMAGE)
					{

					//-- We add the header of our image

					FS_IMAGE << "P3\n" << I_WIDTH << ' ' << I_HEIGHT << "\n255";
					
					//-- We add the pixels of our image

					for(unsigned short y = 0; y < I_HEIGHT; y++)
						for(unsigned short x = 0; x < I_WIDTH; x++)
							FS_IMAGE << '\n' << CL_PIXELS[y][x].GetColor() << " #";
					
					//-- We close the stream

					FS_IMAGE.close();
					
					//-- Conversion
					
					if(B_CONVERT)
						{
						
						//-- Depending on the OS, we run a different version of the code
						
						#ifdef linux
							std::string S_TEMPORARY = "pnmtopng "+S_PATH+" > "+S_PATH.substr(0,S_PATH.size()-3)+"png";
						#endif
						#ifdef _WIN32
							std::string S_TEMPORARY = "convert.exe "+S_PATH+" "+S_PATH.substr(0,S_PATH.size()-3)+"png";
						#endif

						//-- We convert our work

						std::system(S_TEMPORARY.c_str());
						}

					//-- Everything went smoothly

					return true;
					}
				else
					{
					
					//-- Something went wrong
					
					return false;
					}
				}
		private:
			
			//-- Function : Ordonate integers
			
			void OrdonatePoints(short& I_P1, short& I_P2) const
				{
				if(I_P1 > I_P2)
					{
					unsigned short I_EXCHANGE = I_P1;
					I_P1 = I_P2;
					I_P2 = I_EXCHANGE;
					}
				}
				
			//-- Function : Ordonate floats
			
			void OrdonatePoints(float& I_P1, float& I_P2) const
				{
				if(I_P1 > I_P2)
					{
					float I_EXCHANGE = I_P1;
					I_P1 = I_P2;
					I_P2 = I_EXCHANGE;
					}
				}
				
			//-- Function : Triangle Area
			
			float AreaTriangle(float const& F_X1, float const& F_Y1, float const& F_X2, float const& F_Y2, float const& F_X3, float const& F_Y3)
				{
				
				//-- We retrieve the values
				
				float d1 = sqrt( (pow(F_Y2-F_Y1,2)) + (pow(F_X2-F_X1,2)) );
				float d2 = sqrt( (pow(F_Y3-F_Y2,2)) + (pow(F_X3-F_X2,2)) );
				float d3 = sqrt( (pow(F_Y1-F_Y3,2)) + (pow(F_X1-F_X3,2)) );
				float s  = (d1 + d2 + d3) / 2;
				
				//-- We return the formula
				
				return sqrt(s * (s - d1) * (s - d2) * (s - d3));
				}
		
			//-- Dimensions of our image

			unsigned short I_WIDTH;
			unsigned short I_HEIGHT;

			//-- Our image

			Color **CL_PIXELS;
		};
	
	}
	
#endif
