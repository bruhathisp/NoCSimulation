#include "CPU.h"
#include "NoCMessages.msg"

Define_Module(CPU);

void CPU::initialize() {
    cMessage *event = new cMessage("generateTraffic");
    double interval = par("generationInterval").doubleValue();
    scheduleAt(simTime() + exponential(interval), event);
    maxBufferSize = par("initialBufferSize").intValue(); // Default buffer size from parameters
}

void CPU::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        generateTraffic();
    } else {
        processIncomingMessage(check_and_cast<NoCMessage *>(msg));
    }
}

void CPU::generateTraffic() {
    NoCMessage *nocMsg = new NoCMessage("nocTraffic");
    nocMsg->setSrcX(getIndex());
    nocMsg->setSrcY(0);
    nocMsg->setDestX(intuniform(0, par("networkSize").intValue()-1));
    nocMsg->setDestY(0);
    nocMsg->setType(intuniform(0, 1)); // 0 for read, 1 for write
    nocMsg->setPriority(intuniform(1, 10));
    nocMsg->setByteLength(32);

    double latency = calculateLatency(nocMsg->getType(), nocMsg->getDestX());
    nocMsg->setLatency(latency);

    EV << simTime() << " - Generating " << (nocMsg->getType() == 0 ? "Read" : "Write")
       << " Traffic to " << nocMsg->getDestX() << " with latency " << latency << " cycles: "
       << nocMsg->getName() << endl;

    send(nocMsg, "out");
}

double CPU::calculateLatency(int type, int dest) {
    // Placeholder formula: Modify according to actual latency calculation logic
    return type == 0 ? 10 : 5; // Example: Reads take 10 cycles, writes take 5 cycles
}

void CPU::processIncomingMessage(NoCMessage *msg) {
    EV << simTime() << " - Processing received data at CPU" << endl;
    delete msg;
}

// API Implementation
void CPU::set_max_buffer_size(int size) {
    maxBufferSize = size;
    EV << "Max buffer size set to " << maxBufferSize << endl;
}

void CPU::set_arbiter_weights(double weight) {
    arbiterWeight = weight; // Assuming there's an arbiter mechanism in the CPU
    EV << "Arbiter weight set to " << arbiterWeight << endl;
}

void CPU::throttle(bool enable) {
    isThrottled = enable; // Assuming there's a mechanism to throttle CPU operations
    EV << "Throttling " << (enable ? "enabled" : "disabled") << endl;
}
