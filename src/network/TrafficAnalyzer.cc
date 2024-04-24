#include "TrafficAnalyzer.h"

Define_Module(TrafficAnalyzer);

void TrafficAnalyzer::initialize() {
    // Initialize anything that is needed before starting the analysis
}

void TrafficAnalyzer::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        analyzeTraffic();
    } else {
        processTrafficData(check_and_cast<NoCMessage *>(msg));
        delete msg; // Clean up the message once processed
    }
}

void TrafficAnalyzer::analyzeTraffic() {
    // Periodic traffic analysis tasks can be scheduled here
    // For example, summarizing collected data, calculating metrics, etc.
    EV << "Analyzing current traffic patterns at simulation time: " << simTime() << endl;
}

void TrafficAnalyzer::processTrafficData(NoCMessage *msg) {
    // Example processing function to handle traffic data
    EV << "Processing traffic data from message: " << msg->getName() << endl;

    // Here, you would extract data such as packet sizes, source/destination addresses,
    // types of traffic (read/write), etc., and use this data for further analysis.
    // This method could also call other methods to calculate latency, throughput, or other metrics.
}
