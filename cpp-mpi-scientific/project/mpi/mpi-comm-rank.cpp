#include <iostream>
#include <mpi.h>

int main(int argc, char ** argv) {

	int mynode, totalnode;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &totalnode); //This prints TOTAL number of processor (process)
	MPI_Comm_rank(MPI_COMM_WORLD, &mynode); //This prints the current number of processor (process)

	std::cout << "Hello world from process " << mynode;
	std::cout << " of " << totalnode << std::endl;

	MPI_Finalize();
}
