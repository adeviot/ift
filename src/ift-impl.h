#ifndef _IFT_TOOLS_IMPL_H_
#define _IFT_TOOLS_IMPL_H_

#include <ift.h>

/*!
*  @brief  Tools : Explode String
*  @param  data message
*  @param  separator separator
*  @param  index index
*  @return String "" will always be returned
*/
String ift::explode(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = {0, -1};
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++)
    {
        if (data.charAt(i) == separator || i == maxIndex)
        {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i + 1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

//! @copydoc ift::explode()(String, char, int)
String ift::explode(String data, String separator, int index)
{
    return explode(data, separator.charAt(0), index);
}

/*!
*  @section Tools -> Convert : ip to String
*  @brief  ip2string(IPAddress address)
*  @param  address IPAddress
*  @return String
*/
String ift::ip2string(IPAddress address)
{
    return String(address[0]) + "." +
           String(address[1]) + "." +
           String(address[2]) + "." +
           String(address[3]);
}

void ift::ip2string(IPAddress address, String &ret)
{
    ret = String(address[0]) + "." +
          String(address[1]) + "." +
          String(address[2]) + "." +
          String(address[3]);
}

void ift::string2ip(byte *addr, String ipStr)
{
    if (ipStr == "")
        return;

    IPAddress ip;
    bool i;

    i = ip.fromString(ipStr);
    if (i)
    {
        for (int a = 0; a < 4; a++)
        {
            addr[a] = ip[a];
        }
    }
}

IPAddress str2IP(String str) {

    IPAddress ret( this.explode(str,'.',0).toInt(),getIpBlock(1,str),getIpBlock(2,str),getIpBlock(3,str) );
    return ret;
}
IPAddress str2IP(String str) {

    IPAddress ret( getIpBlock(0,str),getIpBlock(1,str),getIpBlock(2,str),getIpBlock(3,str) );
    return ret;

}


}

#endif // _IFT_TOOLS_IMPL_H_