#include "color.h"

void write_color(std::ostream& out, const color& pixel_color) {
    int r = static_cast<int>(255.999 * pixel_color.r());
    int g = static_cast<int>(255.999 * pixel_color.g());
    int b = static_cast<int>(255.999 * pixel_color.b());

    out << r << " " << g << " " << b << "\n";
}