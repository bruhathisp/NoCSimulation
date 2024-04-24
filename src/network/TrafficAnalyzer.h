#ifndef TRAFFICANALYZER_H_
#define TRAFFICANALYZER_H_

#include <omnetpp.h>
#include "NoCMessages.msg"

using namespace omnetpp;

class TrafficAnalyzer : public cSimpleModule {
protected:
    // Initialization function
    virtual void initialize() override;

    // Handler for incoming messages
    virtual void handleMessage(cMessage *msg) override;

    // Method to analyze traffic data
    void analyzeTraffic();

public:
    // Function to extract and process traffic data
    void processTrafficData(NoCMessage *msg);
};

#endif // TRAFFICANALYZER_H_
