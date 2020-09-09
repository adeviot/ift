#ifndef _IFT_TOOLS_H_
#define _IFT_TOOLS_H_

#include "Arduino.h"

class ift
{
private:
    /* data */
public:
    String explode(String data = "", char separator = ' ', int index = 0);
    String explode(String data = "", String separator = " ", int index = 0);

    /*convert*/
    String ip2string(IPAddress address);
    String ip2string(IPAddress address, String &ret);
    
};

#endif // _IFT_TOOLS_H_