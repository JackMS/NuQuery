/*
 _   _        ___
| \ | |_   _ / _ \ _   _  ___ _ __ _   _
|  \| | | | | | | | | | |/ _ \ '__| | | |
| |\  | |_| | |_| | |_| |  __/ |  | |_| |
|_| \_|\__,_|\__\_\\__,_|\___|_|   \__, |
                                   |___/

It's new-ish and queries, what else do you need.

A slowly evolving lineage of programs to query the output of Burnf processed 
outputs of SNSPH simulations. This is the (hopefully final) rewrite of
Burn Query, now including the correct libraries! NO MORE KLUDGE! At least 
no more kludgy than avergae now anyway. The Suck Less school of thought
has convinced me tht building the query in same tool you run it with is dumb,
So this is now a headless tool as part of the Burn Query package. The sort
params etc you might want will now be read from a config file, which can
be either hand edited or modifed with Query Tool (coming soon-ish!) extenrally. 

To-Do:
Load Query:		Idea
Interface with SDF:	Started
Interface with HDF5:	Solved, no code
Unified Output:		Idea
Raw Abundance Output:	Solved, no code
Pretty Plots:		Ext. solution, script interface?

*/


// Declarations 
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <SE.h>
#include <SDF.h>

// copypasta
int i, j, k, nvecs, nrecs;
char **vecs;
double x, y, z;
float masscf,lengthcf,timecf;
// new declarations
double vx, vy, vz;
double ax, ay, az;
double stride;
// The Main Loop 

int main(int argc, char *argv[])
{
	SDF *sdfp = NULL;
	
	sdfp = SDFopen(NULL, argv[1]);
	if (*sdfp == NULL){
        	fprintf(stderr, "%s: %s: %s\n", argv[0], argv[1], SDFerrstring);
        	exit(2);
		}

	nvecs = SDFnvecs(sdfp);
	vecs = SDFvecnames(sdfp);
	nrecs = SDFnrecs("npart",sdfp);

	SDFgetint(sdfp, "npart", &nrecs);
	SDFgetfloatOrDefault(sdfp, "massCF", &masscf, 1.9889e27);
	SDFgetfloatOrDefault(sdfp, "timeCF", &timecf, 1.e2);
	SDFgetfloatOrDefault(sdfp, "lengthCF", &lengthcf, 6.955e10);
	printf("length= %e, mass= %e, time= %e\n",lengthcf, masscf, timecf);
	printf("nrecs= %d \n",nrecs);

	for (i = 0; i < nvecs; i++){
		printf("%s,",vecs[i]);
	}
	
	stride = SDFfilestride("x", sdfp);

return 0;
}


