#if !defined(RESIP_BASECREATOR_HXX)
#define RESIP_BASECREATOR_HXX

#include "resiprocate/SipMessage.hxx"
#include "resiprocate/dum/Identity.hxx"

namespace resip
{

class DialogUsageManager;

class BaseCreator
{
   public:
      BaseCreator(DialogUsageManager& dum, Identity& identity);
      virtual ~BaseCreator();
      SipMessage& getLastRequest();
      Identity& getIdentity();
      const SipMessage& getLastRequest() const;
      
   protected:
      void makeInitialRequest(const NameAddr& target, MethodTypes method);
      
      // this will get updated when an initial request is challenged. where we
      // store the credentials and last cseq
      SipMessage mLastRequest;
      DialogUsageManager& mDum;
      Identity& mIdentity;
};

}

#endif
