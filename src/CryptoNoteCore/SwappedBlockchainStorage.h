// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <CryptoNoteCore/BlockchainStorage.h>
#include "CryptoNoteCore/SwappedVector.h"

namespace CryptoNote {

class SwappedBlockchainStorage : public BlockchainStorage::IBlockchainStorageInternal {
public:
  SwappedBlockchainStorage(const std::string& indexFileName, const std::string& dataFileName);
  virtual ~SwappedBlockchainStorage() override;

  virtual void pushBlock(RawBlock&& rawBlock) override;

  //Returns MemoryBlockchainStorage with elements from [splitIndex, blocks.size() - 1].
  //Original SwappedBlockchainStorage will contain elements from [0, splitIndex - 1].
  virtual std::unique_ptr<BlockchainStorage::IBlockchainStorageInternal> splitStorage(uint32_t splitIndex) override;

  virtual RawBlock getBlockByIndex(uint32_t index) const override;
  virtual uint32_t getBlockCount() const override;

private:
  mutable SwappedVector<RawBlock> blocks;
};

}
