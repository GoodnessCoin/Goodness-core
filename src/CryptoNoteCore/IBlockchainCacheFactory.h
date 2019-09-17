// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <memory>

namespace CryptoNote {

class IBlockchainCache;
class Currency;

class IBlockchainCacheFactory {
public:
  virtual ~IBlockchainCacheFactory() {}

  virtual std::unique_ptr<IBlockchainCache> createRootBlockchainCache(const Currency& currency) = 0;
  virtual std::unique_ptr<IBlockchainCache> createBlockchainCache(const Currency& currency, IBlockchainCache* parent, uint32_t startIndex = 0) = 0;
};

} //namespace CryptoNote
