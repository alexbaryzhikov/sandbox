#include <cfloat>
#include <cmath>
#include <cstdio>
#include <numbers>

void printDouble(double x) {
    printf("%.*g\n", DBL_DECIMAL_DIG, x);
}

void printFloat(float x) {
    printf("%.*g\n", FLT_DECIMAL_DIG, x);
}

float projectionDistanceCoef(float fov) {
    return 0.5f / std::tan(fov / 2.0f);
}

int main() {
    float fov = std::numbers::pi / 3.0;
    float coef = projectionDistanceCoef(fov);

    printFloat(fov);
    printFloat(coef);
}
