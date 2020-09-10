#pragma once

#ifndef _IFT_TOOLS_H_
#define _IFT_TOOLS_H_

#include <Arduino.h>
#include <IPAddress.h>

class ift
{
private:
    /* data */
public:
    String explode(String data = "", char separator = ' ', int index = 0);
    String explode(String data = "", String separator = " ", int index = 0);

    /*convert*/
    String ip2string(IPAddress address);
    void ip2string(IPAddress address, String &ret);

    void string2ip(byte *addr, String ipStr);
    IPAddress string2ip(String str);
    IPAddress string2ip(const char *str);


    
};

#endif // _IFT_TOOLS_H_2