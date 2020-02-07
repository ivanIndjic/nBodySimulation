#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ui.h"
#include "nbody.h"
#include "nbody_tools.h"
#include "nbody_alloc.h"

void all_init_particles(int num_particles, particle_t *particles)
{
  int    i;
  double total_particle = num_particles;

  for (i = 0; i < num_particles; i++) {
    particle_t *particle = &particles[i];
#if 0
    particle->x_pos = ((rand() % max_resolution)- (max_resolution/2))*2.0 / max_resolution;
    particle->y_pos = ((rand() % max_resolution)- (max_resolution/2))*2.0 / max_resolution;
    particle->x_vel = particle->y_pos;
    particle->y_vel = particle->x_pos;
#else
    particle->x_pos = i*2.0/nparticles - 1.0;
    particle->y_pos = 0.0;
    particle->x_vel = 0.0;
    particle->y_vel = particle->x_pos;
#endif
    particle->mass = 1.0 + (num_particles+i)/total_particle;
  }
}

