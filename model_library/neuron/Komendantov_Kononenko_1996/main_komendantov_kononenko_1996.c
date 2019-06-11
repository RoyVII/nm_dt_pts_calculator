#include "nm_komendantov_kononenko_1996.h"

void init_vars_params (double ** vars, double ** params) {
	(*vars) = (double*) malloc (sizeof(double) * NM_KOMENDANTOV_KONONENKO_1996_N_VARS);
	(*params) = (double*) malloc (sizeof(double) * NM_KOMENDANTOV_KONONENKO_1996_N_PARAMS);

	// Variables
	(*vars)[NM_KOMENDANTOV_KONONENKO_1996_V] = -55; // Not set yet
	(*vars)[NM_KOMENDANTOV_KONONENKO_1996_M_B] = 0; // Not set yet
	(*vars)[NM_KOMENDANTOV_KONONENKO_1996_H_B] = 0; // Not set yet
	(*vars)[NM_KOMENDANTOV_KONONENKO_1996_M] = 0; // Not set yet
	(*vars)[NM_KOMENDANTOV_KONONENKO_1996_H] = 0; // Not set yet
	(*vars)[NM_KOMENDANTOV_KONONENKO_1996_N] = 0; // Not set yet
	(*vars)[NM_KOMENDANTOV_KONONENKO_1996_M_CA] = 0; // Not set yet
	(*vars)[NM_KOMENDANTOV_KONONENKO_1996_CA] = 0; // Not set yet

	// Parameters
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_DT] = 3; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_I] = 0; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_SYN] = 0; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_CM] = 0.02; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_G_NA_V] = 0.11; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_V_NA] = 40.0; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_G_K] = 0.25; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_V_K] = -70.0; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_G_NA] = 0.0231; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_G_B] = 0.165; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_V_B] = -58.0; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_G_NA_TTX] = 400.0; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_G_K_TEA] = 10.0; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_G_CA] = 1.5; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_V_CA] = 150.0; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_G_CA_CA] = 0.02; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_K_BETA] = 15000.0; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_BETA] = 0.00004; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_RHO] = 0.002; // Not set yet
	(*params)[NM_KOMENDANTOV_KONONENKO_1996_K_S] = 50.0; // Not set yet
}

int main (int argc, char * argv[]) {
	double * vars, * params;
	int freq = 10000;
	neuron_model nm;
	unsigned long loop_points = 0, i = 0;
	FILE * f;

	init_vars_params(&vars, &params);
	params[NM_KOMENDANTOV_KONONENKO_1996_DT] = atoi(argv[2]);
	nm_komendantov_kononenko_1996_init(&(nm), vars, params);
	free_pointers(2, &vars, &params);

	nm.params[NM_KOMENDANTOV_KONONENKO_1996_DT] = atof(argv[3]);

	f = fopen(argv[1], "w");
	loop_points = 100 * freq;

	for (i = 0; i < loop_points; i++) {
		fprintf(f, "%f\n", nm.vars[NM_KOMENDANTOV_KONONENKO_1996_V]);
		nm.func(nm, 0);
	}

	fclose(f);
	free_pointers(2, &(nm.vars), &(nm.params));
	return 1;
}