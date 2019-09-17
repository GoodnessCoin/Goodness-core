// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include <set>
#include <unordered_set>
#include "CachedTransaction.h"
#include <CryptoNote.h>
#include <crypto/crypto.h>

namespace CryptoNote {

struct TransactionValidatorState {
  std::unordered_set<Crypto::KeyImage> spentKeyImages;
  std::set<std::pair<uint64_t, uint32_t>> spentMultisignatureGlobalIndexes;
};

void mergeStates(TransactionValidatorState& destionation, const TransactionValidatorState& source);
bool hasIntersections(const TransactionValidatorState& destionation, const TransactionValidatorState& source);
void excludeFromState(TransactionValidatorState& state, const CachedTransaction& transaction);

}
