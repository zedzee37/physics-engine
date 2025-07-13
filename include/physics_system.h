#ifndef PHYSICS_SYSTEM_H
#define PHYSICS_SYSTEM_H

#include <stddef.h>
#include <physics_object.h>

#define DEFAULT_OBJ_SIZE 10

typedef struct {
	size_t obj_count;
	size_t obj_size;
	PhysicsObject *physics_objects;
} PhysicsSystem;

extern PhysicsSystem *physics_system_new();
extern void physics_system_free(PhysicsSystem *sys);

#endif
