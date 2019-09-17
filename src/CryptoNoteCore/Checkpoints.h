// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include <map>
#include "CryptoNoteBasicImpl.h"
#include <Logging/LoggerRef.h>

namespace CryptoNote
{
  class Checkpoints
  {
  public:
    Checkpoints(Logging::ILogger& log);

    bool addCheckpoint(uint32_t index, const std::string& hash_str);
    bool isInCheckpointZone(uint32_t index) const;
    bool checkBlock(uint32_t index, const Crypto::Hash& h) const;
    bool checkBlock(uint32_t index, const Crypto::Hash& h, bool& isCheckpoint) const;
    bool isAlternativeBlockAllowed(uint32_t blockchainSize, uint32_t blockIndex) const;
    std::vector<uint32_t> getCheckpointHeights() const;

  private:
    std::map<uint32_t, Crypto::Hash> points;
    Logging::LoggerRef logger;
  };
}
