#include "Simulation.h"

int main(int argc, char** argv) {
    if(argc != 6) return 1;
    Simulation simulation(argc, argv);
    simulation.run();
}
