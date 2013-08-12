/**
 * @author: Jeff Thompson
 * See COPYING for copyright and distribution information.
 */

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <time.h>
#if 0
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/date_time/posix_time/time_serialize.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#endif
#include <ndn-cpp/data.hpp>
#include <ndn-cpp/key-chain.hpp>

using namespace std;
using namespace ndn;
#if 0
using namespace boost::posix_time;
using namespace boost::gregorian;
#endif

unsigned char Data1[] = {
0x04, 0x82, // NDN Data
  0x02, 0xaa, // Signature
    0x03, 0xb2, // SignatureBits
      0x08, 0x85, 0x20, 0xea, 0xb5, 0xb0, 0x63, 0xda, 0x94, 0xe9, 0x68, 0x7a,
      0x8e, 0x65, 0x60, 0xe0, 0xc6, 0x43, 0x96, 0xd9, 0x69, 0xb4, 0x40, 0x72, 0x52, 0x00, 0x2c, 0x8e, 0x2a, 0xf5,
      0x47, 0x12, 0x59, 0x93, 0xda, 0xed, 0x82, 0xd0, 0xf8, 0xe6, 0x65, 0x09, 0x87, 0x84, 0x54, 0xc7, 0xce, 0x9a,
      0x93, 0x0d, 0x47, 0xf1, 0xf9, 0x3b, 0x98, 0x78, 0x2c, 0x22, 0x21, 0xd9, 0x2b, 0xda, 0x03, 0x30, 0x84, 0xf3,
      0xc5, 0x52, 0x64, 0x2b, 0x1d, 0xde, 0x50, 0xe0, 0xee, 0xca, 0xa2, 0x73, 0x7a, 0x93, 0x30, 0xa8, 0x47, 0x7f,
      0x6f, 0x41, 0xb0, 0xc8, 0x6e, 0x89, 0x1c, 0xcc, 0xf9, 0x01, 0x44, 0xc3, 0x08, 0xcf, 0x77, 0x47, 0xfc, 0xed,
      0x48, 0xf0, 0x4c, 0xe9, 0xc2, 0x3b, 0x7d, 0xef, 0x6e, 0xa4, 0x80, 0x40, 0x9e, 0x43, 0xb6, 0x77, 0x7a, 0x1d,
      0x51, 0xed, 0x98, 0x33, 0x93, 0xdd, 0x88, 0x01, 0x0e, 0xd3, 
    0x00, 
  0x00, 
  0xf2, 0xfa, 0x9d, 0x6e, 0x64, 0x6e, 0x00, 0xfa, 0x9d, 0x61, 0x62, 0x63, 0x00, 0x00,  // Name
  0x01, 0xa2, // SignedInfo
    0x03, 0xe2, // PublisherPublicKeyDigest
      0x02, 0x85, 0xb5, 0x50, 0x6b, 0x1a,
      0xba, 0x3d, 0xa7, 0x76, 0x1b, 0x0f, 0x8d, 0x61, 0xa4, 0xaa, 0x7e, 0x3b, 0x6d, 0x15, 0xb4, 0x26, 0xfe, 0xb5,
      0xbd, 0xa8, 0x23, 0x89, 0xac, 0xa7, 0x65, 0xa3, 0xb8, 0x1c, 
    0x00, 
    0x02, 0xba, // Timestamp
      0xb5, 0x05, 0x1d, 0xde, 0xe9, 0x5b, 0xdb, 
    0x00, 
    0x01, 0xe2, // KeyLocator
      0x01, 0xda, // Key
        0x0a, 0x95, 0x30, 0x81, 0x9f, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86,
        0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x81, 0x8d, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81,
        0x81, 0x00, 0xe1, 0x7d, 0x30, 0xa7, 0xd8, 0x28, 0xab, 0x1b, 0x84, 0x0b, 0x17, 0x54, 0x2d, 0xca, 0xf6, 0x20,
        0x7a, 0xfd, 0x22, 0x1e, 0x08, 0x6b, 0x2a, 0x60, 0xd1, 0x6c, 0xb7, 0xf5, 0x44, 0x48, 0xba, 0x9f, 0x3f, 0x08,
        0xbc, 0xd0, 0x99, 0xdb, 0x21, 0xdd, 0x16, 0x2a, 0x77, 0x9e, 0x61, 0xaa, 0x89, 0xee, 0xe5, 0x54, 0xd3, 0xa4,
        0x7d, 0xe2, 0x30, 0xbc, 0x7a, 0xc5, 0x90, 0xd5, 0x24, 0x06, 0x7c, 0x38, 0x98, 0xbb, 0xa6, 0xf5, 0xdc, 0x43,
        0x60, 0xb8, 0x45, 0xed, 0xa4, 0x8c, 0xbd, 0x9c, 0xf1, 0x26, 0xa7, 0x23, 0x44, 0x5f, 0x0e, 0x19, 0x52, 0xd7,
        0x32, 0x5a, 0x75, 0xfa, 0xf5, 0x56, 0x14, 0x4f, 0x9a, 0x98, 0xaf, 0x71, 0x86, 0xb0, 0x27, 0x86, 0x85, 0xb8,
        0xe2, 0xc0, 0x8b, 0xea, 0x87, 0x17, 0x1b, 0x4d, 0xee, 0x58, 0x5c, 0x18, 0x28, 0x29, 0x5b, 0x53, 0x95, 0xeb,
        0x4a, 0x17, 0x77, 0x9f, 0x02, 0x03, 0x01, 0x00, 0x01, 
      0x00, 
    0x00, 
  0x00, 
  0x01, 0x9a, // Content
    0xc5, 0x53, 0x55, 0x43, 0x43, 0x45, 0x53, 0x53, 0x21, 
  0x00, 
0x00,
1
};

