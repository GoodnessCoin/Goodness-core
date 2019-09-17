// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "ICryptoNoteProtocolQueryStub.h"

bool ICryptoNoteProtocolQueryStub::addObserver(CryptoNote::ICryptoNoteProtocolObserver* observer) {
  return false;
}

bool ICryptoNoteProtocolQueryStub::removeObserver(CryptoNote::ICryptoNoteProtocolObserver* observer) {
  return false;
}

uint32_t ICryptoNoteProtocolQueryStub::getObservedHeight() const {
  return observedHeight;
}

size_t ICryptoNoteProtocolQueryStub::getPeerCount() const {
  return peers;
}

bool ICryptoNoteProtocolQueryStub::isSynchronized() const {
  return synchronized;
}

void ICryptoNoteProtocolQueryStub::setPeerCount(uint32_t count) {
  peers = count;
}

void ICryptoNoteProtocolQueryStub::setObservedHeight(uint32_t height) {
  observedHeight = height;
}

void ICryptoNoteProtocolQueryStub::setSynchronizedStatus(bool status) {
    synchronized = status;
}
