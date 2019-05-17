#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
using namespace cv;
using namespace std;

//点击鼠标gray +5 and show , 1 channel
#define WINDOW "fan kai yuan image"
Mat src;
void On_mouse(int event, int x, int y, int flags, void*);

int gray;
int main()
{
    Scalar s;
    Mat L(150,200, CV_8UC1, Scalar(0));
	L.copyTo(src);
    cout<<"channel="<<L.channels()<<endl;
    //cout<<src.channels()<<endl;
    namedWindow(WINDOW, WINDOW_NORMAL);
    setMouseCallback(WINDOW, On_mouse);
   // while(1){
  	  imshow(WINDOW, src);
  	cv::waitKeyEx(0);
  	cout<<"haha\n";
   // }

    return 0;
}
void On_mouse(int event, int x, int y, int flags, void*)
{
    if (event == EVENT_LBUTTONDOWN   )
    {
        gray+=15;
        if(gray>255) gray=0;
        Mat L(150,200, CV_8UC1, Scalar(gray));
    	  L.copyTo(src);
      	  imshow(WINDOW, src);
    	  cout<<__LINE__<<endl;
		//printf("%d,%d\n",x,y);
    }
}

