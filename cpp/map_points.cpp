#include <simd/simd.h>

struct Point { float x, y; };

struct Matrix { float m[9]; };

/** Maps pts Point array of length count in place. Point are mapped by multiplying
    each Point by Matrix. Given:

                 | A B C |        | x |
        Matrix = | D E F |,  pt = | y |
                 | G H I |        | 1 |

    where

        for (i = 0; i < count; ++i) {
            x = pts[i].x
            y = pts[i].y
        }

    each resulting pts SkPoint is computed as:

                      |A B C| |x|                               Ax+By+C   Dx+Ey+F
        Matrix * pt = |D E F| |y| = |Ax+By+C Dx+Ey+F Gx+Hy+I| = ------- , -------
                      |G H I| |1|                               Gx+Hy+I   Gx+Hy+I

    @param matrix transformation Matrix
    @param pts    storage for mapped Points
    @param count  number of Points to transform
*/
void mapPoints(Matrix* matrix, Point pts[], int count) {
    // Convert matrix components into 2x3 transformation matrix form
    simd::float2x2 linear = {
        simd::float2(matrix->m[0], matrix->m[1]), // first row: A, B
        simd::float2(matrix->m[3], matrix->m[4])  // second row: D, E
    };
    simd::float2 translate(matrix->m[2], matrix->m[5]); // C, F

    for (int i = 0; i < count; ++i) {
        // Convert Point to simd::float2
        simd::float2 p(pts[i].x, pts[i].y);
        
        // Apply transformation: linear * p + translate
        simd::float2 result = linear * p + translate;
        
        // Store back to Point
        pts[i].x = result.x;
        pts[i].y = result.y;
    }
}
