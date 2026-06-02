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


// I improve my tree deleting some backwards
void drawFractalTwo (Turtle * t , float side , unsigned int depth)  {
  if (depth == 0 ) return ;

  turtleForward(t, side);

  turtleLeft (t , 45);
  drawFractalTwo(t, side * 0.7 , depth - 1);

  turtleRight(t, 90);
  drawFractalTwo(t, side * 0.7 , depth - 1);

  turtleLeft(t, 45);
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
  drawFractalTwo(t, side, 6);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
