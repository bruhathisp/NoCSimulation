#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <omnetpp.h>
#include "NoCMessages.msg"

using namespace omnetpp;

class TestBench : public cSimpleModule {
protected:
    // Initialization function
    virtual void initialize() override;

    // Handler for incoming messages
    virtual void handleMessage(cMessage *msg) override;

    // Method to run test scenarios
    void runTestScenario();

public:
    // Function to check results and validate simulation outcomes
    void validateResults();
};

#endif // TESTBENCH_H_
