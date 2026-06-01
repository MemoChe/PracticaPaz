#include "../turtlec.h"
#include <CSFML/System/Vector2.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

static const float PI = 3.14159265359f;

void starRecursive (float posx, float posy, unsigned int side, Turtle * t, int drawsides) {
  if (drawsides == 0) return;
  turtlePenUp(t);
  turtleGoTo(t, posx, posy);
  turtlePenDown(t);
  turtleForward(t, side);
  turtleRight(t, 144);
  starRecursive(t->pos.x, t->pos.y, side, t, drawsides-1);
  t->heading = 0;
}

void treeRecursive (float posx, float posy, double anglel , double angler, unsigned side, Turtle *t , int nivel) {
  if (nivel == 0)  return ;
  turtlePenDown(t);
  turtleGoTo(t, posx, posy);
  turtlePenUp(t);
  treeRecursive( posx + (float) side * cosf( anglel * PI/180), posy + side * sinf(anglel * PI/180), anglel - 45, anglel + 45,  side * sinf(45 * PI/ 180), t, nivel-1);
  turtlePenUp(t);
  turtleGoTo(t, posx, posy);
  turtlePenDown(t);
  treeRecursive( posx + (float) side  * cosf( angler * PI/180), posy + side * sinf(angler * PI/180), angler - 45 , angler + 45, side * sinf(45 * PI/ 180), t, nivel-1);
  turtlePenUp(t);
}

void drawHexagon (Turtle * t, float posx , float posy , unsigned int side, int sides){
  float c1 = 25;
  float c2 = 50;
  float h = sqrt(pow(c1, 2) + pow(c2, 2));
  float b = asinf(c2/h);
  float a = asinf(c1/h);
  printf("(h=%f)(a=%f)(b=%f)", h,a*180/PI, b*180/PI);
  turtlePenUp(t);
  turtleGoTo(t, posx, posy);
  turtleForward(t, c1);
  turtlePenDown(t);
  turtleForward(t, side-2*c1);
  turtleRight(t, b*180/PI);
  turtleForward(t, h);
  turtleRight(t, 2*a*180/PI);
  turtleForward(t, h);
  turtleRight(t, b*180/PI);
  turtleForward(t, side-2*c1);
  turtleRight(t, b*180/PI);
  turtleForward(t, h);
  turtleRight(t, 2*a*180/PI);
  turtleForward(t, h);
  turtlePenUp(t);
  t->heading = 0;
}


void drawCircle (Turtle * t, float posx, float posy, float radius){
  posx+= radius;
  posy+= radius;
  turtlePenUp(t);
  turtleGoTo(t, posx + radius*cosf(0), posy + radius*sinf(0));
  turtlePenDown(t);
  for (int i =0 ; i <= 360; i+=10) {
    turtleGoTo(t, posx + radius*cosf(i*PI/180), posy + radius*sinf(i*PI/180));
  }
  turtlePenUp(t);
}

void drawCircle2 (Turtle * t, float posx, float posy, float radius){
  int steps = 10;
  turtlePenUp(t);
  turtleGoTo(t, posx + radius, posy );
  t->heading = steps / 2.0f;
  turtlePenDown(t);
  float movement = 2 * radius * sinf(steps * PI / 360.0f);
  for (int i =steps ; i <= 360; i+=steps) {
    turtleForward(t, movement);
    turtleRight(t, steps);
  }
  turtlePenUp(t);
  t->heading = 0;
}



void drawOctagon (Turtle * t ,int posx, int posy , int side, int movement){
  float angle = 45;
  turtlePenUp(t);
  turtleGoTo(t, posx, posy);
  turtleForward(t, movement);
  turtlePenDown(t);
  int even = 0;
  for (int i =0 ; i < 8 ; i++) {
    if (even){
      turtleForward(t, movement*sqrt(2));
      even = 0;
    }else{
      turtleForward(t, 100-2*movement);
      even = 1;
    }
    turtleRight(t, angle);
  }
  turtlePenUp(t);
}


void drawGrid (Turtle * t, int side, int n) {
  for (int i =0 ; i< n ; i++){
    for (int j =0 ; j < n ; j++) {
      turtlePenUp(t);
      turtleGoTo(t, j*side, i*side);
      for (int i =0 ; i< 4 ; i++) {
        turtlePenDown(t);
        turtleForward(t, side);
        turtleRight(t, 90);
        turtlePenDown(t);
      }
    }
  }
  t->heading = 0;
}


void DrawClock (Turtle * t, float posx, float posy, float radius) {
  turtleRight(t, 180);
  turtleSetSpeed(t, 2);
  for (int i =0 ; i <= 360; i +=30) {
    turtlePenUp(t);
    turtleGoTo(t, posx + radius*cosf(i*PI/180), posy + radius*sinf(i*PI/180));
    turtlePenDown(t);
    turtleForward(t, 20);
    turtlePenUp(t);
    turtleRight(t,30);

  }
  t->heading = 0;
}

void DrawClockRecursive (Turtle * t , float posx, float posy, float radius){
  if (fabsf(t->heading-360)<0.5) return;
  turtlePenUp(t);
  turtleGoTo(t, posx + radius * cosf(t->heading*PI/180), posy + radius * sinf(t->heading*PI/180));
  turtlePenDown(t) ;
  turtleBackward(t , 20);
  turtleRight(t , 30);
  DrawClockRecursive(t, posx, posy, radius);
  t->heading = 0;
}



void drawTriangle ( Turtle * t , float posx , float posy, float side ) {
  t->heading = 0;
  turtlePenUp(t);
  turtleGoTo(t, posx, posy);
  turtlePenDown(t);
  turtleGoTo(t, posx+side, posy);
  turtleGoTo(t, posx+side/2, posy-side);
  turtleGoTo(t, posx, posy);
  turtlePenUp(t);
}

void drawFractalTriangle (Turtle * t , float posx, float posy, float side, int nivel) {
  if (nivel == 0) return;
  drawTriangle(t, posx, posy, side);
  drawFractalTriangle(t, posx, posy,side/2, nivel-1);
  drawFractalTriangle(t, posx + side/4,posy-side/2, side/2, nivel-1);
  drawFractalTriangle(t, posx + side/2,posy, side/2, nivel-1);
}



int main(void){
  float width = 600;
  float height = 600;
  TurtleApp *app = turtleAppCreate(width, height, "Test Line");
  float velocity = 40;
  if(app == NULL)
    return 1;
  Turtle *t = turtleAppGetTurtle(app);
  turtleSetSpeed(t, velocity);
  int n = width / 100;
  int side = width / n;
  // drawGrid(t, side, n);
  // DrawClock(t, t->pos.x, t->pos.y , side);
  //DrawClockRecursive(t, t->pos.x, t->pos.y, side);
  // int sides = 6;
  // for (int i =0 ; i < n ; i++) {
  //   for (int j =0 ; j < n; j++) {
  //     //drawHexagon(t, j*side , i*side, 100, 6);
  //     //drawOctagon(t, j*side, i*side, 60,100/3);
  //     drawCircle2(t, j*side, i*side, side/2);
  //   }
  // }
  //starRecursive(width/2-50, height/2, 300, t, 5);
  // turtlePenUp(t);
  // turtleGoTo(t, width/2, height);
  // turtlePenDown(t);
  // turtleGoTo(t, width/2, height - 100);
  // turtlePenUp(t);
  //treeRecursive(width/2, height - 100, -135, -45, 100, t, 8);
  //drawFractalTriangle(t, 250, 400, 200, 6);
  turtleAppRun(app);
  turtleAppDestroy(app);



  return 0;
}
