#ifndef NETWORKMONITOR_H_
#define NETWORKMONITOR_H_

#include <omnetpp.h>
#include "NoCMessages.msg"

using namespace omnetpp;

class NetworkMonitor : public cSimpleModule {
protected:
    // Initialization function
    virtual void initialize() override;

    // Handler for incoming messages
    virtual void handleMessage(cMessage *msg) override;

public:
    // Function to collect and report network statistics
    void reportNetworkStatistics();
};

#endif // NETWORKMONITOR_H_
