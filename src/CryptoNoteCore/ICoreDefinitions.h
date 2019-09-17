// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <vector>
#include <CryptoNote.h>
#include <CryptoTypes.h>
#include <Serialization/ISerializer.h>

namespace CryptoNote {

struct BlockFullInfo : public RawBlock {
  Crypto::Hash block_id;
};

struct TransactionPrefixInfo {
  Crypto::Hash txHash;
  TransactionPrefix txPrefix;
};

struct BlockShortInfo {
  Crypto::Hash blockId;
  BinaryArray block;
  std::vector<TransactionPrefixInfo> txPrefixes;
};

void serialize(BlockFullInfo&, ISerializer&);
void serialize(TransactionPrefixInfo&, ISerializer&);
void serialize(BlockShortInfo&, ISerializer&);

}
