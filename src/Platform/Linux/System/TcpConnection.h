// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include "Dispatcher.h"

namespace System {

class Ipv4Address;

class TcpConnection {
public:
  TcpConnection();
  TcpConnection(const TcpConnection&) = delete;
  TcpConnection(TcpConnection&& other);
  ~TcpConnection();
  TcpConnection& operator=(const TcpConnection&) = delete;
  TcpConnection& operator=(TcpConnection&& other);
  std::size_t read(uint8_t* data, std::size_t size);
  std::size_t write(const uint8_t* data, std::size_t size);
  std::pair<Ipv4Address, uint16_t> getPeerAddressAndPort() const;

private:
  friend class TcpConnector;
  friend class TcpListener;
  
  Dispatcher* dispatcher;
  int connection;
  ContextPair contextPair;

  TcpConnection(Dispatcher& dispatcher, int socket);
};

}
