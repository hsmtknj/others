#include <iostream>
#include "Utils.hpp"
#include "opencv2/opencv.hpp"

int main()
{
    std::string str = "Hello World!";
    Utils::print(str);

    cv::Mat image = cv::imread("./lena.jpg");
    Utils::imshow(image);

    return 0;
}
