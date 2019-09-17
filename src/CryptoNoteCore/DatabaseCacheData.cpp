// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include <CryptoNoteCore/CryptoNoteSerialization.h>
#include <CryptoNoteCore/CryptoNoteTools.h>
#include <CryptoNoteCore/DatabaseCacheData.h>
#include <Serialization/SerializationOverloads.h>

namespace CryptoNote {

void ExtendedTransactionInfo::serialize(CryptoNote::ISerializer& s) {
  s(static_cast<CachedTransactionInfo&>(*this), "cached_transaction");
  s(amountToKeyIndexes, "key_indexes");
  s(amountToMultiIndexes, "multi_indexes");
}

void KeyOutputInfo::serialize(ISerializer& s) {
  s(publicKey, "public_key");
  s(transactionHash, "transaction_hash");
  s(unlockTime, "unlock_time");
  s(outputIndex, "output_index");
}

}
