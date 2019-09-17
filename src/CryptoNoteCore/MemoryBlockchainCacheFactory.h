// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "IBlockchainCacheFactory.h"

#include "BlockchainCache.h"

namespace CryptoNote {

class MemoryBlockchainCacheFactory: public IBlockchainCacheFactory {
public:
  MemoryBlockchainCacheFactory(const std::string& filename, Logging::ILogger& logger);
  virtual ~MemoryBlockchainCacheFactory() override;

  std::unique_ptr<IBlockchainCache> createRootBlockchainCache(const Currency& currency) override;
  std::unique_ptr<IBlockchainCache> createBlockchainCache(const Currency& currency, IBlockchainCache* parent, uint32_t startIndex = 0) override;

private:
  std::string filename;
  Logging::ILogger& logger;
};

} //namespace CryptoNote
