// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <CryptoNoteCore/BlockchainCache.h>
#include <map>

namespace CryptoNote {

struct KeyOutputInfo {
  Crypto::PublicKey publicKey;
  Crypto::Hash transactionHash;
  uint64_t unlockTime;
  uint16_t outputIndex;

  void serialize(CryptoNote::ISerializer& s);
};

// inherit here to avoid breaking IBlockchainCache interface
struct ExtendedTransactionInfo : CachedTransactionInfo {
  //CachedTransactionInfo tx;
  std::map<IBlockchainCache::Amount, std::vector<IBlockchainCache::GlobalOutputIndex>> amountToKeyIndexes; //global key output indexes spawned in this transaction
  std::map<IBlockchainCache::Amount, std::vector<IBlockchainCache::GlobalOutputIndex>> amountToMultiIndexes; //global multisignature output indexes spawned in this transaction
  void serialize(ISerializer& s);
};

}
