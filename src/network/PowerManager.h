// PowerManager.h
#ifndef POWERMANAGER_H_
#define POWERMANAGER_H_

#include <omnetpp.h>

using namespace omnetpp;

class PowerManager : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

  private:
    double powerThreshold; // Power threshold for throttling
    bool isThrottling; // Current throttling status
};

#endif // POWERMANAGER_H_
