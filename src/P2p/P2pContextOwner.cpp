// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "P2pContextOwner.h"
#include <cassert>
#include "P2pContext.h"

namespace CryptoNote {

P2pContextOwner::P2pContextOwner(P2pContext* ctx, ContextList& contextList) : contextList(contextList) {
  contextIterator = contextList.insert(contextList.end(), ContextList::value_type(ctx));
}

P2pContextOwner::P2pContextOwner(P2pContextOwner&& other) : contextList(other.contextList), contextIterator(other.contextIterator) {
  other.contextIterator = contextList.end();
}

P2pContextOwner::~P2pContextOwner() {
  if (contextIterator != contextList.end()) {
    contextList.erase(contextIterator);
  }
}

P2pContext& P2pContextOwner::get() {
  assert(contextIterator != contextList.end());
  return *contextIterator->get();
}

P2pContext* P2pContextOwner::operator -> () {
  return &get();
}

}
