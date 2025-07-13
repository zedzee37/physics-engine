#include "physics_object.h"
#include <stdio.h>

void physics_object_add_force_generator(
	PhysicsObject *obj, ForceGenerator generator
) {
	if (obj->force_generator_count >= MAX_FORCE_GENERATORS - 1) {
		perror("The force generator limit has been reached.");
		return;
	}

	obj->force_generators[obj->force_generator_count++] = generator;
}

void physics_object_acceleration(PhysicsObject *obj, double *a_x, double *a_y) {
	double f_x = 0;
	double f_y = 0;

	for (int i = 0; i < obj->force_generator_count; i++) {
		ForceGenerator generator = obj->force_generators[i];

		if (!generator) {
			continue;
		}

		double local_f_x;
		double local_f_y;
		generator(obj->x, obj->y, obj->v_x, obj->v_y, &local_f_x, &local_f_y);
		
		f_x += local_f_x;
		f_y += local_f_y;
	}

	*a_x = f_x / obj->mass;
	*a_y = f_y / obj->mass;
}
