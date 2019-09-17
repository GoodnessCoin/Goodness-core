// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstdint>

#include "CryptoNoteProtocol/ICryptoNoteProtocolObserver.h"
#include "CryptoNoteProtocol/ICryptoNoteProtocolQuery.h"
#include "CryptoNoteProtocol/CryptoNoteProtocolHandlerCommon.h"

class ICryptoNoteProtocolQueryStub : public CryptoNote::ICryptoNoteProtocolHandler {
public:
  ICryptoNoteProtocolQueryStub() : peers(0), observedHeight(0), synchronized(false) {
  }

  virtual bool addObserver(CryptoNote::ICryptoNoteProtocolObserver* observer) override;
  virtual bool removeObserver(CryptoNote::ICryptoNoteProtocolObserver* observer) override;
  virtual uint32_t getObservedHeight() const override;
  virtual size_t getPeerCount() const override;
  virtual bool isSynchronized() const override;

  void setPeerCount(uint32_t count);
  void setObservedHeight(uint32_t height);

  void setSynchronizedStatus(bool status);
  virtual void relayBlock(CryptoNote::NOTIFY_NEW_BLOCK_request& arg) override{};
  virtual void relayTransactions(const std::vector<CryptoNote::BinaryArray>& transactions) override{};


private:
  size_t peers;
  uint32_t observedHeight;

  bool synchronized;
};
