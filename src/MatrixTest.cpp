#include<iostream>
#include<memory>
#include <chrono>
#include <thread>
#include "libkmMatrix.h"




int main() {


// test for memory leak
    for (int i = 0; i < 10; i++) {
       kmm::Matrix<int> A({{0, 0},
                       {1, 1}});
       kmm::Matrix<int> B({{1, 1},
                       {0, 0}});

        auto S = A + B;
    }
    std::cout << "ping" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));


}
