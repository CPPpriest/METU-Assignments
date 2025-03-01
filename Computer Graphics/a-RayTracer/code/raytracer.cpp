#include "scene.h"
#include <chrono>
#include <thread>


// Scene GLOBALS
//parser::Scene scene;                            // Scene
SCENE* main_scene;
std::vector<parser::PointLight> point_lights;   // point lights




// Camera GLOBALS
unsigned char* image;   // image plane
int nx, ny;             // Resolution



// Function Declerations
Pixel computeColor(Ray ray);
Pixel addShading(Ray ray, hitRecord object);




// FUNCTIONS

hitRecord hit(Ray ray)
{

    // Initiate Object
    hitRecord hitObj;
    hitObj.isHit = false;


    // Set t parameter to max value
    double t_min = DBL_MAX;

    for(OBJECT& obj : main_scene->scene_objects)
    {

        if(obj.type == ObjectType::SPHERE)
        {
            
            Point c = obj.center_vertex;
        
            float R = obj.radius;

            Vector d = ray.direction;

            Point o = ray.origin;

            // Calculate Discriminant
        

            Vector o_c(o ,c);
            double a = dotProduct( d, d ) ;
            double b = 2 * dotProduct(d, o_c) ;
            double cval = dotProduct(o_c, o_c) - R*R;

            double discriminant = b*b - 4*a*cval;



            if( discriminant >= 0 )
            {
                // Calculate t
            
                        // !! might be problematic
                        // scenario 1: camera inside the sphere 
                        // scenario 2: tangent ( discriminant == 0)

                double t_1 = (-b + sqrt(discriminant) ) / (2*a);
                double t_2 = (-b - sqrt(discriminant) ) / (2*a);


                double t = t_1;
                if( (0 < t_2) && ( t_2 < t_1) )   
                    t = t_2;


                if( (t > 0) && (t < t_min) )
                {
                    t_min = t;

                    // SET OBJECT FOR TRIANGLE
                    hitObj.ObjID = obj.ID;
                    hitObj.isHit = true;

                    hitObj.ambient = obj.ambient;
                    hitObj.diffuse = obj.diffuse;
                    hitObj.specular = obj.specular;
                    hitObj.mirror = obj.mirror;
                    hitObj.phong = obj.phong;
                }
            }
        }

        if(obj.type == ObjectType::TRIANGLE)
        {
            Point a = obj.v0; 
            Point b = obj.v1; 
            Point c = obj.v2;


            Point o = ray.origin;


            Vector d = ray.direction * (-1);
            d.normalize();


            Vector ab(b,a);             //  b - a
            Vector ac(c,a);             //  c - a
            Vector ao(o,a);             //  o - a


            Matrix A(ab, ac, d);
            Matrix A_beta(ao, ac, d);
            Matrix A_gamma(ab, ao, d);
            Matrix A_t(ab, ac, ao);


            double det_A =  A.det();                    if(det_A == 0)  continue;

            double beta  =  A_beta.det() / det_A;       if(beta < 0)    continue;

            double gamma =  A_gamma.det() / det_A;      if(gamma < 0)   continue;

            double t =  A_t.det() / det_A;              if (t <= 0)     continue;
        

            if( ((gamma + beta) <= 1.0f) && (t < t_min) )
            {
        
                t_min = t;

                hitObj.ObjID = obj.ID;
                hitObj.isHit = true;

                hitObj.ambient = obj.ambient;
                hitObj.diffuse = obj.diffuse;
                hitObj.specular = obj.specular;
                hitObj.mirror = obj.mirror;
                hitObj.phong = obj.phong;
            }
            
        }    
    }

    


    
    if(hitObj.isHit)
    {
        // Calculate hitPoint
        Vector vt = ray.direction;
        vt.normalize();
        vt = vt * t_min;

        hitObj.hitPoint = ray.origin + vt;


        // Calculate hitNormal
        OBJECT obj = main_scene->scene_objects[hitObj.ObjID];

        if(obj.type == ObjectType::SPHERE)
        {
            Vector normal = Vector( hitObj.hitPoint, obj.center_vertex );
            normal.normalize();
            hitObj.hitNormal = normal;
        }
        else // (hitObj.type == ObjectType::TRIANGLE) OR (hitObj.type == ObjectType::MESH)
        {
            hitObj.hitNormal = obj.Normal;
        }

        hitObj.hitNormal.normalize();
        // Calculate scaled hitPoint

        hitObj.hitPoint = hitObj.hitPoint + Point(hitObj.hitNormal * main_scene->shadow_ray_epsilon);

    }

    return hitObj;
}



Ray reflect(Vector incomingDir, Vector surfaceNormal)
{       
    Vector temp = incomingDir + surfaceNormal  * ( (-2) * dotProduct(incomingDir, surfaceNormal) ) ;
    return Ray( {0,0,0}, (temp) );
}



