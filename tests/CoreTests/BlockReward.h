// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include "Chaingen.h"

struct gen_block_reward : public test_chain_unit_base {
  gen_block_reward();

  bool generate(std::vector<test_event_entry>& events) const;

  bool check_block_verification_context(std::error_code bve, size_t event_idx, const CryptoNote::BlockTemplate& blk);
  bool check_block_verification_context(std::error_code bve, size_t event_idx, const CryptoNote::RawBlock& /*blk*/);

  bool mark_invalid_block(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);
  bool mark_checked_block(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);
  bool check_block_rewards(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);

private:
  //uint64_t ts_start = 1338224400;
  size_t m_invalid_block_index;
  std::vector<size_t> m_checked_blocks_indices;
};
