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
class gen_chain_switch_1 : public test_chain_unit_base {
public:
  gen_chain_switch_1();

  bool generate(std::vector<test_event_entry>& events) const;

  bool check_split_not_switched(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);
  bool check_split_switched(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);

private:
  std::vector<CryptoNote::BlockTemplate> m_chain_1;

  CryptoNote::AccountBase m_recipient_account_1;
  CryptoNote::AccountBase m_recipient_account_2;
  CryptoNote::AccountBase m_recipient_account_3;
  CryptoNote::AccountBase m_recipient_account_4;

  std::vector<CryptoNote::Transaction> m_tx_pool;
};
