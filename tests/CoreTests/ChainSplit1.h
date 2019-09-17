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
class gen_simple_chain_split_1 : public test_chain_unit_base 
{
public: 
  gen_simple_chain_split_1();
  bool generate(std::vector<test_event_entry> &events) const; 
  bool check_split_not_switched(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_split_not_switched2(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_split_switched(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_split_not_switched_back(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_split_switched_back_1(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_split_switched_back_2(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_mempool_1(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_mempool_2(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  /*bool check_orphaned_chain_1(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_switched_to_alternative(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_chain_2(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_switched_to_main(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_chain_38(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_chain_39(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_chain_40(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool check_orphaned_chain_41(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); */
private:
};
