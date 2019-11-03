#ifndef INCLUDED_UTILS_H
#define INCLUDED_UTILS_H

#include <iostream>
#include "opencv2/opencv.hpp"

class Utils
{
    public:
        // constructor and destructor
        Utils();
        ~Utils();

        // static functions
        static void print(const std::string message  = "default setting");
        static void imshow(cv::Mat &showeImg, int waitTime=0);
};

#endif
