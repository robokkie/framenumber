//
//  main.cpp
//  Realtime_anomaly_detection
//
//  Created by KurokiRyohei on 2015/01/13.
//  Copyright (c) 2015年 KurokiRyohei. All rights reserved
//


#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>

#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	//arrow key code in windows
	//const int CV_WAITKEY_CURSORKEY_RIGHT = 2555904;
	//const int CV_WAITKEY_CURSORKEY_LEFT = 2424832;

	string input_video = "/Users/Ryohei/OneDrive/Research/Projects/videos/hukan/anomaly.mp4";
	
	if (argc > 1)
	{
		input_video = argv[1];
	}

	Mat frame;
	int frnum=0;
	cv::VideoCapture capture = cv::VideoCapture(input_video);
	
	int frames = capture.get(CV_CAP_PROP_FRAME_COUNT);
	frnum = (int)frames / 2;

	cout << "total frame number:" << frames << std::endl;
	capture >> frame;
	if (frame.empty())
		return 1;

	namedWindow("frame", CV_WINDOW_AUTOSIZE);
	
	while (true){
		if (frnum < 0)
		{
			frnum = 0;
		}
		else if (frnum >= frames)
		{
			frnum = frames - 1;
		}

		capture.set(CV_CAP_PROP_POS_FRAMES, frnum);
		
		capture >> frame;
		stringstream ss;
		ss << frnum;
		string frnum_str = ss.str();
		cv::putText(frame, frnum_str, cv::Point(50, 50), FONT_HERSHEY_COMPLEX, 1.2, cv::Scalar(0, 0, 200), 2, CV_AA);
		imshow("frame", frame);
		cvWaitKey(10);

		int c = cv::waitKey();
		if (c == 'q')
		{
			break;
		}
		if (c == 'j')
		{
			frnum--;
		}
		if (c == 'k')
		{
			frnum++;
		}
		if (c == 'n')
		{
			cv::putText(frame, "put number to console", cv::Point(50, 100), FONT_HERSHEY_COMPLEX, 1.2, cv::Scalar(0, 0, 200), 2, CV_AA);
			imshow("frame", frame);
			cv::waitKey(10);
			cin >> frnum;
		}
	}

	return 0;
}

