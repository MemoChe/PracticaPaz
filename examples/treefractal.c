#include "../turtlec.h"
#include <CSFML/System/Vector2.h>
#include <stdbool.h>


void drawFractalTree (Turtle * t, float side, int depth) {
  if (depth == 0 ) return ;

  turtleForward(t, side);

  turtleLeft(t, 45);
  drawFractalTree(t, side * 0.7, depth - 1);
  turtleRight(t, 45);
  turtleBackward(t, side);

  turtleForward(t, side);
  drawFractalTree(t, side * 0.7, depth-1);
  turtleBackward(t, side);

  turtleForward(t, side);
  turtleRight(t, 45);
  drawFractalTree(t, side * 0.7, depth - 1);
  turtleLeft(t, 45);
  turtleBackward(t, side);

}




int main(void) {
  float width = 600;
  float height = 600;
  TurtleApp * app = turtleAppCreate(width, height, "Laboratory");
  float velocity = 1000;
  if(app == NULL) return 1;
  Turtle *t = turtleAppGetTurtle(app);
  turtleSetSpeed(t, velocity);
  int n = width / 100;
  int side = width / n;
  turtleLeft(t, 90);
  drawFractalTree(t, side, 10);
  turtleAppRun(app);
  turtleAppDestroy(app);

  return 0;
}
