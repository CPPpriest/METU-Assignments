#ifndef __SCENE__
#define __SCENE__


#include "utilities.h"




enum class ObjectType
{
    SPHERE,
    TRIANGLE
};





struct OBJECT
{
    // Object ID
    int ID;

    // Object Type
    ObjectType type;

    // Material
    Pixel ambient;
    Pixel diffuse;
    Pixel specular;
    Pixel mirror;
    double phong;



    // Sphere properties
    Point center_vertex;
    double radius;

    // Triangle properties
    Vector Normal;
    Point v0;
    Point v1;
    Point v2;


    // Bounding Box
    Point p_max;
    Point p_min;

};





struct SCENE
{
    parser::Scene scene;


    Pixel background_color;
    Pixel ambient_light;

    double shadow_ray_epsilon;
    int max_recursion_depth;
    
	std::vector<Point> scene_vertices;
	std::vector<OBJECT> scene_objects;

    // Convert to convenient formats
    SCENE(parser::Scene SCN);
};












#endif