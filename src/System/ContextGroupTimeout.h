// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once 
#include <chrono>
#include <System/ContextGroup.h>
#include <System/Timer.h>

namespace System {

class ContextGroupTimeout {
public: 
  ContextGroupTimeout(Dispatcher&, ContextGroup&, std::chrono::nanoseconds);

private: 
  Timer timeoutTimer;
  ContextGroup workingContextGroup;
};

}
