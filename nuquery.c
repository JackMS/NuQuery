/*
	NuQuery: It's new-ish and queries, what else do you need.
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <SE.h>

typedef struct
{
    double x, y, z;		/* position of body */
    float mass;			/* mass of body */
    float vx, vy, vz;		/* velocity of body */
    float u;			/* internal energy */
    float h;			/* smoothing length */
    float rho;			/* density */
    float drho_dt;              /* time derivative of rho */
    float udot;			/* time derivative of u */
    float ax, ay, az;		/* acceleration */
    float lax, lay, laz;	/* acceleration at tpos-dt */
    float phi;			/* potential */
    float idt;			/* timestep */
    unsigned int nbrs;          /* number of neighbors */
    unsigned int ident;		/* unique identifier */
    unsigned int windid;        /* wind id */
    float temp;                 /* temperature */
    float Y_el;                  /* for alignment */
    float f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22; 
    int p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22; 
    int m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16,m17,m18,m19,m20,m21,m22; 
} particle; 


// The Main Loop - The Actual Program

int main(int argc, char *argv[])
{
	int sz,nobj_sph,nobj_se;
	int offset=1600;
	int sefp;
   	int i, j, k;
	FILE *sphfp,*out,*totals;
	particle part;

	if (argc < 3) 
	{
	fprintf(stderr, "Usage: %s SPH File SE Files \n", argv[0]);
	exit(1);
   	}

	// Poke the SPH file for it's size etc then reset the fp, but keep the file open	
	sphfp = fopen(argv[1], "rb");
	fseek(fp, 0L, SEEK_END);
	sz = ftell(sphfp);
	nobj_sph = (sz-offset)/sizeof(particle);
	fseek(sphfp,offset,SEEK_SET);

	//Poke the first SE file for some details then close it again
	sefp = SEopen(argv[2]);
   	SEreadIArrayAttr(sefp, -1, "nn", &nn, &nspecies);
   	SEreadIArrayAttr(sefp, -1, "nz", &nz, &nspecies);
   	SEclose(sefp);
   	printf("%s contains %d species\n", argv[1], nspecies);

   	total_mass = (double *)calloc(nspecies, sizeof(double));

}


