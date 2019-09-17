// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <vector>
#include <string>
#include <utility>

namespace CryptoNote {

class IReadBatch {
public:
  virtual std::vector<std::string> getRawKeys() const = 0; 
  virtual void submitRawResult(const std::vector<std::string>& values, const std::vector<bool>& resultStates) = 0;
  virtual ~IReadBatch(){}
};

} //namespace CryptoNote
