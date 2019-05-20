#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
using namespace cv;
using namespace std;

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

	Mat v, h;

//hconcat(v0,v1,v1);//水平拼接
//vconcat
	vconcat(v0, v1, h);
	vconcat(h, v2, h);
	vconcat(h, v3, h);
	vconcat(h, v4, h);
	vconcat(h, v5, h);

	//hconcat(v0, v1, h);
	int he = h.size().height/2;
	int wi = h.size().width/2;
	int r =( he>wi? wi:he);
	r = r-scale;
	circle(h, Point(wi,he),  r,Scalar(255,255,255),100,-1);
	r = r*2/3;
	circle(h, Point(wi,he),  r,Scalar(255,255,255),-1,LINE_AA);
	imshow("hc", h);
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


