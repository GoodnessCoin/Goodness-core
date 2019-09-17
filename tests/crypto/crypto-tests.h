// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#if defined(__cplusplus)
#include "crypto/crypto.h"

extern "C" {
#endif

void setup_random(void);

#if defined(__cplusplus)
}

bool check_scalar(const Crypto::EllipticCurveScalar &scalar);
void random_scalar(Crypto::EllipticCurveScalar &res);
void hash_to_scalar(const void *data, size_t length, Crypto::EllipticCurveScalar &res);
void hash_to_point(const Crypto::Hash &h, Crypto::EllipticCurvePoint &res);
void hash_to_ec(const Crypto::PublicKey &key, Crypto::EllipticCurvePoint &res);
#endif
