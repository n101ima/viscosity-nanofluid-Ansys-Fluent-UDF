#include "udf.h"

DEFINE_PROPERTY(cell_viscosity, c, t)
{
	real mu_base;
	real mu_nanofluid;
	real phi = 0.01; // volume fraction of nanoparticle
	real temp = C_T(c, t); // temperature of the fluid zone

	// calculate the viscosity of base fluid
	if (temp < 285.15)
		mu_base = 5.398500844;
	else if (temp >= 285.15 && temp <= 373.15)
		mu_base = 3.661e2 - 3.0154 * temp + 8.3409e-3 * temp * temp - 7.723e-6 * temp * temp * temp;
	else if (temp >= 317.15 && temp <= 698.15)
		mu_base = 23.165 - 0.1476 * temp + 3.617e-4 * temp * temp - 3.9844e-7 * temp * temp * temp + 1.6543e-10 * temp * temp * temp * temp;
	else if (temp > 698.15)
		mu_base = 0.132781558;

	// convert the viscosity from mPa s to kg m^-1 s^-1
	mu_base = mu_base * 1e-3;

	// calculate the viscosity of nanofluid
	mu_nanofluid = mu_base * (123 * phi * phi + 7.3 * phi + 1);

	return mu_nanofluid;
}