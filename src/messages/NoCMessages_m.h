//
// Generated file, do not edit! Created by opp_msgtool 6.0 from messages/NoCMessages.msg.
//

#ifndef __NOCMESSAGES_M_H
#define __NOCMESSAGES_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class NoCMessage;
/**
 * Class generated from <tt>messages/NoCMessages.msg:18</tt> by opp_msgtool.
 * <pre>
 * // NoCMessages.msg
 * message NoCMessage
 * {
 *     int srcX; // Source X coordinate
 *     int srcY; // Source Y coordinate
 *     int destX; // Destination X coordinate
 *     int destY; // Destination Y coordinate
 *     string payload; // Data payload
 *     int type; // 0 for read, 1 for write
 * }
 * </pre>
 */
class NoCMessage : public ::omnetpp::cMessage
{
  protected:
    int srcX = 0;
    int srcY = 0;
    int destX = 0;
    int destY = 0;
    omnetpp::opp_string payload;
    int type = 0;

  private:
    void copy(const NoCMessage& other);

  protected:
    bool operator==(const NoCMessage&) = delete;

  public:
    NoCMessage(const char *name=nullptr, short kind=0);
    NoCMessage(const NoCMessage& other);
    virtual ~NoCMessage();
    NoCMessage& operator=(const NoCMessage& other);
    virtual NoCMessage *dup() const override {return new NoCMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getSrcX() const;
    virtual void setSrcX(int srcX);

    virtual int getSrcY() const;
    virtual void setSrcY(int srcY);

    virtual int getDestX() const;
    virtual void setDestX(int destX);

    virtual int getDestY() const;
    virtual void setDestY(int destY);

    virtual const char * getPayload() const;
    virtual void setPayload(const char * payload);

    virtual int getType() const;
    virtual void setType(int type);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const NoCMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, NoCMessage& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline NoCMessage *fromAnyPtr(any_ptr ptr) { return check_and_cast<NoCMessage*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __NOCMESSAGES_M_H

