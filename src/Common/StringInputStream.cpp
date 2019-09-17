// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "StringInputStream.h"
#include <string.h>

namespace Common {

StringInputStream::StringInputStream(const std::string& in) : in(in), offset(0) {
}

size_t StringInputStream::readSome(void* data, size_t size) {
  if (size > in.size() - offset) {
    size = in.size() - offset;
  }

  memcpy(data, in.data() + offset, size);
  offset += size;
  return size;
}

}
