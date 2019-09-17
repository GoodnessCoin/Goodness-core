// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstdint>
#include <vector>
#include "IOutputStream.h"

namespace Common {

class VectorOutputStream : public IOutputStream {
public:
  VectorOutputStream(std::vector<uint8_t>& out);
  VectorOutputStream& operator=(const VectorOutputStream&) = delete;
  size_t writeSome(const void* data, size_t size) override;

private:
  std::vector<uint8_t>& out;
};

}
