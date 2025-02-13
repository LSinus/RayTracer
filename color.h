//
// Created by Leonardo Sinibaldi on 10/02/25.
//

#ifndef COLOR_H
#define COLOR_H

#include "interval.h"
#include "vec3.h"

using color = vec3;

inline double linear_to_gamma(double linear_component)
{
    if (linear_component > 0)
        return std::sqrt(linear_component);

    return 0;
}

inline uint32_t write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    // Translate the [0,1] component values to the byte range [0,255].
    static const interval intensity(0.000, 0.999);
    uint8_t rbyte = uint8_t(255.999 * intensity.clamp(r));
    uint8_t gbyte = uint8_t(255.999 * intensity.clamp(g));
    uint8_t bbyte = uint8_t(255.999 * intensity.clamp(b));
    uint8_t abyte = 255;  // Fully opaque

    // Write out the pixel color components.
    //out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
    uint32_t color = (abyte << 24) | (bbyte << 16) | (gbyte << 8) | rbyte;
    return color;
}

#endif //COLOR_H
