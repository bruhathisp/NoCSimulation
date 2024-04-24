#include "PowerManager.h"

Define_Module(PowerManager);

void PowerManager::initialize() {
    powerThreshold = par("powerThreshold").doubleValue();
    isThrottling = false;
    WATCH(isThrottling);
}

void PowerManager::handleMessage(cMessage *msg) {
    if (msg->isName("PowerUpdate")) {
        double currentPower = ((cDoubleValue *)msg->getObject())->doubleValue();
        evaluatePowerThreshold(currentPower);
        delete msg; // Clean up the message
    } else {
        // Forward other messages or handle different types of events
        forwardMessage(msg);
    }
}

void PowerManager::evaluatePowerThreshold(double currentPower) {
    int thresholdStatus = get_powerlimit_threshold(currentPower);
    if (thresholdStatus == 1 && !isThrottling) {
        isThrottling = true;
        throttleSystem();
        EV << "Throttling has been activated due to high power usage." << endl;
    } else if (thresholdStatus == 0 && isThrottling) {
        isThrottling = false;
        restoreSystem();
        EV << "Throttling has been deactivated as power usage is normalized." << endl;
    }
}

int PowerManager::get_powerlimit_threshold(double currentPower) {
    // Returns 1 if the system power exceeds the threshold and 0 if under the threshold
    return currentPower > powerThreshold ? 1 : 0;
}

void PowerManager::throttleSystem() {
    // Example of reducing the operational frequency or deactivating some cores
    broadcastCommand("ReducePower");
    EV << "System power reduction commands have been broadcasted." << endl;
}

void PowerManager::restoreSystem() {
    // Example of restoring normal operation
    broadcastCommand("RestorePower");
    EV << "System restoration commands have been broadcasted." << endl;
}

void PowerManager::forwardMessage(cMessage *msg) {
    // Example of forwarding a message to another module
    send(msg, "out");
}

void PowerManager::broadcastCommand(const char* command) {
    // Broadcast power management commands to other modules
    for (int i = 0; i gateSize("out"); ++i) {
        send(new cMessage(command), "out", i);
    }
}
