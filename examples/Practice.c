#include "../turtlec.h"
#include <CSFML/System/Vector2.h>
#include <CSFML/Window/Event.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// my own algorithm of a tree with two tree or n leaves
void drawFractalTree (Turtle * t, float side, int depth) {
  if (depth == 0 ) return ;

  turtleForward(t, side);
  // First leaf
  turtleLeft(t, 45);
  drawFractalTree(t, side * 0.7, depth - 1);
  turtleRight(t, 45);

  turtleBackward(t, side);
  //Center leaf
  // turtleForward(t, side);

  // drawFractalTree(t, side * 0.7, depth-1);

  // turtleBackward(t, side);

  //Right leaf
  turtleForward(t, side);

  turtleRight(t, 45);
  drawFractalTree(t, side * 0.7, depth - 1);
  turtleLeft(t, 45);

  turtleBackward(t, side);
}

struct Colors {
  char r ;
  char g ;
  char b;
};



struct Colors colors[] = {
     {255, 0,   0},     // red
     {255, 128, 0},     // orange
     {255, 255, 0},     // yellow
     {128, 255, 0},     // lime
     {0,   255, 0},     // green
     {0,   255, 128},   // spring green
     {0,   255, 255},   // cyan
     {0,   128, 255},   // azure
     {0,   0,   255},   // blue
     {128, 0,   255},   // violet
     {255, 0,   255},   // magenta
     {255, 0,   128},   // pink
     {255, 255, 255},   // white
     {192, 192, 192},   // light gray
     {128, 128, 128},   // gray
     {64,  64,  64},     // dark gray
     {0,   0,   0},     // black
     {128, 64,  0},     // brown
     {0,   128, 128},   // teal
     {128, 0,   0},     // maroon
 };


// I improve my tree deleting some backwards
void drawFractalTwo (Turtle * t , float side , unsigned int depth)  {
  if (depth == 0 ) return ;

  turtleSetColor(t, colors[depth].r, colors[depth].g, colors[depth].b);
  turtleForward(t, side);

  turtleLeft (t , 45);
  drawFractalTwo(t, side * 0.7 , depth-1 );

  turtleRight(t, 45);
  drawFractalTwo(t, side * 0.7 , depth-1 );

  turtleRight(t, 45);
  drawFractalTwo(t, side * 0.7 , depth-1 );

  turtleLeft(t, 45);
  turtleSetColor(t, colors[depth].r, colors[depth].g, colors[depth].b);
  turtleBackward(t, side);
}



void fractalTree ( Turtle * turtle , float length , int depth ) {
  if (depth == 0) return ;

  turtleForward ( turtle , length ) ;
  turtleLeft ( turtle , 30) ;

  fractalTree ( turtle , length * 0.7 , depth - 1) ;
  turtleRight ( turtle , 60) ;

  fractalTree ( turtle , length * 0.7 , depth - 1) ;
  turtleLeft ( turtle , 30) ;

  turtleBackward ( turtle , length ) ;
}


void levy ( Turtle * turtle , float length , int depth ) {
  if( depth == 0) {
    turtleForward ( turtle , length ) ;
    return ;
  }

  turtleLeft ( turtle , 45) ;
  levy ( turtle , length / sqrt (2) , depth - 1) ;

  turtleRight ( turtle , 90) ;
  levy ( turtle , length / sqrt (2) , depth - 1) ;

  turtleLeft ( turtle , 45) ;
}

int main(void) {
  float width = 600;
  float height = 600;
  TurtleApp *app = turtleAppCreate(width, height, "Test Line");
  float velocity = 100;
  if(app == NULL)
    return 1;
  Turtle *t = turtleAppGetTurtle(app);
  turtleSetSpeed(t, velocity);
  int n = width / 100;
  int side = width / n;
  //turtlePenUp(t);
  //turtleGoTo(t, width/2, height);
  turtlePenDown(t);
  turtleLeft(t, 90);
  //fractalTree(t, 100, 2);
  drawFractalTwo(t, side, 3);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
