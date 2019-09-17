// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "IUpgradeManager.h"

#include <memory>

#include "IUpgradeDetector.h"

namespace CryptoNote {

//Simple upgrade manager version. It doesn't support voting for now.
class UpgradeManager: public IUpgradeManager {
public:
  UpgradeManager();
  virtual ~UpgradeManager() override;

  virtual void addMajorBlockVersion(uint8_t targetVersion, uint32_t upgradeHeight) override;

  virtual uint8_t getBlockMajorVersion(uint32_t blockIndex) const override;

private:
  std::vector<std::unique_ptr<IUpgradeDetector>> m_upgradeDetectors;
};

} //namespace CryptoNote
