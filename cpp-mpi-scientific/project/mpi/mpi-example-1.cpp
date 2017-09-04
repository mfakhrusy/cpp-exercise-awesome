#include <iostream>
#include <mpi.h>

int main(int argc, char ** argv) {

	int mynode, totalnodes;
	int sum, startval, endval, accum;
	MPI_Status status;

	MPI_Init(argc, argv);
	MPI_Comm_size(MPI_COMM_WORLD, &totalnodes);
	MPI_Comm_rank(MPI_COMM_WORLD, &mynode);

	sum = 0;
	startval = 1000*mynode/totalnodes + 1;
	endval = 1000*(mynode + 1)/totalnodes;

	for (int i = startval; i <= endval; i++) {
		sum = sum + i;
	}

	if (mynode != 0) {
		//HAVE NOT FINISHED LOL GOING HOME BB
	}
	std::cout << "The sum from 1 to 1000 is: " << sum << std::endl;
}
