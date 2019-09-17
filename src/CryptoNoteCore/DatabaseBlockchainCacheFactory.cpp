// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "DatabaseBlockchainCacheFactory.h"

#include "IDataBase.h"

#include "BlockchainCache.h"
#include "DatabaseBlockchainCache.h"

namespace CryptoNote {

DatabaseBlockchainCacheFactory::DatabaseBlockchainCacheFactory(IDataBase& database, Logging::ILogger& logger): database(database), logger(logger) {

}

DatabaseBlockchainCacheFactory::~DatabaseBlockchainCacheFactory() {

}

std::unique_ptr<IBlockchainCache> DatabaseBlockchainCacheFactory::createRootBlockchainCache(const Currency& currency) {
  return std::unique_ptr<IBlockchainCache> (new DatabaseBlockchainCache(currency, database, *this, logger));
}

std::unique_ptr<IBlockchainCache> DatabaseBlockchainCacheFactory::createBlockchainCache(const Currency& currency, IBlockchainCache* parent, uint32_t startIndex) {
  return std::unique_ptr<IBlockchainCache> (new BlockchainCache("", currency, logger, parent, startIndex));
}

} //namespace CryptoNote
