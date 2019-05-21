#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
using namespace cv;
using namespace std;
#define WINDOW "vertical concat image"
int main() {

	std::vector<Scalar> color;
	color.push_back(Scalar(255, 0, 0));
	color.push_back(Scalar(0, 255, 0));
	color.push_back(Scalar(0, 0, 255));
	color.push_back(Scalar(0, 255, 255));
	color.push_back(Scalar(255, 0, 25));
	color.push_back(Scalar(255, 0, 255));
	int scale = 6;
	Mat v0(15 * scale, 100 * scale, CV_8UC3, color[0]);
	Mat v1(15 * scale, 100 * scale, CV_8UC3, color[1]);
	Mat v2(15 * scale, 100 * scale, CV_8UC3, color[2]);
	Mat v3(15 * scale, 100 * scale, CV_8UC3, color[3]);
	Mat v4(15 * scale, 100 * scale, CV_8UC3, color[4]);
	Mat v5(15 * scale, 100 * scale, CV_8UC3, color[5]);

	Mat v, image;

//hconcat(v0,v1,v1);//水平拼接
//vconcat
	vconcat(v0, v1, image);
	vconcat(image, v2, image);
	vconcat(image, v3, image);
	vconcat(image, v4, image);
	vconcat(image, v5, image);

	//hconcat(v0, v1, h);
	int height = image.size().height/2;
	int width = image.size().width/2;
	int radius =( height>width? width:height);
	radius = radius-scale;
	circle(image, Point(width,height),  radius,Scalar(255,255,255),100,-1);
	radius = radius*2/3;
	circle(image, Point(width,height),  radius,Scalar(255,255,255),-1,LINE_AA);
	namedWindow(WINDOW, WINDOW_NORMAL);
	imshow(WINDOW, image);
	cv::waitKeyEx(0);
	/*
	 *
	 *
	 * 		double dist = cv::pointPolygonTest(*itc, cv::Point2f(rt,rk), true);
					ROS_INFO("dist %f",dist);
					if( dist >= BOX_PCL_TH)
					{
						int index = rk*cloud.width + rt;
						if (index < cloud.points.size())
							boxcloud.points.push_back(cloud.points[index]);
					}
	 * */
	return 0;
}


