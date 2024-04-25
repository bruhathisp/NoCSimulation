The implementation for measuring average latency and bandwidth would likely be part of the `NetworkMonitor.cc` and `TrafficAnalyzer.cc` functionalities in the simulator. Here's an overview of how these files might handle the implementation:

1. `NetworkMonitor.cc`: This file would be responsible for periodically collecting network statistics, including packet send and receive times. It would record timestamps of events and possibly invoke methods in the `TrafficAnalyzer` to process the raw data.

2. `TrafficAnalyzer.cc`: This file would contain the logic to analyze traffic, including calculating the average latency. The `TrafficAnalyzer` would process each received `NoCMessage` (which represents a packet), extracting the necessary timestamps and sizes to compute the average latency and bandwidth.

The pseudocode would be implemented within methods in these classes, such as a `reportNetworkStatistics` method in `NetworkMonitor` and a `processTrafficData` or `analyzeTraffic` method in `TrafficAnalyzer`. These methods would be called either in response to events or periodically based on a simulation schedule.

Here is an abstracted example of how the implementation could be integrated into `TrafficAnalyzer.cc`:

```cpp
// TrafficAnalyzer.h
class TrafficAnalyzer {
    ...
    double totalLatency;
    int totalPackets;
    simtime_t totalTime;
    simtime_t lastEventTime;
    long totalDataSent;

    public:
        TrafficAnalyzer();
        virtual void processTrafficData(NoCMessage *msg);
        virtual void reportStatistics();
    ...
};

// TrafficAnalyzer.cc
void TrafficAnalyzer::processTrafficData(NoCMessage *msg) {
    // Extract timing and size information from the message
    simtime_t sendTime = msg->getSendTime();
    simtime_t receiveTime = simTime(); // Current simulation time is receive time
    long packetSize = msg->getByteLength();

    // Update latency
    totalLatency += receiveTime - sendTime;
    totalPackets++;

    // Update bandwidth if packet is sent
    if (lastEventTime != SIMTIME_ZERO) {
        totalTime += receiveTime - lastEventTime;
    }
    totalDataSent += packetSize;

    lastEventTime = receiveTime;
}

void TrafficAnalyzer::reportStatistics() {
    double averageLatency = (totalPackets > 0) ? (totalLatency.dbl() / totalPackets) : 0;
    double bandwidth = (totalTime > SIMTIME_ZERO) ? (totalDataSent / totalTime.dbl()) : 0;

    // Output the calculated statistics
    EV << "Average Latency: " << averageLatency << "s, Bandwidth: " << bandwidth << " bytes/s" << endl;
}
```

In a real-world implementation, you would need to handle corner cases and ensure synchronization between the data collection and reporting mechanisms. The above is simplified to illustrate the concept.
