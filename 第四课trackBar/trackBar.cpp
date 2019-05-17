#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
using namespace cv;
using namespace std;

//点击鼠标gray +5 and show , 1 channel
#define WINDOW "fan kai yuan image"
Mat src;
int red,blue, green,alpha;
void On_mouse(int event, int x, int y, int flags, void*);

static void on_trackbar(int, void*)
{
    Mat L(150,200, CV_8UC3, Scalar(blue ,green,red));
	imshow(WINDOW, L );

}

int main()
{
    Scalar s;
    Mat L(150,200, CV_8UC3, Scalar(0,0,0,100));
	L.copyTo(src);
    cout<<"channel="<<L.channels()<<endl;
    //cout<<src.channels()<<endl;
    namedWindow(WINDOW, WINDOW_NORMAL);
	createTrackbar( "red", WINDOW, &red, 255, on_trackbar );
	createTrackbar( "blue", WINDOW, &blue, 255, on_trackbar );
	createTrackbar( "green", WINDOW, &green, 255, on_trackbar );
   // while(1){
  	  imshow(WINDOW, src);
  	cv::waitKeyEx(0);
  	cout<<"haha\n";
   // }

    return 0;
}


