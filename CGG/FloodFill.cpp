#include<stdio.h> 
#include<stdlib.h> 
#include<graphics.h> 

void flood(int x,int y,int fillColor, int bgColor)  
{  
    if(getpixel(x,y)==bgColor)  
    {  
        putpixel(x,y,fillColor);  
        flood(x+1,y,fillColor,bgColor);  
        flood(x-1,y,fillColor,bgColor);  
        flood(x,y+1,fillColor,bgColor);  
        flood(x,y-1,fillColor,bgColor);  
    }  
}  

void boundaryFill(int x, int y, int fill_color,int boundary_color)
{
    if(getpixel(x, y) != boundary_color &&
       getpixel(x, y) != fill_color)
    {
        putpixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

int main() 
{ 
 int gd = DETECT, gm;
 initgraph(&gd, &gm, NULL); 

// triangle
 line(300,100,400,200);
 line(300,100,200,200);
 line(200,200,400,200); 

// side 2 line
 line(200,200,200,400);
 line(400,200,400,400);

// horizontal last line
 line(200,400,400,400);

 // door
 line(270,300,270,400);
 line(330,300,330,400);
 line(270,300,330,300);

 //circle
 circle(300,160,20);

 // window
 line(330,250,330,270);
 line(380,250,380,270);

 line(330,250,380,250);
 line(330,270,380,270);

 line(330,260,380,260);
 line(355,250,355,270);

 //sun
 circle(100,110,40);

 flood(300,110,6,0);

 // fill wall
 flood(300, 220, 1, 0);

 

 delay(500000); 
 closegraph(); 
 return 0; 
}
