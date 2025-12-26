#include <iostream>
#include <simd/geometry.h>
#include <simd/simd.h>

int main() {
    simd::float2 a = {1, 1};
    simd::float2 b = {4, 4};
    simd::float2 c = {2, 1};

    float result = simd::cross(b - a, c - a)[2];
    std::cout << result << '\n';
}
