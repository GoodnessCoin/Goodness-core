// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "CryptoNoteTools.h"
#include "CryptoNoteFormatUtils.h"

using namespace CryptoNote;

template<>
bool CryptoNote::toBinaryArray(const BinaryArray& object, BinaryArray& binaryArray) {
  try {
    Common::VectorOutputStream stream(binaryArray);
    BinaryOutputStreamSerializer serializer(stream);
    std::string oldBlob = Common::asString(object);
    serializer(oldBlob, "");
  } catch (std::exception&) {
    return false;
  }

  return true;
}

void CryptoNote::getBinaryArrayHash(const BinaryArray& binaryArray, Crypto::Hash& hash) {
  cn_fast_hash(binaryArray.data(), binaryArray.size(), hash);
}

Crypto::Hash CryptoNote::getBinaryArrayHash(const BinaryArray& binaryArray) {
  Crypto::Hash hash;
  getBinaryArrayHash(binaryArray, hash);
  return hash;
}

uint64_t CryptoNote::getInputAmount(const Transaction& transaction) {
  uint64_t amount = 0;
  for (auto& input : transaction.inputs) {
    if (input.type() == typeid(KeyInput)) {
      amount += boost::get<KeyInput>(input).amount;
    } else if (input.type() == typeid(MultisignatureInput)) {
      amount += boost::get<MultisignatureInput>(input).amount;
    }
  }

  return amount;
}

std::vector<uint64_t> CryptoNote::getInputsAmounts(const Transaction& transaction) {
  std::vector<uint64_t> inputsAmounts;
  inputsAmounts.reserve(transaction.inputs.size());

  for (auto& input: transaction.inputs) {
    if (input.type() == typeid(KeyInput)) {
      inputsAmounts.push_back(boost::get<KeyInput>(input).amount);
    } else if (input.type() == typeid(MultisignatureInput)) {
      inputsAmounts.push_back(boost::get<MultisignatureInput>(input).amount);
    }
  }

  return inputsAmounts;
}

uint64_t CryptoNote::getOutputAmount(const Transaction& transaction) {
  uint64_t amount = 0;
  for (auto& output : transaction.outputs) {
    amount += output.amount;
  }

  return amount;
}

void CryptoNote::decomposeAmount(uint64_t amount, uint64_t dustThreshold, std::vector<uint64_t>& decomposedAmounts) {
  decompose_amount_into_digits(amount, dustThreshold,
    [&](uint64_t amount) {
    decomposedAmounts.push_back(amount);
  },
    [&](uint64_t dust) {
    decomposedAmounts.push_back(dust);
  }
  );
}
