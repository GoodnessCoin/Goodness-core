// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <unordered_map>
#include <map>

#include <IDataBase.h>
#include "CryptoNoteCore/BlockchainReadBatch.h"
#include "CryptoNoteCore/BlockchainWriteBatch.h"

namespace CryptoNote {

class DataBaseMock : public IDataBase {
public:
  DataBaseMock() = default;
  ~DataBaseMock() override;

  std::error_code write(IWriteBatch& batch) override;
  std::error_code writeSync(IWriteBatch& batch) override;
  std::error_code read(IReadBatch& batch) override;
  std::unordered_map<uint32_t, RawBlock> blocks();

  std::map<std::string, std::string> baseState;
};
}
