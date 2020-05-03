#include "SVG.h"
#include "fun.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>


using namespace std;

void svg_line(double x_1, double y_1, double x_2, double y_2, size_t width)
{
 cout << "<line x1='"<<x_1<<"' y1='"<<y_1<<"' x2='"<<x_2<<"' y2='"<<y_2<<"' stroke='black' stroke-width='"<<width<<"'/>\n";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
 cout << "<rect x='"<< x << "' y='" <<y<<"' width='" <<width <<"' height='" <<height <<"' stroke='"<< stroke <<"' fill='"<<fill<<"'/>\n";
}

void svg_text(double left, double baseline, string text)
{
    char sst[10];
    strncpy(sst,text.c_str(),5);
    cout << "<text x='" << left << "' y='"<< baseline <<"'>"<<sst<<"</text>\n";
}

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

void svg_output(vector<vector<double>> max, vector<vector<double>> min, vector<vector<size_t>> Error, vector<size_t> M, size_t K, size_t N)
{
    auto const ot = 13;
    size_t y0=10, x0=10;
    size_t width;
    if(K>4)
        width=(K+2)*60;
    else
        width=600;
    size_t height=(y0+40*(K+3))*N+50*K;
    vector<size_t> x(6);
    for(size_t i=0;i<6;i++)
        x[i]=x0+60*i;
    vector<size_t> y(K+3);
    svg_begin(width, height);
    for(size_t z=0;z<N;z++)
    {
      for(size_t i=0;i<K+3;i++)
      {
          y[i]=y0+i*40;
          svg_line(x[0],y[i],x[5],y[i], 1);
      }
      svg_text(x[0]+ot,y[0]+ot,"N=");
      string str = to_string(z+1);
      svg_text(x[0]+ot*3,y[0]+ot, str);
      svg_text(x[0]+ot,y[1]+ot,"M");
      svg_text(x[1]+ot,y[1]+ot,"max");
      svg_text(x[2]+ot,y[1]+ot,"min");
      svg_text(x[3]+ot,y[1]+ot,"dX");
      svg_text(x[4]+ot,y[1]+ot,"Error");
      for(size_t i=0;i<K;i++)
      {
        str = to_string(M[i]);
        svg_text(x[0]+ot,y[i+2]+ot,str);
        str = to_string(max[i][z]);
        svg_text(x[1]+ot,y[i+2]+ot,str);
        str = to_string(min[i][z]);
        svg_text(x[2]+ot,y[i+2]+ot,str);
        str = to_string(max[i][z]-min[i][z]);
        svg_text(x[3]+ot,y[i+2]+ot,str);
        if(Error[i][z]>0)
            svg_text(x[4]+ot,y[i+2]+ot,"-");
        else
            svg_text(x[4]+ot,y[i+2]+ot,"+");
      }
      svg_line(x[0],y[0],x[0],y[K+2], 1);
      svg_line(x[1],y[1],x[1],y[K+2], 1);
      svg_line(x[2],y[1],x[2],y[K+2], 1);
      svg_line(x[3],y[1],x[3],y[K+2], 1);
      svg_line(x[4],y[1],x[4],y[K+2], 1);
      svg_line(x[5],y[0],x[5],y[K+2], 1);

      y0=y[K+2]+10;
    }
    vector<size_t> x1(K+2);
    vector<size_t> y1(3);
    for(size_t i=0;i<3;i++)
    {
        y1[i]=y0+i*40;
    }
    for(size_t i=0;i<K+2;i++)
    {
        x1[i]=x0+i*60;
        svg_line(x1[i],y1[0],x1[i],y1[2], 1);
    }
    svg_line(x1[0],y1[0],x1[K+1],y1[0], 1);
    svg_line(x1[0],y1[1],x1[K+1],y1[1], 1);
    svg_line(x1[0],y1[2],x1[K+1],y1[2], 1);
    svg_text(x1[0]+ot,y1[0]+ot,"M");
    svg_text(x1[0]+ot,y1[1]+ot,"Error");
    for(size_t i=0;i<K;i++)
    {
      for(size_t j=1;j<N;j++)
      {
        Error[i][0]=Error[i][j]+Error[i][0];
      }
    }
    for(size_t i=0;i<K;i++)
    {
       string str;
       str = to_string(M[i]);
       svg_text(x1[i+1]+ot,y1[0]+ot,str);
       str = to_string(Error[i][0]);
       svg_text(x1[i+1]+ot,y1[1]+ot,str);
    }
    svg_end();
}
