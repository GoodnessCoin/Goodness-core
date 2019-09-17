// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace Tests {

enum class NodeType {
  RPC,
  InProcess
};

struct TestNodeConfiguration {
  NodeType nodeType = NodeType::RPC;
  bool testnet = true;
  uint16_t p2pPort;
  uint16_t rpcPort;

  std::string dataDir;
  std::string blockchainLocation; // copy blockchain from this path
  std::string logFile;
  std::string daemonPath; // only for rpc node
  bool cleanupDataDir = true;

  std::vector<std::string> exclusiveNodes;

  std::string getP2pAddress() const {
    return "127.0.0.1:" + std::to_string(p2pPort);
  }
};

}
