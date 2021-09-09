// processingHyperspectrometerImg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main()
{
    std::ifstream inputFile{ "test.csv" };
    std::string bufer{};
    for (int j{ 0 };; ++j)
    {
        std::getline(inputFile, bufer);
        //std::istringstream iss{ };
        std::vector<int> a{};
        if (j > 1000)
        {
            for (size_t i{}; i < bufer.size(); ++i)
            {
                if (bufer[i] != ';')
                {
                    std::string qwe{ bufer[i] };
                    std::cout << std::stoi(qwe) << std::endl;
                    a.push_back(std::stoi(qwe));
                }
            }
            std::cout << "D";
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
