package nocsimulation.simulations;

@license(LGPL);

import ned.NoCMessage;
import ned.CPU;
import ned.IO;
import ned.Memory;
import ned.Router;
import ned.Arbitrator;

network NoCSimulation
{
    parameters:
        @display("bgb=600,400;bgg=100,1,grey95");

    types:
        channel BiDirectionalChannel {
            delay = default(100ns); // Example fixed delay
            datarate = default(1Gbps);
        }

    submodules:
        cpu: CPU {
            @display("p=100,300");
        }
        io: IO {
            @display("p=500,300");
        }
        systemMemory: Memory {
            @display("p=300,100");
        }
        router: Router {
            @display("p=300,300");
        }
        arbiter: Arbitrator {
            @display("p=300,200");
        }

    connections:
        cpu.port++ <--> BiDirectionalChannel <--> router.port++;
        io.port++ <--> BiDirectionalChannel <--> router.port++;
        router.port++ <--> BiDirectionalChannel <--> arbiter.port++;
        arbiter.port++ <--> BiDirectionalChannel <--> systemMemory.port++;

        // Define other connections as necessary based on system topology and requirements
}

