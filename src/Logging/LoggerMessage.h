// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <iostream>
#include "ILogger.h"

namespace Logging {

class LoggerMessage : public std::ostream, std::streambuf {
public:
  LoggerMessage(ILogger& logger, const std::string& category, Level level, const std::string& color);
  virtual ~LoggerMessage() override;
  LoggerMessage(const LoggerMessage&) = delete;
  LoggerMessage& operator=(const LoggerMessage&) = delete;
  LoggerMessage(LoggerMessage&& other);

private:
  int sync() override;
  std::streamsize xsputn(const char* s, std::streamsize n) override;
  int overflow(int c) override;

  std::string message;
  const std::string category;
  Level logLevel;
  ILogger& logger;
  boost::posix_time::ptime timestamp;
  bool gotText;
};

}
