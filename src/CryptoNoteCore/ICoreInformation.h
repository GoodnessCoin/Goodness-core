// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include <cstdint>
#include <vector>
#include <stddef.h>
#include "CryptoNote.h"

namespace CryptoNote {

class ICoreInformation {
public:
  virtual ~ICoreInformation() {}
  virtual size_t getPoolTransactionCount() const = 0;
  virtual size_t getBlockchainTransactionCount() const = 0;
  virtual size_t getAlternativeBlockCount() const = 0;
  virtual uint64_t getTotalGeneratedAmount() const = 0;
  virtual std::vector<BlockTemplate> getAlternativeBlocks() const = 0;
  virtual std::vector<Transaction> getPoolTransactions() const = 0;
};

}
