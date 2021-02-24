#ifndef SERIALPROTOCOL_H
#define SERIALPROTOCOL_H

#include <QObject>

class SerialProtocol
{
public:
    SerialProtocol();

    typedef struct protocol{
      const unsigned char start = 0x02;
      unsigned char type[2];
      unsigned char size[2];
      unsigned char payload[4092];
      const unsigned char end = 0x03;
    }protocol;

    Protocol_init(protocol *prot);
};

#endif // SERIALPROTOCOL_H
