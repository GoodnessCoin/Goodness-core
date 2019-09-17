// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "UpgradeDetector.h"
#include "IUpgradeDetector.h"

namespace CryptoNote {

class SimpleUpgradeDetector : public IUpgradeDetector {
public:
  SimpleUpgradeDetector(uint8_t targetVersion, uint32_t upgradeIndex) :
    m_targetVersion(targetVersion), m_upgradeIndex(upgradeIndex) {
  }
 
  uint8_t targetVersion() const override {
    return m_targetVersion;
  }
  
  uint32_t upgradeIndex() const override {
    return m_upgradeIndex;
  }

  ~SimpleUpgradeDetector() override {
  }

private:
  uint8_t m_targetVersion;
  uint32_t m_upgradeIndex;
};

std::unique_ptr<IUpgradeDetector> makeUpgradeDetector(uint8_t targetVersion, uint32_t upgradeIndex) {
  return std::unique_ptr<SimpleUpgradeDetector>(new SimpleUpgradeDetector(targetVersion, upgradeIndex));
}

}
