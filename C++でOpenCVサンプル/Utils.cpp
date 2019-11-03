#include <iostream>
#include "Utils.hpp"
#include "opencv2/opencv.hpp"

Utils::Utils()
{

}

Utils::~Utils()
{

}

void Utils::print(const std::string message)
{
    std::cout << message << std::endl;
}

void Utils::imshow(cv::Mat &showedImg, int waitTime)
{
    cv::namedWindow("", CV_WINDOW_AUTOSIZE );
    cv::imshow("", showedImg);
    cv::waitKey(waitTime);
}
