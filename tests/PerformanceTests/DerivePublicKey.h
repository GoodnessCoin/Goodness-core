// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "crypto/crypto.h"
#include "CryptoNoteCore/CryptoNoteBasic.h"

#include "SingleTransactionTestBase.h"

class test_derive_public_key : public single_tx_test_base
{
public:
  static const size_t loop_count = 1000;

  bool init()
  {
    if (!single_tx_test_base::init())
      return false;

    Crypto::generate_key_derivation(m_tx_pub_key, m_bob.getAccountKeys().viewSecretKey, m_key_derivation);
    m_spend_public_key = m_bob.getAccountKeys().address.spendPublicKey;

    return true;
  }

  bool test()
  {
    CryptoNote::KeyPair in_ephemeral;
    Crypto::derive_public_key(m_key_derivation, 0, m_spend_public_key, in_ephemeral.publicKey);
    return true;
  }

private:
  Crypto::KeyDerivation m_key_derivation;
  Crypto::PublicKey m_spend_public_key;
};
