
#include "../turtlec.h"
#include <CSFML/System/Vector2.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

 void fractalTree ( Turtle * turtle , float length , int depth ) {
   if ( depth == 0 || length < 5) return ;

   turtleForward ( turtle , length ) ;
   turtleLeft ( turtle , 30) ;

   fractalTree ( turtle , length * 0.7 , depth - 1) ;
   turtleRight ( turtle , 60) ;

   fractalTree ( turtle , length * 0.7 , depth - 1) ;
   turtleLeft ( turtle , 30) ;

   turtleBackward ( turtle , length ) ;
 }

int main(void) {
  float width = 600;
  float height = 600;
  TurtleApp *app = turtleAppCreate(width, height, "Test Line");
  float velocity = 10;
  if(app == NULL)
    return 1;
  Turtle *t = turtleAppGetTurtle(app);
  turtleSetSpeed(t, velocity);
  int n = width / 100;
  int side = width / n;
  turtleLeft(t, -90);
  fractalTree(t, side, 5);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
