// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <CryptoNote.h>

namespace CryptoNote {

//TODO: rename this class since it's not persistent blockchain storage!
class BlockchainStorage {
public:

  class IBlockchainStorageInternal {
  public:
    virtual ~IBlockchainStorageInternal() { }

    virtual void pushBlock(RawBlock&& rawBlock) = 0;

    //Returns IBlockchainStorageInternal with elements from [splitIndex, blocks.size() - 1].
    //Original IBlockchainStorageInternal will contain elements from [0, splitIndex - 1].
    virtual std::unique_ptr<IBlockchainStorageInternal> splitStorage(uint32_t splitIndex) = 0;

    virtual RawBlock getBlockByIndex(uint32_t index) const = 0;
    virtual uint32_t getBlockCount() const = 0;
  };

  explicit BlockchainStorage(uint32_t reserveSize);
  explicit BlockchainStorage(const std::string& indexFileName, const std::string& dataFileName);
  virtual ~BlockchainStorage();

  virtual void pushBlock(RawBlock&& rawBlock);

  //Returns BlockchainStorage with elements from [splitIndex, blocks.size() - 1].
  //Original BlockchainStorage will contain elements from [0, splitIndex - 1].
  virtual std::unique_ptr<BlockchainStorage> splitStorage(uint32_t splitIndex);

  virtual RawBlock getBlockByIndex(uint32_t index) const;
  virtual uint32_t getBlockCount() const;

private:
  std::unique_ptr<IBlockchainStorageInternal> internalStorage;

  explicit BlockchainStorage(std::unique_ptr<IBlockchainStorageInternal> storage);
};

}
