// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "BlockchainUtils.h"

namespace CryptoNote {
namespace Utils {

bool restoreCachedTransactions(const std::vector<BinaryArray>& binaryTransactions,
                               std::vector<CachedTransaction>& transactions) {
  transactions.reserve(binaryTransactions.size());

  for (auto binaryTransaction : binaryTransactions) {
    Transaction transaction;
    if (!fromBinaryArray(transaction, binaryTransaction)) {
      return false;
    }

    transactions.emplace_back(std::move(transaction));
  }

  return true;
}

}
}
