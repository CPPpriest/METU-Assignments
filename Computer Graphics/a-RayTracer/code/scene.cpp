#include "scene.h"
#include <algorithm>




SCENE::SCENE(parser::Scene scn){

	this->scene = scn;

	this->shadow_ray_epsilon = scn.shadow_ray_epsilon;
	this->max_recursion_depth = scn.max_recursion_depth;

	this->background_color = scn.background_color;
	this->ambient_light = scn.ambient_light;


	// FOR ALL VERTICES
	for(const parser::Vec3f& vec : scn.vertex_data)
	{
		scene_vertices.push_back( Point(vec.x,vec.y,vec.z) );
	}


	int k = 0;


	// FOR ALL SPHERES
	for (const parser::Sphere& sp : scn.spheres)
	{
		OBJECT obj;
		obj.ID = k++;
		obj.type = ObjectType::SPHERE;

		obj.ambient = scn.materials[sp.material_id-1].ambient;
		obj.diffuse = scn.materials[sp.material_id-1].diffuse;
		obj.specular = scn.materials[sp.material_id-1].specular;
		obj.mirror = scn.materials[sp.material_id-1].mirror;
		obj.phong = scn.materials[sp.material_id-1].phong_exponent;

		obj.center_vertex = this->scene_vertices[sp.center_vertex_id-1];
		obj.radius = sp.radius;

		scene_objects.push_back(obj);

		obj.p_min.x = obj.center_vertex.x - obj.radius ;
		obj.p_min.y = obj.center_vertex.y - obj.radius ;
		obj.p_min.z = obj.center_vertex.z - obj.radius ;

		obj.p_max.x = obj.center_vertex.x + obj.radius ;
		obj.p_max.y = obj.center_vertex.y + obj.radius ;
		obj.p_max.z = obj.center_vertex.z + obj.radius ;
	}


	// FOR ALL TRIANGLES
	for (const parser::Triangle& tr : scn.triangles)
	{
		OBJECT obj;
		obj.ID = k++;
		obj.type = ObjectType::TRIANGLE;

		obj.ambient = scn.materials[tr.material_id-1].ambient;
		obj.diffuse = scn.materials[tr.material_id-1].diffuse;
		obj.specular = scn.materials[tr.material_id-1].specular;
		obj.mirror = scn.materials[tr.material_id-1].mirror;
		obj.phong = scn.materials[tr.material_id-1].phong_exponent;

		obj.v0 = this->scene_vertices[tr.indices.v0_id-1];
		obj.v1 = this->scene_vertices[tr.indices.v1_id-1];
		obj.v2 = this->scene_vertices[tr.indices.v2_id-1];

		//calculate normal HERE
		Point a = obj.v0;
        Point b = obj.v1;  
       	Point c = obj.v2;
        Vector ba(a, b); // a - b 
        Vector bc(c, b); // c - b

        Vector tmp = crossProduct(bc, ba);
        tmp.normalize();
        obj.Normal = tmp;


        obj.p_min.x = std::min(a.x, std::min(b.x, c.x) );
		obj.p_min.y = std::min(a.y, std::min(b.y, c.y) );
		obj.p_min.z = std::min(a.z, std::min(b.z, c.z) ); 

		obj.p_max.x = std::min(a.x, std::max(b.x, c.x) );
		obj.p_max.y = std::min(a.y, std::max(b.y, c.y) );
		obj.p_max.z = std::min(a.z, std::max(b.z, c.z) ); 


		scene_objects.push_back(obj);
	}


	// FOR ALL MESHES
	for (const parser::Mesh& ms : scn.meshes)
	{
		for (const parser::Face& fc : ms.faces)
    	{
			OBJECT obj;
			obj.ID = k++;
			obj.type = ObjectType::TRIANGLE;

			obj.ambient = scn.materials[ms.material_id-1].ambient;
			obj.diffuse = scn.materials[ms.material_id-1].diffuse;
			obj.specular = scn.materials[ms.material_id-1].specular;
			obj.mirror = scn.materials[ms.material_id-1].mirror;
			obj.phong = scn.materials[ms.material_id-1].phong_exponent;

			obj.v0 = this->scene_vertices[fc.v0_id-1];
			obj.v1 = this->scene_vertices[fc.v1_id-1];
			obj.v2 = this->scene_vertices[fc.v2_id-1];

			Point a = obj.v0;
        	Point b = obj.v1;  
       		Point c = obj.v2;
        	Vector ba(a, b); // a - b 
        	Vector bc(c, b); // c - b

        	Vector tmp = crossProduct(bc, ba);
        	tmp.normalize();
        	obj.Normal = tmp;


			obj.p_min.x = std::min(obj.v0.x, std::min(obj.v1.x, obj.v2.x) );
			obj.p_min.y = std::min(obj.v0.y, std::min(obj.v1.y, obj.v2.y) );
			obj.p_min.z = std::min(obj.v0.z, std::min(obj.v1.z, obj.v2.z) ); 

			obj.p_max.x = std::min(obj.v0.x, std::max(obj.v1.x, obj.v2.x) );
			obj.p_max.y = std::min(obj.v0.y, std::max(obj.v1.y, obj.v2.y) );
			obj.p_max.z = std::min(obj.v0.z, std::max(obj.v1.z, obj.v2.z) ); 


			//calculate normal HERE
			scene_objects.push_back(obj);
    	}
	}
}