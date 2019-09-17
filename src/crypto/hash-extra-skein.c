// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include <stddef.h>
#include <stdint.h>

#include "hash-ops.h"
#include "skein.h"

void hash_extra_skein(const void *data, size_t length, char *hash) {
  int r = skein_hash(8 * HASH_SIZE, data, 8 * length, (uint8_t*)hash);
  if (r) {}
  assert(SKEIN_SUCCESS == r);
}
