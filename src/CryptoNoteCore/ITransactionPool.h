// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include "CachedTransaction.h"

namespace CryptoNote {

struct TransactionValidatorState;

class ITransactionPool {
public:
    virtual ~ITransactionPool(){}
  virtual bool pushTransaction(CachedTransaction&& tx, TransactionValidatorState&& transactionState) = 0;
  virtual const CachedTransaction& getTransaction(const Crypto::Hash& hash) const = 0;
  virtual bool removeTransaction(const Crypto::Hash& hash) = 0;

  virtual size_t getTransactionCount() const = 0;
  virtual std::vector<Crypto::Hash> getTransactionHashes() const = 0;
  virtual bool checkIfTransactionPresent(const Crypto::Hash& hash) const = 0;

  virtual const TransactionValidatorState& getPoolTransactionValidationState() const = 0;
  virtual std::vector<CachedTransaction> getPoolTransactions() const = 0;

  virtual uint64_t getTransactionReceiveTime(const Crypto::Hash& hash) const = 0;
  virtual std::vector<Crypto::Hash> getTransactionHashesByPaymentId(const Crypto::Hash& paymentId) const = 0;
};

}
