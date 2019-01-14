#pragma once

#include <utility>
#include <math.h>

typedef std::pair<float, float> vertex_t;
typedef std::pair<int, int> int_vertex_t;

vertex_t rotate(vertex_t v, float a) {
    float sin_a = sinf(a);
    float cos_a = cosf(a);

    // matrix multiplication ftw
    return {
        v.first * cos_a - v.second * sin_a,
        v.first * sin_a + v.second * cos_a
    };

}

vertex_t translate(vertex_t v, float x, float y) {
    return {v.first + x, v.second + y};
}

vertex_t scale(vertex_t v, float a) {
    return {v.first * a, v.second * a};
}