#if 0
const ptime UNIX_EPOCH_TIME = ptime (date (1970, Jan, 1));
#endif

static void dumpData(const Data &data)
{
  cout << "name: " << data.getName().to_uri() << endl;
  if (data.getContent().size() > 0) {
    cout << "content (raw): ";
    for (unsigned int i = 0; i < data.getContent().size(); ++i)
      cout << data.getContent()[i];
    cout<< endl;
    cout << "content (hex): " << toHex(data.getContent()) << endl;
  }
  else
    cout << "content: <empty>" << endl;
    
  cout << "signature.digestAlgorithm: "
       << (data.getSignature().getDigestAlgorithm().size() > 0 ? toHex(data.getSignature().getDigestAlgorithm()).c_str() : "default (sha-256)") << endl;
  cout << "signature.witness: "
       << (data.getSignature().getWitness().size() > 0 ? toHex(data.getSignature().getWitness()).c_str() : "<none>") << endl;
  cout << "signature.signature: "
       << (data.getSignature().getSignature().size() > 0 ? toHex(data.getSignature().getSignature()).c_str() : "<none>") << endl;
  
  cout << "signedInfo.publisherPublicKeyDigest: "
       << (data.getSignedInfo().getPublisherPublicKeyDigest().getPublisherPublicKeyDigest().size() > 0 ? 
           toHex(data.getSignedInfo().getPublisherPublicKeyDigest().getPublisherPublicKeyDigest()).c_str() : "<none>") << endl;
  cout << "signedInfo.timestamp: ";
  if (data.getSignedInfo().getTimestampMilliseconds() >= 0) {
    cout << data.getSignedInfo().getTimestampMilliseconds() << " milliseconds" << endl;
    // TODO: dump timestamp real date.
#if 0
    ptime timestamp = UNIX_EPOCH_TIME + milliseconds(data.getSignedInfo().getTimestampMilliseconds());
    cout << "Data timestamp " << timestamp.date().year() << "/" << timestamp.date().month() << "/" << timestamp.date().day() 
         << " " << timestamp.time_of_day().hours() << ":" << timestamp.time_of_day().minutes() << ":" << timestamp.time_of_day().seconds()  << endl;
#endif
  }
  else
    cout << "<none>" << endl;
  cout << "signedInfo.freshnessSeconds: ";
  if (data.getSignedInfo().getFreshnessSeconds() >= 0)
    cout << data.getSignedInfo().getFreshnessSeconds() << endl;
  else
    cout << "<none>" << endl;
  cout << "signedInfo.finalBlockID: "
       << (data.getSignedInfo().getFinalBlockID().size() > 0 ? 
           toHex(data.getSignedInfo().getFinalBlockID()).c_str() : "<none>") << endl;
  cout << "signedInfo.keyLocator: ";
  if (data.getSignedInfo().getKeyLocator().getType() >= 0) {
    if (data.getSignedInfo().getKeyLocator().getType() == ndn_KeyLocatorType_KEY)
      cout << "Key: " << toHex(data.getSignedInfo().getKeyLocator().getKeyOrCertificate()) << endl;
    else if (data.getSignedInfo().getKeyLocator().getType() == ndn_KeyLocatorType_CERTIFICATE)
      cout << "Certificate: " << toHex(data.getSignedInfo().getKeyLocator().getKeyOrCertificate()) << endl;
    else if (data.getSignedInfo().getKeyLocator().getType() == ndn_KeyLocatorType_KEYNAME)
      // TODO: Implement keyName.
      cout << "keyName" << endl;
    else
      cout << "<unrecognized ndn_KeyLocatorType " << data.getSignedInfo().getKeyLocator().getType() << ">" << endl;
  }
  else
    cout << "<none>" << endl;
}

int main(int argc, char** argv)
{
  try {
    Data data;
    data.wireDecode(Data1, sizeof(Data1));
    cout << "Decoded Data:" << endl;
    dumpData(data);
    cout << "Decoded Data signature verification: " << (KeyChain::selfVerifyData(Data1, sizeof(Data1)) ? "VERIFIED" : "FAILED") << endl;
    
    ptr_lib::shared_ptr<vector<unsigned char> > encoding = data.wireEncode();
    
    Data reDecodedData;
    reDecodedData.wireDecode(*encoding);
    cout << endl << "Re-decoded Data:" << endl;
    dumpData(reDecodedData);
    cout << "Re-decoded Data signature verification: " << (KeyChain::selfVerifyData(&encoding->front(), encoding->size()) ? "VERIFIED" : "FAILED") << endl;
  
    Data freshData(Name("/ndn/abc"));
    const unsigned char freshContent[] = "SUCCESS!";
    freshData.setContent(freshContent, sizeof(freshContent) - 1);
    freshData.getSignedInfo().setTimestampMilliseconds(time(NULL) * 1000.0);
    
    KeyChain::defaultSign(freshData);
    cout << endl << "Freshly-signed Data:" << endl;
    dumpData(freshData);
    ptr_lib::shared_ptr<vector<unsigned char> > freshEncoding = freshData.wireEncode();
    cout << "Freshly-signed Data signature verification: " << (KeyChain::selfVerifyData(&freshEncoding->front(), freshEncoding->size()) ? "VERIFIED" : "FAILED") << endl;
  } catch (exception &e) {
    cout << "exception: " << e.what() << endl;
  }
  return 0;
}
