// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#ifndef HTTPPARSER_H_
#define HTTPPARSER_H_

#include <iostream>
#include <map>
#include <string>
#include "HttpRequest.h"
#include "HttpResponse.h"

namespace CryptoNote {

//Blocking HttpParser
class HttpParser {
public:
  HttpParser() {}
  virtual ~HttpParser() {}
  void receiveRequest(std::istream& stream, HttpRequest& request);
  void receiveResponse(std::istream& stream, HttpResponse& response);
  static HttpResponse::HTTP_STATUS parseResponseStatusFromString(const std::string& status);
private:
  void readWord(std::istream& stream, std::string& word);
  void readHeaders(std::istream& stream, HttpRequest::Headers &headers);
  bool readHeader(std::istream& stream, std::string& name, std::string& value);
  size_t getBodyLen(const HttpRequest::Headers& headers);
  void readBody(std::istream& stream, std::string& body, const size_t bodyLen);
};

} //namespace CryptoNote

#endif /* HTTPPARSER_H_ */