// Specular Shading + Mirror
Pixel addShading(Ray ray, hitRecord object)
{
    // AMBIENT LIGHT

    Pixel pixel = object.ambient.r * main_scene->ambient_light.r;
    pixel = object.ambient.g * main_scene->ambient_light.g;
    pixel = object.ambient.b * main_scene->ambient_light.b;

    // DIFFUSE , SPECULAR , MIRROR
    for(parser::PointLight pl : point_lights)
    {
        // MIRROR
        if(object.mirror.r || object.mirror.g || object.mirror.b)
        {
            Ray reflectionRay = reflect(ray.direction , object.hitNormal);
            reflectionRay.origin = object.hitPoint;
            reflectionRay.depth = ray.depth + 1;
            
            // Compute Color for reflectionRay
            Pixel refColor = computeColor(reflectionRay);

            // Add color from reflection to pixel value
            pixel.r += object.mirror.r * refColor.r;
            pixel.g += object.mirror.g * refColor.g;
            pixel.b += object.mirror.b * refColor.b;

        }

        // Define unit vector from hitPoint to point light
        Point lsPosition = {pl.position.x , pl.position.y, pl.position.z};
        Vector vc( lsPosition , object.hitPoint);
        vc.normalize();

        // Define shadowRay
        Ray shadowRay = { object.hitPoint , vc};

        hitRecord blockingObject = hit(shadowRay);
        if( ! blockingObject.isHit )
        {

            Vector rayVector(lsPosition , object.hitPoint); // to the light source
            double magnitude = rayVector.magnitude();
            double magnitudeSquared = magnitude*magnitude;
            rayVector.normalize();
            double cosTheta = dotProduct(object.hitNormal, rayVector );

            double incomingRadience_x = (pl.intensity.x / magnitudeSquared) * cosTheta;
            double incomingRadience_y = (pl.intensity.y / magnitudeSquared) * cosTheta;
            double incomingRadience_z = (pl.intensity.z / magnitudeSquared) * cosTheta;

            // DIFFUSE SHADING   
            pixel.r += object.diffuse.r * incomingRadience_x ;
            pixel.g += object.diffuse.g * incomingRadience_y ;
            pixel.b += object.diffuse.b * incomingRadience_z ;
            

            // SPECULAR SHADING
            Vector h((ray.direction * (-1)) + rayVector);   h.normalize();
            double cosAlpha = dotProduct(h, object.hitNormal);


            double cosAlphaPow = pow(cosAlpha, object.phong);


            pixel.r += object.specular.r * cosAlphaPow * incomingRadience_x;
            pixel.g += object.specular.g * cosAlphaPow * incomingRadience_y;
            pixel.b += object.specular.b * cosAlphaPow * incomingRadience_z;
            
        }
    }
    return pixel;
}







Pixel computeColor(Ray ray)
{
    Pixel pixel(0,0,0);
    
    if(ray.depth > main_scene->max_recursion_depth)
        return pixel;                               // {0, 0, 0}

    // hit closest object
    hitRecord object = hit(ray);

    if( ! object.isHit )
    {
        if(ray.depth == 0)
        {
            pixel = main_scene->background_color ;
            return pixel;                           // BACKGROUND
        }    
        
        return pixel;                               // {0, 0, 0}
    }
    
    return addShading(ray, object);                 // Pixel Value
}



void renderFrame(int start, int end, int k, Point q, double pw , double ph, Point camPosition){

    for (int j = start; j < end; ++j)    // row  j
    {
        for (int i = 0; i < nx; ++i)    // column   i
        {
            // 1) Find pixel location
            Point s( (q.x + (i + 0.5) * pw ), (q.y - (j + 0.5) * ph) , (q.z) );

            // 2) Find ray direction (Unit Vector)
            Vector ray_direction(s, camPosition);

            // 3) Create eye_ray with depth=0 (by default)
            Ray eye_ray(camPosition, ray_direction);

            // Compute Color
            Pixel pixel = computeColor(eye_ray);

            // Clamp and write pixel values to image plane
            image[k++] = clamp(pixel.r);  // red
            image[k++] = clamp(pixel.g);  // green
            image[k++] = clamp(pixel.b);  // blue
        }

    }

}






void create_image(parser::Camera camera)
{

    // a) Camera Position
    Point camPosition = camera.position;

    
    // b) Camera Unit Vectors
    Vector camGaze(camera.gaze);
    Vector gaze = camera.gaze;
    Vector v = camera.up; 
    Vector u = crossProduct(gaze, v);


    // c) Center of Image Plane
    Point m = camPosition + camGaze * camera.near_distance;


    // d) Image Plane borders
    double l = camera.near_plane.x; //left
    double r = camera.near_plane.y; //right
    double b = camera.near_plane.z; //bottom
    double t = camera.near_plane.w; //top


    // e) Upper Left Edge Point of Image Plane
    Point q = m + u*l + v*t ;


    // g) Pixel width & height
    double pw = (r - l) / nx ;
    double ph = (t - b) / ny;


    int chunkSize = 200; // Number of rows each thread will process
    std::vector<std::thread> threads;
    int startY = 0;
    int k = 0;

    while (startY < ny) {
        int endY = std::min(startY + chunkSize, ny); // Calculate the end of the chunk
        threads.emplace_back(renderFrame, startY, endY, k, q, pw, ph, camPosition);
        k += (endY - startY) * nx * 3; // Update k for the next chunk
        startY = endY; // Move to the next chunk
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

}



// !!! Modify for ALL CAMERAS
int main(int argc, char* argv[])
{

    // Parse input scene
    parser::Scene scene;
    scene.loadFromXml(argv[1]);
    main_scene = new SCENE(scene);


    point_lights = main_scene->scene.point_lights;


    // START TIME
    auto start = std::chrono::high_resolution_clock::now();


    // Render scene to image for each camera
    for(parser::Camera CAM : scene.cameras){
        
        // Resolution
        nx = CAM.image_width;
        ny = CAM.image_height;
        
        image = new unsigned char [nx * ny * 3];

        create_image(CAM);

        const char* image_name = CAM.image_name.c_str();
        write_ppm(image_name, image, nx, ny);

        delete(image);
    }
    

    // END TIME
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    // std::cout << "Execution time: " << elapsed_time << " msec " << std::endl;

    
    return 0;
}