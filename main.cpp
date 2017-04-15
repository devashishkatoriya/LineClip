//Program to Show the working of Cohen-Sutherland Line-Clipping Algorithm

#include <iostream>
#include <graphics.h>

using namespace std;

//Variable Declarations
static int ABOVE = 8,
           BELOW = 4,
           RIGHT = 2,
            LEFT = 1;
int xh,yh,xl,yl;

//GetCode function
int getCode(int x,int y)
{
    int code = 0;
    if(y > yh)
        code |= ABOVE;
    if(y < yl)
        code |= BELOW;
    if(x > xh)
        code |= RIGHT;
    if(x < xl)
        code |= LEFT;
    return code;
}


int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    char ch;
    int x1,x2,y1,y2,outCode1,outCode2;
    cout<<"\nEnter the windows co-ordinates :- \n";
    cin>>xl>>yl>>xh>>yh;

    //xl = yl = 100;
    //xh = yh = 400;

    setcolor(BLUE);
    rectangle(xl,yl,xh,yh);
    do
    {
        ch = 'n';
        cout<<"\nEnter the line co-ordinates :- \n";
        cin>>x1>>y1>>x2>>y2;
        setcolor(BLUE);
        line(x1,y1,x2,y2);

        outCode1 = getCode(x1,y1);
        outCode2 = getCode(x2,y2);

        //Both points are inside
        if(outCode1 == 0 && outCode2 == 0)
        {
            setcolor(WHITE);
            line(x1,y1,x2,y2);
        }
        //If ANDing returns nonzero value then partially visible lines
        else if((outCode1&outCode2)==0)
        {
            int x3,y3,x4,y4;
            float m;
            if(x1<xl)
            {
                x3 = xl;
                m = (y1-y2)/(x1-x2);
                y3 = m*(x3-x1) + y1;


            }
            else if(x1>xh)
            {
                x3 = xh;
                m = (y1-y2)/(x1-x2);
                y3 = m*(x3-x1) + y1;
            }
            else
            {
                x3 = x1;

                if(y1<yl)
                {
                    y3 = yl;
                    m = (x1-x2)/(y1-y2);
                    x3 = m*(y3-y1) + x1;


                }
                else if(y1>yh)
                {
                    y3 = yh;
                    m = (x1-x2)/(y1-y2);
                    y3 = m*(y3-y1) + x1;
                }
                else
                {
                    y3 = y1;
                }

                if(y2<yl)
                {
                    y4 = yl;
                    m = (x1-x2)/(y1-y2);
                    x4 = m*(y4-y2) + x2;
                }
                else if(y1>yh)
                {
                    y4 = yh;
                    m = (x1-x2)/(y1-y2);
                    y4 = m*(y4-y2) + x2;
                }
                else
                {
                    y4 = y2;
                }
            }

            if(x2<xl)
            {
                x4 = xl;
                m = (y1-y2)/(x1-x2);
                y4 = m*(x4-x2) + y2;
            }
            else if(x2>xh)
            {
                x4 = xh;
                m = (y1-y2)/(x1-x2);
                y4 = m*(x4-x2) + y2;
            }
            else
            {
                x4 = x2;
                if(y1<yl)
                {
                    y3 = yl;
                    m = (x1-x2)/(y1-y2);
                    x3 = m*(y3-y1) + x1;


                }
                else if(y1>yh)
                {
                    y3 = yh;
                    m = (x1-x2)/(y1-y2);
                    y3 = m*(y3-y1) + x1;
                }
                else
                {
                    y3 = y1;
                }

                if(y2<yl)
                {
                    y4 = yl;
                    m = (x1-x2)/(y1-y2);
                    x4 = m*(y4-y2) + x2;
                }
                else if(y1>yh)
                {
                    y4 = yh;
                    m = (x1-x2)/(y1-y2);
                    y4 = m*(y4-y2) + x2;
                }
                else
                {
                    y4 = y2;
                }
            }

            setcolor(WHITE);
            line(x3,y3,x4,y4);
        }
        //ANDing returns ZERO value
        else
        {
            //means both pts are outside
        }

        cout<<"\nDo you want to continue (y/n) ? ";
        cin>>ch;
    }while(ch!='n');

    closegraph();
    cout<<"\nThank you for using this program :) ";
    return 0;
}

//Sample Points
//  50 200 450 200
//  50 50 150 150
//  50 50 450 450