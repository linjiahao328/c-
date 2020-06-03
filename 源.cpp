//
//  main.cpp
//  �ƶ�����ʶ��
//
//  Created by ywy on 2016/10/10.
//  Copyright ? 2016�� Swallow. All rights reserved.
//


#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>

#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;


Mat frame; //��ǰ֡
Mat fgMaskMOG2; //ͨ��MOG2�����õ�������ͼ��fgmask
Mat segm;      //frame�ĸ���

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;
Ptr<BackgroundSubtractor> pMOG2; //MOG2 Background subtractor

//����������Ƶ��������
void processVideo();

int main()
{
    //namedWindow("Original Frame");
    //namedWindow("After MOG2");

    //create Background Subtractor objects
    pMOG2 = createBackgroundSubtractorMOG2();

    processVideo();

    destroyAllWindows();
    return 0;
}


void processVideo() {

    VideoCapture capture(0); //����Ϊ0��Ĭ�ϴ�����ͷ��ȡ��Ƶ

    if (!capture.isOpened()) {
        cout << "Unable to open the camera! " << endl;
        exit(EXIT_FAILURE); //EXIT_FAILURE ������Ϊexit()�Ĳ�����ʹ�ã���ʾû�гɹ���ִ��һ������,��ֵΪ1
    }

    while (true) {

        if (!capture.read(frame)) {
            cout << "Unable to read next frame." << endl;
            exit(0);
        }

        //�Ի������һ�������ţ����㴦��
        double scale = 1.3;         //���ű���
        Mat smallImg(frame.rows / scale, frame.cols / scale, CV_8SC1);
        resize(frame, frame, smallImg.size(), 0, 0, INTER_LINEAR);


        pMOG2->apply(frame, fgMaskMOG2);    //���±���ģ��
        frame.copyTo(segm);             //����һ����ǰframe�ĸ���
        findContours(fgMaskMOG2, contours, hierarchy,
            CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0)); //�������

        vector <vector<Point> > contours_poly(contours.size());
        vector <Point2f> center(contours.size());
        vector <float> radius(contours.size());
        for (int i = 0; i < contours.size(); i++) {
            //findContours���������Ϣcontours���ܹ��ڸ��Ӳ�ƽ����������approxPolyDP�����Ըö�����������ʵ�����
            approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
            //�õ������������Բ
            minEnclosingCircle(contours_poly[i], center[i], radius[i]);
        }
        //�����õ�����������һ����ɸѡ
        for (int i = 0; i < contours.size(); i++) {
            if (contourArea(contours[i]) > 500) {
                circle(segm, center[i], (int)radius[i], Scalar(100, 100, 0), 2, 8, 0);
                break;
            }
        }

        //get the frame number and write it on the current frame
        stringstream ss;
        //        rectangle(frame, cv::Point(10, 2), cv::Point(100,20),
        //                  cv::Scalar(255,255,255), -1);
        ss << capture.get(CAP_PROP_POS_FRAMES);
        string frameNumberString = ss.str();
        putText(frame, frameNumberString.c_str(), cv::Point(15, 15),
            FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));

        //��ʾ
        imshow("frame", frame);
        imshow("Segm", segm);
        imshow("FG Mask MOG 2", fgMaskMOG2);


        int key;
        key = waitKey(5);
        if (key == 'q' || key == 'Q' || key == 27)
            break;


    }

    capture.release();
}
