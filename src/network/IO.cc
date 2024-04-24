#include "IO.h"
#include "NoCMessages.msg"

Define_Module(IO);

void IO::initialize() {
    cMessage *event = new cMessage("startIOOperation");
    double delay = uniform(0.1, 1.0); // More realistic operational delays
    scheduleAt(simTime() + delay, event);
    maxBufferSize = par("initialBufferSize").intValue(); // Default buffer size from parameters
    arbiterWeight = par("initialWeight").doubleValue(); // Default arbiter weight from parameters
    isThrottled = false; // Throttling not enabled by default
}

void IO::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        performIOOperation();
    } else {
        processIncomingData(check_and_cast<NoCMessage *>(msg));
    }
}

void IO::performIOOperation() {
    NoCMessage *nocMsg = new NoCMessage("ioTraffic");
    nocMsg->setSrcX(getIndex());
    nocMsg->setSrcY(0);
    nocMsg->setDestX(intuniform(0, par("networkSize").intValue()-1));
    nocMsg->setDestY(0);
    nocMsg->setType(intuniform(0, 1));

    double latency = calculateLatency(nocMsg->getType(), nocMsg->getDestX());
    nocMsg->setLatency(latency);

    EV << simTime() << " - Performing IO Operation " << (nocMsg->getType() == 0 ? "Read" : "Write")
       << " to " << nocMsg->getDestX() << " with latency " << latency << " cycles: "
       << nocMsg->getName() << endl;

    send(nocMsg, "out");
}

double IO::calculateLatency(int type, int dest) {
    // Placeholder formula for latency calculation
    return type == 0 ? 15 : 7; // Different latency for IO operations
}

void IO::processIncomingData(NoCMessage *msg) {
    EV << simTime() << " - Processing received data at IO" << endl;
    delete msg;
}

// API Implementation
void IO::set_max_buffer_size(int size) {
    maxBufferSize = size;
    EV << "Max buffer size for IO set to " << maxBufferSize << endl;
}

void IO::set_arbiter_weights(double weight) {
    arbiterWeight = weight;
    EV << "Arbiter weight for IO set to " << arbiterWeight << endl;
}

void IO::throttle(bool enable) {
    isThrottled = enable;
    EV << "Throttling for IO " << (enable ? "enabled" : "disabled") << endl;
}
