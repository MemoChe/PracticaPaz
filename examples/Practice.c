
#include "../turtlec.h"
#include <CSFML/System/Vector2.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

 void fractalTree ( Turtle * turtle , float length , int depth ) {
   if ( depth == 0 || length < 5) return ;

   if( depth > 3) turtleSetColor ( turtle , 120 , 70 , 20) ;
   else turtleSetColor ( turtle , 0 , 200 , 0) ;
   turtleForward ( turtle , length ) ;
   turtleLeft ( turtle , 30) ;
   if( depth > 1) turtleSetColor ( turtle , 120 , 70 , 20) ;
   else turtleSetColor ( turtle , 0 , 200 , 0) ;
   fractalTree ( turtle , length * 0.7 , depth - 1) ;
   turtleRight ( turtle , 60) ;
   if( depth > 1) turtleSetColor ( turtle , 120 , 70 , 20) ;
   else turtleSetColor ( turtle , 0 , 200 , 0) ;
   fractalTree ( turtle , length * 0.7 , depth - 1) ;
   turtleLeft ( turtle , 30) ;
   if( depth > 1) turtleSetColor ( turtle , 120 , 70 , 20) ;
   else turtleSetColor ( turtle , 0 , 200 , 0) ;
   turtleBackward ( turtle , length ) ;
 }

int main(void) {
  float width = 600;
  float height = 600;
  TurtleApp *app = turtleAppCreate(width, height, "Test Line");
  float velocity = 1000;
  if(app == NULL)
    return 1;
  Turtle *t = turtleAppGetTurtle(app);
  turtleSetSpeed(t, velocity);
  int n = width / 100;
  int side = width / n;
  turtlePenUp(t);
  turtleGoTo(t, width/2, height);
  turtlePenDown(t);
  turtleLeft(t, 90);
  fractalTree(t, side, 5);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
