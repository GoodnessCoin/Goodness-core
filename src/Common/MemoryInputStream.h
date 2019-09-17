// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "IInputStream.h"

namespace Common {

  class MemoryInputStream : public IInputStream {
  public:
    MemoryInputStream(const void* buffer, size_t bufferSize);
    size_t getPosition() const;
    bool endOfStream() const;
    
    // IInputStream
    virtual size_t readSome(void* data, size_t size) override;

  private:
    const char* buffer;
    size_t bufferSize;
    size_t position;
  };
}
