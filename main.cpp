#include <fstream>
#include <string>
#include <vector>
#include "src/vec3.h"
#include "src/color.h"
#include "src/ray.h"
#include "src/Shape.h"
#include "src/Sphere.h"
#include "src/Plane.h"


using std::cout, std::endl;
using std::vector;

#define kWidth 1920
#define kHeight int(kWidth / (16.0 / 9.0))
#define kViewHeight 2.0
#define kViewWidth double(kViewHeight * (static_cast<double>(kWidth)/kHeight))

vector<Shape*> objects;

Shape* hitShape(const Ray& r) {
    double close = 1000000.0f;
    Shape* retShape = nullptr;
    for (int i = 0; i < objects.size(); i++) {
        double intersection = objects[i]->intersect(r);

        if (intersection < 0) { continue; }

        if (intersection < close) {
            close = intersection;
            retShape = objects[i];
        }
    }
    return retShape;
}

color rayColor(const Ray& r) {
    Shape* s = hitShape(r);
    color ret;
    if (s) {
        vec3 N = s->getNormal(r.at(s->intersect(r)));
        ret = 0.5 * vec3(N.x() + 1, N.y() + 1, N.z() + 1);
    } else {
        vec3 normDir = normalize(r.direction());
        double a = 0.5f * (normDir.y() + 1.0f);
        ret = (1.0f - a) * color(1.0f, 1.0f, 1.0f) + a * color(0.5f, 0.7f, 1.0f);
    }
    return ret;
}

bool render(const std::string& filename) {
    double focalLength = 2.0f;
    point3 cameraPos = point3(0.0f, 0.0f, 0.0f);
    // delta pixel (u, v)
    vec3 viewportU = vec3(kViewHeight, 0.0f, 0.0f);
    vec3 viewportV = vec3(0.0f, -kViewHeight, 0.0f);
    vec3 pixelDeltaU = viewportU / kWidth;
    vec3 pixelDeltaV = viewportV / kHeight;
    point3 viewportUpLeft = cameraPos - vec3(0.0f, 0.0f, focalLength) - (viewportU / 2) - (viewportV / 2);
    // halfway pixel
    point3 pixel00Loc = viewportUpLeft + 0.5f * (pixelDeltaU + pixelDeltaV);

    try {
        std::ofstream outFile(filename);
        outFile << "P3\n" << kWidth << ' ' << kHeight << "\n255\n";

        for (int j = 0; j < kHeight; j++) {
            for (int i = 0; i < kWidth; i++) {
                point3 pixelCenter = pixel00Loc + (i * pixelDeltaU) + (j * pixelDeltaV);
                vec3 rayDir = pixelCenter - cameraPos;
                Ray r(cameraPos, rayDir);
                color pixelColor = rayColor(r);

                write_color(outFile, pixelColor);
            }
        }
        outFile.close();
    } catch (const std::runtime_error err) {
        cout << err.what() << endl;
    }
    
    return true;
}

int main(int argc, char* argv[]) {
    std::string filename = "default.ppm";

    Sphere s(vec3(1.0, 0.0, 0.0), vec3(0.0, 0.1, 0.0), vec3(0.0, 0.1, 0.0), vec3(0.0, 0.1, 0.0),
            1.0, true, vec3(0.0, 0.5, -3.0), vec3(0.5, 1.0, 1.0));
    Sphere s1(vec3(1.0, 0.0, 0.0), vec3(0.0, 0.1, 0.0), vec3(0.0, 0.1, 0.0), vec3(0.0, 0.1, 0.0),
            1.0, true, vec3(0.0, -99.0, -20.0), vec3(100.0, 1.0, 1.0));

    //Plane p(vec3(0.0, 0.1, 0.0), vec3(0.0, 0.1, 0.0), vec3(0.0, 0.1, 0.0), vec3(0.0, 0.1, 0.0),
    //        1.0, true, vec3(0.0, 1.0, 0.0), vec3(0.0, 0.0, 0.0));

    objects.push_back(&s);
    objects.push_back(&s1);
    //objects.push_back(p);

    if (argc > 1) {
        filename = argv[1];
    }

    render(filename);

    return 0;
}