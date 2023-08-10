#include<stdio.h> 
#include<stdlib.h> 
#include<graphics.h> 

int main() 
{ 
 int gd = DETECT, gm;
 initgraph(&gd, &gm, NULL); 

 // circle(50, 50, 30); 


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

 line(100,160,100,190);
 line(70,160,60,180);
 line(50,110,30,110);

 line(100,50,100,20);
 line(160,110,190,110);





 delay(500000); 
 closegraph(); 
 return 0; 
}

