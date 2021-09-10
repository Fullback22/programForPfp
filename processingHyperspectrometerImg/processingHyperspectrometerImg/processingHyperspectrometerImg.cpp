// processingHyperspectrometerImg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main()
{
    int const imageSize{ 2044 };
    std::ifstream inputFile{ "test.csv" };
    std::string buferForLine{};
    cv::Mat outputSpektrum{ cv::Size{imageSize,imageSize }, CV_32FC1, cv::Scalar(1.0) };
    int const maxTwelveBitNumber{ 4095 };
    for (int l{ -1 }; !inputFile.eof() ; ++l)
    {
        std::getline(inputFile, buferForLine);
        if (l > -1)
        {
            std::string buferForNumber{};
            int columNumber{-1};
            for (int i{0}; i < buferForLine.size(); ++i)
            {
                if (buferForLine[i] == ';' || buferForLine[i] == '\n')
                {
                    if (columNumber > 0)
                    {
                        outputSpektrum.at<float>(l, columNumber) = std::stof(buferForNumber) / maxTwelveBitNumber;
                    }
                    ++columNumber;
                    buferForNumber.clear();
                }
                else
                {
                    buferForNumber.push_back(buferForLine[i]);
                }
            }
            if (buferForNumber.size() > 0)
            {
                outputSpektrum.at<float>(l, columNumber) = std::stof(buferForNumber) / maxTwelveBitNumber;
                buferForNumber.clear();
            }
        }
    }
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
