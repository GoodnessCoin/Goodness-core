// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <boost/optional.hpp>
#include <CryptoNote.h>

namespace CryptoNote {

class CachedBlock {
public:
  explicit CachedBlock(const BlockTemplate& block);
  const BlockTemplate& getBlock() const;
  const Crypto::Hash& getTransactionTreeHash() const;
  const Crypto::Hash& getBlockHash() const;
  const Crypto::Hash& getBlockLongHash() const;
  const Crypto::Hash& getAuxiliaryBlockHeaderHash() const;
  const BinaryArray& getBlockHashingBinaryArray() const;
  const BinaryArray& getParentBlockBinaryArray(bool headerOnly) const;
  const BinaryArray& getParentBlockHashingBinaryArray(bool headerOnly) const;
  uint32_t getBlockIndex() const;

private:
  const BlockTemplate& block;
  mutable boost::optional<BinaryArray> blockHashingBinaryArray;
  mutable boost::optional<BinaryArray> parentBlockBinaryArray;
  mutable boost::optional<BinaryArray> parentBlockHashingBinaryArray;
  mutable boost::optional<BinaryArray> parentBlockBinaryArrayHeaderOnly;
  mutable boost::optional<BinaryArray> parentBlockHashingBinaryArrayHeaderOnly;
  mutable boost::optional<uint32_t> blockIndex;
  mutable boost::optional<Crypto::Hash> transactionTreeHash;
  mutable boost::optional<Crypto::Hash> blockHash;
  mutable boost::optional<Crypto::Hash> blockLongHash;
  mutable boost::optional<Crypto::Hash> auxiliaryBlockHeaderHash;
};

}
