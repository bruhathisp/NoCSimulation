package simulation;

// Import statements for the modules might be required depending on your project structure
// import ned.CPU;
// import ned.Router;

// Defines a simple module for TestBench, which may control tests and validate outcomes
simple TestBench {
    parameters:
        @display("i=block/control"); // Icon and display settings for the TestBench in the GUI
}

// Main network configuration that includes the TestBench and other network components
network NoCSimulation
{
    submodules:
        testbench: TestBench {
            @display("p=50,50"); // Position of the TestBench module in the graphical editor
        }
        cpu: CPU {
            @display("p=100,150"); // Position of the CPU module
        }
        // Example addition: Router module, assuming a Router type is defined elsewhere
        router: Router {
            @display("p=150,150"); // Position of the Router module
        }

    connections:
        // Example connections between CPU, Router, and potentially to the TestBench
        // Connect the CPU output to the Router input
        cpu.out --> router.in;
        // Connect the Router output back to the CPU input
        router.out --> cpu.in;
        
        // Optionally, if the TestBench needs to interact or monitor these components, connections might look like:
        // cpu.out --> testbench.in;
        // router.out --> testbench.in;

        // If TestBench needs to send commands or configurations:
        // testbench.out --> cpu.in;
        // testbench.out --> router.in;
}

