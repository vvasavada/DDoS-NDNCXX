/**
 * @author: Jeff Thompson
 * See COPYING for copyright and distribution information.
 */

#ifndef NDN_TCPTRANSPORT_HPP
#define NDN_TCPTRANSPORT_HPP

#include "../c/transport/tcp-transport.h"
#include "../c/encoding/binary-xml-element-reader.h"
#include "transport.hpp"

namespace ndn {
  
class TcpTransport : public Transport {
public:
  TcpTransport() 
  {
    ndn_TcpTransport_init(&transport_);
    face_ = 0;
    elementReader_.partialData.array = 0;
  }
  
  /**
   * Connect to the host specified in face.
   * @param face Not a shared_ptr because we assume that it will remain valid during the life of this Transport object.
   */
  virtual void connect(Face &face);
  
  /**
   * Set data to the host
   * @param data A pointer to the buffer of data to send.
   * @param dataLength The number of bytes in data.
   */
  virtual void send(const unsigned char *data, unsigned int dataLength);

  /**
   * Process any data to receive.  For each element received, call face.onReceivedElement.
   * This is non-blocking and will silently time out after a brief period if there is no data to receive.
   * You should repeatedly call this from an event loop.
   * @throw This may throw an exception for reading data or in the callback for processing the data.  If you
   * call this from an main event loop, you may want to catch and log/disregard all exceptions.
   */
  virtual void processEvents();

  /**
   * Close the connection to the host.
   */
  virtual void close();
  
  ~TcpTransport();
  
private:
  struct ndn_TcpTransport transport_;
  Face *face_;
  // TODO: This belongs in the socket listener.
  ndn_BinaryXmlElementReader elementReader_;
};

}

#endif