/*
 * $File: camera.hh
 * $Date: Thu Jun 27 03:36:37 2013 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#pragma once

#include "vector.hh"
#include "ray.hh"
#include "random.hh"
#include <cstdio>
class Camera
{
	public:
		Vector eye,
			   front,
			   up;

		real_t screen_dist ;
        real_t focal_dist ;                     // focal_dist is the distance between the eye and the focal plane
        real_t lens_radius ;                    // lens_radius is the radius of the lens on the camera
		real_t screen_width , screen_height ;

		int resol_x, resol_y;

		Camera() {}

		Camera(const Vector &eye, const Vector &front, const Vector &up,
				real_t screen_dist, real_t screen_width, real_t screen_height,
				real_t focal_dist , real_t lens_radius ,
				int resol_x, int resol_y) :
			eye(eye), front(front), up(up),
			screen_dist(screen_dist), screen_width(screen_width), screen_height(screen_height),
			focal_dist( focal_dist ), lens_radius( lens_radius ) ,
			resol_x(resol_x), resol_y(resol_y) {
				normalize();
			}

		Ray emit_ray(int x, int y);
		void normalize();

	protected:

		Random random;
};

/**
 * vim: syntax=cpp11 foldmethod=marker
 */


