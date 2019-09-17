// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <CryptoNoteCore/IMainChainStorage.h>
#include <CryptoNoteCore/Currency.h>

#include <vector>

namespace CryptoNote {

class VectorMainChainStorage: public IMainChainStorage {
public:
  virtual void pushBlock(const RawBlock& rawBlock) override;
  virtual void popBlock() override;
  virtual RawBlock getBlockByIndex(uint32_t index) const override;
  virtual uint32_t getBlockCount() const override;
  virtual void clear() override;

private:
  std::vector<RawBlock> storage;
};

std::unique_ptr<IMainChainStorage> createVectorMainChainStorage(const Currency& currency);

}
