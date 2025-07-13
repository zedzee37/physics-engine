#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

#include <stddef.h>

#define MAX_FORCE_GENERATORS 16

typedef void (*ForceGenerator)(double x, double y, double v_x, double v_y, double *f_x, double *f_y);

typedef struct {
	double mass;
	double x, y;
	double v_x, v_y;
	size_t force_generator_count;
	ForceGenerator force_generators[MAX_FORCE_GENERATORS];
} PhysicsObject;

extern void physics_object_add_force_generator(
		PhysicsObject *obj, ForceGenerator generator
);
extern void physics_object_acceleration(
		PhysicsObject *obj, double *a_x, double *a_y
);

#endif
