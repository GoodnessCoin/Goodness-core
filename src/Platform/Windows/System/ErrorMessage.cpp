// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "ErrorMessage.h"

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <cstddef>
#include <windows.h>

namespace System {

std::string lastErrorMessage() {
  return errorMessage(GetLastError());
}

std::string errorMessage(int error) {
  struct Buffer {
    ~Buffer() {
      if (pointer != nullptr) {
        LocalFree(pointer);
      }
    }

    LPTSTR pointer = nullptr;
  } buffer;

  auto size = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, nullptr, error,
                            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), reinterpret_cast<LPTSTR>(&buffer.pointer), 0, nullptr);
  return "result=" + std::to_string(error) + ", " + std::string(buffer.pointer, size);
}

}
