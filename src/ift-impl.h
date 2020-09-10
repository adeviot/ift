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

//! @copydoc ift::explode(String, char, int)
String ift::explode(String data, String separator, int index)
{
    return explode(data, separator.charAt(0), index);
}

/*!
*  @section Tools -> Convert : IPV4 to String
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

/*!
*  @section Tools -> Convert : IPV4 to String
*  @brief  void ip2string(IPAddress address, String &ret)
*  @param  address IPAddress
*  @param  ret String variable to response
*  @return String format 0.0.0.0 to ret
*/
void ift::ip2string(IPAddress address, String &ret)
{
    ret = String(address[0]) + "." +
          String(address[1]) + "." +
          String(address[2]) + "." +
          String(address[3]);
}

/*!
*  @section Tools -> Convert : String to IPV4
*  @brief  void string2ip(IPAddress address)
*  @param  addr IPAddress type byte
*  @param  str String value
*  @return byte array to pointer addr
*/
void ift::string2ip(byte *addr, String str)
{
    if (str == "")
        return;

    IPAddress ip;
    bool i;
    i = ip.fromString(str);
    if (i)
    {
        for (int a = 0; a < 4; a++)
        {
            addr[a] = ip[a];
        }
    }
}

/*!
*  @section Tools -> Convert : String to IPV4
*  @brief  IPAddress string2ip(String str)
*  @param  str String value IP Address
*  @return IPAddress
*/
IPAddress ift::string2ip(String str)
{
    IPAddress ret(explode(str, '.', 0).toInt(), explode(str, '.', 1).toInt(), explode(str, '.', 2).toInt(), explode(str, '.', 3).toInt());
    return ret;
}

IPAddress ift::string2ip(const char *str)
{
    return string2ip(String(str));
}


/*!
*  @section Tools -> URL Decode
*  @brief  String urlDecode(String &str)
*  @param  str String value
*  @return String
*/
String urlDecode(String &str)
{
    char temp[] = "0x00";
    unsigned int len = text.length();
    unsigned int i = 0;
    String decoded = String();
    decoded.reserve(len); // Allocate the string internal buffer - never longer from source text
    while (i < len)
    {
        char decodedChar;
        char encodedChar = text.charAt(i++);
        if ((encodedChar == '%') && (i + 1 < len))
        {
            temp[2] = text.charAt(i++);
            temp[3] = text.charAt(i++);
            decodedChar = strtol(temp, NULL, 16);
        }
        else if (encodedChar == '+')
        {
            decodedChar = ' ';
        }
        else
        {
            decodedChar = encodedChar; // normal ascii char
        }
        decoded.concat(decodedChar);
    }
    return decoded;
}

/*!
*  @section Tools -> URL Encode
*  @brief  String urlEncode(String &str)
*  @param  str String value
*  @return String
*/
String urlEncode(String &str)
{
    String encodedString = "";
    char c;
    char code0;
    char code1;
    char code2;
    for (int i = 0; i < str.length(); i++)
    {
        c = str.charAt(i);
        if (c == ' ')
        {
            encodedString += '+';
        }
        else if (isalnum(c))
        {
            encodedString += c;
        }
        else
        {
            code1 = (c & 0xf) + '0';
            if ((c & 0xf) > 9)
            {
                code1 = (c & 0xf) - 10 + 'A';
            }
            c = (c >> 4) & 0xf;
            code0 = c + '0';
            if (c > 9)
            {
                code0 = c - 10 + 'A';
            }
            code2 = '\0';
            encodedString += '%';
            encodedString += code0;
            encodedString += code1;
            //encodedString+=code2;
        }
        yield();
    }
    return encodedString;
}

#endif // _IFT_TOOLS_IMPL_H_