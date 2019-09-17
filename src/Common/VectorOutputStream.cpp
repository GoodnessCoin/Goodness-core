// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "VectorOutputStream.h"

namespace Common {

VectorOutputStream::VectorOutputStream(std::vector<uint8_t>& out) : out(out) {
}

size_t VectorOutputStream::writeSome(const void* data, size_t size) {
  out.insert(out.end(), static_cast<const uint8_t*>(data), static_cast<const uint8_t*>(data) + size);
  return size;
}

}
