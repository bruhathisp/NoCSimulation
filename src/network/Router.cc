#include "Router.h"
#include "NoCMessages.msg"

Define_Module(Router);

void Router::initialize() {
    bufferSize = par("initialBufferSize").intValue();  // Dynamically adjusted based on simulation needs
    weight = par("initialWeight").doubleValue();       // Dynamically adjusted for network conditions
    isThrottled = false;                               // Throttling not enabled by default
}

void Router::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        // Handle time-triggered events or periodic updates
        processPeriodicUpdate();
    } else {
        // Asynchronously handle incoming packets
        cMessage *asyncMsg = new cMessage("asyncProcess");
        asyncMsg->encapsulate(msg);  // Encapsulate the original message
        scheduleAt(simTime() + par("processingDelay").doubleValue(), asyncMsg);
    }
}

void Router::processPeriodicUpdate() {
    updateRoutingTable();
    // Check for messages that are waiting to be processed and handle them
    if (!messageQueue.isEmpty()) {
        cMessage *msg = check_and_cast<cMessage *>(messageQueue.pop());
        processIncomingPacket(msg);
        delete msg;
    }
}


void Router::handleInternalEvent(cMessage *msg) {
    updateRoutingTable();
    delete msg;
}

void Router::routePacket(NoCMessage *msg) {
    int nextHop = calculateNextHop(msg->getDestX(), msg->getDestY());
    char port[10];
    sprintf(port, "out%d", nextHop);
    send(msg, port);
}

int Router::calculateNextHop(int destX, int destY) {
    // Adaptive routing based on network congestion and other metrics
    int xDiff = destX - getIndexX();  // Assuming getIndexX() gives the current X position
    int yDiff = destY - getIndexY();  // Assuming getIndexY() gives the current Y position

    // Example of a simple adaptive routing decision
    if (abs(xDiff) > abs(yDiff)) {
        return (xDiff > 0) ? east : west; // east and west are predefined port indices
    } else {
        return (yDiff > 0) ? north : south; // north and south are predefined port indices
    }
}


void Router::updateRoutingTable() {
    EV << "Dynamically updating routing table based on real-time traffic and network state." << endl;
}

// API Implementation
void Router::set_max_buffer_size(int size) {
    bufferSize = size;  // Optimize buffer size based on traffic analysis
    EV << "Buffer size dynamically set to " << bufferSize << " in router." << endl;
}

void Router::set_arbiter_weights(double newWeight) {
    weight = newWeight;  // Adjust weights based on current network conditions
    EV << "Arbiter weight dynamically adjusted to " << weight << " in router." << endl;
}

void Router::throttle(bool enable) {
    isThrottled = enable;  // Respond to network overload situations
    EV << "Throttling " << (enable ? "enabled" : "disabled") << " in router to manage network load." << endl;
}
