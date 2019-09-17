// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once 
#include "Chaingen.h"

/************************************************************************/
/*                                                                      */
/************************************************************************/
class gen_ring_signature_1 : public test_chain_unit_base
{
public:
  gen_ring_signature_1();

  bool generate(std::vector<test_event_entry>& events) const;

  bool check_balances_1(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);
  bool check_balances_2(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);

private:
  CryptoNote::AccountBase m_bob_account;
  CryptoNote::AccountBase m_alice_account;
};


/************************************************************************/
/*                                                                      */
/************************************************************************/
class gen_ring_signature_2 : public test_chain_unit_base
{
public:
  gen_ring_signature_2();

  bool generate(std::vector<test_event_entry>& events) const;

  bool check_balances_1(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);
  bool check_balances_2(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);

private:
  CryptoNote::AccountBase m_bob_account;
  CryptoNote::AccountBase m_alice_account;
};


/************************************************************************/
/*                                                                      */
/************************************************************************/
class gen_ring_signature_big : public test_chain_unit_base
{
public:
  gen_ring_signature_big();

  bool generate(std::vector<test_event_entry>& events) const;

  bool check_balances_1(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);
  bool check_balances_2(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);

private:
  size_t m_test_size;
  uint64_t m_tx_amount;

  CryptoNote::AccountBase m_bob_account;
  CryptoNote::AccountBase m_alice_account;
};
