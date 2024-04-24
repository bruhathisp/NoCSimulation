//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 
// CPU.h
#ifndef CPU_H_
#define CPU_H_

#include <omnetpp.h>
#include "NoCMessages.msg"  // Assuming you have a message class defined here

using namespace omnetpp;

class CPU : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

  private:
    void generateTraffic();  // Method to generate traffic
    void processIncomingMessage(NoCMessage *msg);  // Method to process incoming messages
};

#endif // CPU_H_
