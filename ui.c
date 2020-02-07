#include <stdio.h>
#include "xstuff.h"
#include "ui.h"



void simple_init(int x, int y, unsigned width, unsigned height)
{
  xwin_init();
  initapp(1, NULL, x, y, width, height);
}

void init_display(int argc, char ** argv, int x, int y, unsigned width, unsigned height)
{
  xwin_init();
  initapp(argc, argv, x, y, width, height);

}

void draw_rect(int x1, int y1, int x2, int y2) {
  int width=x2-x1;
  int height=y2-y1;
  XDrawRectangle(theDisplay, theMain, theGC, x1, y1, width, height);
  XFlush(theDisplay);
}

void draw_point(int x, int y)
{
  XArc arc;
  arc.x = x;
  arc.y = y;
  arc.height = 80;
  arc.width = 80;

  
  XSetForeground(theDisplay, theGC, black.pixel);
  //XDrawPoint(theDisplay, theMain, theGC, x, y);
  XDrawArcs(theDisplay,theMain,theGC,&arc,1);
  //XFillArcs(theDisplay,theMain,theGC,&arc,0);
  
//  flush_display(theDisplay);
//  XSetForeground(theDisplay, theGC, black.pixel);
}

void draw_red_point(int x, int y)
{
  XSetForeground(theDisplay, theGC, black.pixel);
  XDrawPoint(theDisplay, theMain, theGC, x, y);
  XFlush(theDisplay);
  XSetForeground(theDisplay, theGC, black.pixel);
}

void flush_display()
{
  XFlush(theDisplay);
}

void clear_display() {
  XClearWindow(theDisplay, theMain);
  XFlush(theDisplay);
}


void close_display()
{
  XCloseDisplay(theDisplay);
}
