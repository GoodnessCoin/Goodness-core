// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <exception>
#include <iomanip>
#include <iostream>

#include "IWalletLegacy.h"
#include "Wallet/WalletErrors.h"

namespace CryptoNote {

inline void throwIf(bool expr, CryptoNote::error::WalletErrorCodes ec)
{
  if (expr)
    throw std::system_error(make_error_code(ec));
}

inline std::ostream& operator <<(std::ostream& ostr, const Crypto::Hash& hash) {
  std::ios_base::fmtflags flags = ostr.setf(std::ios_base::hex, std::ios_base::basefield);
  char fill = ostr.fill('0');

  for (auto b : hash.data) {
    ostr << std::setw(2) << static_cast<unsigned int>(b);
  }

  ostr.fill(fill);
  ostr.setf(flags);
  return ostr;
}

} //namespace CryptoNote
