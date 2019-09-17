// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "LoggerRef.h"

namespace Logging {

LoggerRef::LoggerRef(ILogger& logger, const std::string& category) : logger(&logger), category(category) {
}

LoggerMessage LoggerRef::operator()(Level level, const std::string& color) const {
  return LoggerMessage(*logger, category, level, color);
}

ILogger& LoggerRef::getLogger() const {
  return *logger;
}

}
