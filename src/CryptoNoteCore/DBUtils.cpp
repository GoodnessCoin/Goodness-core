// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "DBUtils.h"

namespace {
  const std::string RAW_BLOCK_NAME = "raw_block";
  const std::string RAW_TXS_NAME = "raw_txs";
}

namespace CryptoNote {
namespace DB {
  std::string serialize(const RawBlock& value, const std::string& name) {
    std::stringstream ss;
    Common::StdOutputStream stream(ss);
    CryptoNote::BinaryOutputStreamSerializer serializer(stream);
    
    serializer(const_cast<RawBlock&>(value).block, RAW_BLOCK_NAME);
    serializer(const_cast<RawBlock&>(value).transactions, RAW_TXS_NAME);

    return ss.str();
  }

  void deserialize(const std::string& serialized, RawBlock& value, const std::string& name) {
    std::stringstream ss(serialized);
    Common::StdInputStream stream(ss);
    CryptoNote::BinaryInputStreamSerializer serializer(stream);
    serializer(value.block, RAW_BLOCK_NAME);
    serializer(value.transactions, RAW_TXS_NAME);
  }
}
}
