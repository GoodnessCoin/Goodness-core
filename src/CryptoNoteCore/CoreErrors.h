// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <string>
#include <system_error>

namespace CryptoNote {
namespace error {

enum class CoreErrorCode {
  NOT_INITIALIZED,
  CORRUPTED_BLOCKCHAIN
};

// custom category:
class CoreErrorCategory : public std::error_category {
public:
  static CoreErrorCategory INSTANCE;

  virtual const char* name() const throw() {
    return "CoreErrorCategory";
  }

  virtual std::error_condition default_error_condition(int ev) const throw() {
    return std::error_condition(ev, *this);
  }

  virtual std::string message(int ev) const {
    CoreErrorCode code = static_cast<CoreErrorCode>(ev);

    switch (code) {
      case CoreErrorCode::NOT_INITIALIZED: return "Core is not initialized";
      case CoreErrorCode::CORRUPTED_BLOCKCHAIN: return "Blockchain storage is corrupted";
      default: return "Unknown error";
    }
  }

private:
  CoreErrorCategory() {
  }
};

inline std::error_code make_error_code(CryptoNote::error::CoreErrorCode e) {
  return std::error_code(static_cast<int>(e), CryptoNote::error::CoreErrorCategory::INSTANCE);
}

}
}

namespace std {

template <>
struct is_error_code_enum<CryptoNote::error::CoreErrorCode>: public true_type {};

}
